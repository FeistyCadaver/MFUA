#ifndef FINANCIAL_DOCUMENT_HPP
#define FINANCIAL_DOCUMENT_HPP

#include <iostream>
#include <string>
#include <vector>

class FinancialDocument 
{
protected:
    int id;
    
public:
    FinancialDocument(int id) : id(id) 
    {
    }
    virtual ~FinancialDocument() = default;
    
    // Запрет копирования
    FinancialDocument(const FinancialDocument&) = delete;
    FinancialDocument& operator=(const FinancialDocument&) = delete;
    
    int getId() const { return id; }

    virtual bool validate() const = 0;
    virtual std::string serializeToString() const = 0;
    virtual void printFormatted(std::ostream& os) const = 0;
    

    static std::string escapeString(const std::string& input) 
    {
        std::string output;
        for (char c : input) 
        {
            if (c == ';') output += "\\;";
            else if (c == '\\') output += "\\\\";
            else output += c;
        }
        return output;
    }
    
    static std::string unescapeString(const std::string& input) 
    {
        std::string output;
        for (size_t i = 0; i < input.size(); ++i) {
            if (input[i] == '\\' && i + 1 < input.size()) 
            {
                if (input[i+1] == ';') output += ';';
                else if (input[i+1] == '\\') output += '\\';
                ++i;
            }
            else 
            {
                output += input[i];
            }
        }
        return output;
    }
};

#endif // FINANCIAL_DOCUMENT_HPP