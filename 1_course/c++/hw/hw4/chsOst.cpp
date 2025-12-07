#include <iostream>
using std::cin, std::cout, std::endl;

int main()
{
    int a, b;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    float c, d;
    c = a / b;
    cout << "Chastnoe: " << c << endl;
    d = (a % b);
    cout << "Ostatok ot deleniya: " << d << endl;
    return 0;
}