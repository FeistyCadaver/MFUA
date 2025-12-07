#ifndef RECEIPT_HPP
#define RECEIPT_HPP

#include "FinancialDocument.hpp"

class Receipt : public FinancialDocument 
{  
private:
    double amount;
    std::string details;
    std::string date;
    std::string signature;

public:
    Receipt(int id, double amount, const std::string& details,
            const std::string& date, const std::string& signature)
        : FinancialDocument(id), amount(amount), details(details),
          date(date), signature(signature) 
          {
          }
    bool validate() const override 
    {
        return amount > 0 && !details.empty() && 
               !date.empty() && !signature.empty();
    }
    
    std::string serializeToString() const override 
    {
        return "Receipt;" + std::to_string(id) + ";" + 
               std::to_string(amount) + ";" + 
               FinancialDocument::escapeString(details) + ";" +
               FinancialDocument::escapeString(date) + ";" + 
               FinancialDocument::escapeString(signature);
    }
    
    void printFormatted(std::ostream& os) const override 
    {
        os << "=== Receipt ===\n"
           << "ID: " << id << "\n"
           << "Amount: " << amount << "\n"
           << "Details: " << details << "\n"
           << "Date: " << date << "\n"  
           << "Signature: " << signature << "\n";
    }
};

#endif // RECEIPT_HPP