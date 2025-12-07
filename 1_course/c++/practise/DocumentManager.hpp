#include "FinancialDocument.hpp"
#include "Invoice.hpp"
#include "Receipt.hpp"  
#include "Report.hpp"
#include <cstdio>
#include <cstring>
#include <string>

class DocumentManager 
{
private:
    FinancialDocument** documents;  
    int size;
    int capacity;

    void resize() 
    {
        capacity *= 2;
        FinancialDocument** newArray = new FinancialDocument*[capacity];
        for (int i = 0; i < size; ++i) 
        {
            newArray[i] = documents[i];
        }
        delete[] documents;
        documents = newArray;
    }
    
    void insertSorted(FinancialDocument* doc) 
    {
        int pos = size;
        while (pos > 0 && documents[pos-1]->getId() > doc->getId()) 
        {
            documents[pos] = documents[pos-1];
            --pos;
        }
        documents[pos] = doc;
        ++size;
    }
    
public:
    DocumentManager() : size(0), capacity(10) 
    {
        documents = new FinancialDocument*[capacity];
    }
    
    ~DocumentManager() 
    {
        for (int i = 0; i < size; ++i) 
        {
            delete documents[i];
        }
        delete[] documents;
    }
    
    void addDocument(FinancialDocument* doc)
    {
        if (size == capacity) resize();
        insertSorted(doc);
    }
    
    FinancialDocument* findById(int id) 
    {
        int left = 0;
        int right = size - 1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            int midId = documents[mid]->getId();
            if (midId == id) {
                return documents[mid];
            } else if (midId < id) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nullptr;
    }
    
    void saveToFile(const char* filename) 
    {
        FILE* file = fopen(filename, "w");
        if (!file) return;
        
        for (int i = 0; i < size; ++i) 
        {
            std::string data = documents[i]->serializeToString();
            fprintf(file, "%s\n", data.c_str());
        }
        fclose(file);
    }
    
    void loadFromFile(const char* filename) 
    {
        for (int i = 0; i < size; ++i) 
        {
            delete documents[i];
        }
        size = 0;
        
        FILE* file = fopen(filename, "r");
        if (!file) return;

        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file) 
        {
            buffer[strcspn(buffer, "\n")] = 0;
            char* token = strtok(buffer, ";");
            if (!token) continue;
            
            if (strcmp(token, "Invoice") == 0) 
            {
                token = strtok(nullptr, ";");
                int id = std::stoi(token);
                token = strtok(nullptr, ";");
                double amount = std::stod(token);
                token = strtok(nullptr, ";");
                std::string details = token ? FinancialDocument::unescapeString(token) : "";
                addDocument(new Invoice(id, amount, details));
            }
            else if (strcmp(token, "Receipt") == 0) 
            {  
                token = strtok(nullptr, ";");
                int id = std::stoi(token);
                token = strtok(nullptr, ";");
                double amount = std::stod(token);
                token = strtok(nullptr, ";");
                std::string details = token ? FinancialDocument::unescapeString(token) : "";
                token = strtok(nullptr, ";");
                std::string date = token ? FinancialDocument::unescapeString(token) : "";
                token = strtok(nullptr, ";");
                std::string signature = token ? FinancialDocument::unescapeString(token) : "";
                addDocument(new Receipt(id, amount, details, date, signature));
            }
            else if (strcmp(token, "Report") == 0) 
            {
                token = strtok(nullptr, ";");
                int id = std::stoi(token);
                token = strtok(nullptr, ";");
                std::string title = token ? FinancialDocument::unescapeString(token) : "";
                Report* rep = new Report(id, title);
                
                token = strtok(nullptr, ";");
                
                addDocument(rep);
            }
        }
        fclose(file);
    }
};
