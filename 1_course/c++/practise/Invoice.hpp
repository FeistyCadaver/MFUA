#ifndef INVOICE_HPP
#define INVOICE_HPP

#include "FinancialDocument.hpp"

class Invoice : public FinancialDocument 
{
protected:  
    double amount;
    std::string details;

public:
    Invoice(int id, double amount, const std::string& details)
        : FinancialDocument(id), amount(amount), details(details) 
        {
        }
    bool validate() const override 
    {
        return amount > 0 && !details.empty();
    }
    
    std::string serializeToString() const override 
    {
        return "Invoice;" + std::to_string(id) + ";" + 
               std::to_string(amount) + ";" + 
               FinancialDocument::escapeString(details);
    }
    
    void printFormatted(std::ostream& os) const override 
    {
        os << "=== Invoice ===\n"
           << "ID: " << id << "\n"
           << "Amount: " << amount << "\n"
           << "Details: " << details << "\n";
    }
};

#endif // INVOICE_HPP