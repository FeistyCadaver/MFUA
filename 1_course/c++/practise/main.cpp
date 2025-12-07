#include "FinancialDocument.hpp"
#include "Invoice.hpp"
#include "Receipt.hpp" 
#include "Report.hpp"
#include "DocumentManager.hpp"

int main() 
{
    Invoice inv(1, 1500.75, "Software development payment");
    Receipt rec(2, 1500.75, "Software development payment", "2023-10-01", "Efimov A.N.");  
    Report rep(3, "Q1 Financial Report");
    
    rep.addDocument(new Invoice(4, 500.0, "Additional services"));  
    
    rep.addDocument(new Receipt(5, 500.0, "Additional services", "2023-10-02", "Morgenshtern A.T."));  
    
    DocumentManager manager;
    manager.addDocument(new Invoice(6, 2000.0, "Web development"));  
    manager.addDocument(new Receipt(7, 2000.0, "Web development", "2023-10-03", "Kirillov I.T."));  
    
    manager.addDocument(new Report(rep));

    FinancialDocument* doc = manager.findById(6);
    if (doc) doc->printFormatted(std::cout);

    manager.saveToFile("documents.txt");
    DocumentManager manager2;
    manager2.loadFromFile("documents.txt");

    return 0;
}