#include <iostream>
#include <cmath>
using std::cin, std::cout, std::endl;

int main()
{
    int a, b, mod, c;
    cout << "Input first number: ";
    cin >> a;
    cout << "Input second number: ";
    cin >> b;
    cout << "Input module: ";
    cin >> mod;
    c = pow(a, b);
    cout << c;
}