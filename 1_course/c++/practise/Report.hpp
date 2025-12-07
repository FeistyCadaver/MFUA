#ifndef REPORT_HPP
#define REPORT_HPP

#include "FinancialDocument.hpp"
#include <vector>

class Report : public FinancialDocument 
{
private:
    std::vector<FinancialDocument*> documents;
    std::string title;

public:
    Report(int id, const std::string& title)
        : FinancialDocument(id), title(title) 
        {
        }
    ~Report() 
    {
        for (auto doc : documents) 
        {
            delete doc;
        }
    }
    
    void addDocument(FinancialDocument* doc) 
    { 
        documents.push_back(doc);
    }
    
    bool validate() const override 
    {
        for (const auto& doc : documents) 
        {
            if (!doc->validate()) return false;
        }
        return true;
    }
    
    std::string serializeToString() const override 
    {
        std::string result = "Report;" + std::to_string(id) + ";" + 
                             FinancialDocument::escapeString(title) + ";" +
                             std::to_string(documents.size());
        
        for (const auto& doc : documents) 
        {
            result += ";" + std::to_string(doc->getId());
        }
        return result;
    }
    
    void printFormatted(std::ostream& os) const override 
    {
        os << "=== Report ===\n"
           << "ID: " << id << "\n"
           << "Title: " << title << "\n"
           << "Contains " << documents.size() << " documents:\n";
        
        for (const auto& doc : documents) 
        {
            doc->printFormatted(os);
        }
    }
};

#endif // REPORT_HPP