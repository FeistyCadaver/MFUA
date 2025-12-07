#include <iostream>
using std::cin, std::cout, std::endl;

int main()
{
    int nok, a, b, c;
    cout << "Input first number: ";
    cin >> a;
    cout << "Input second number: ";
    cin >> b;

    while(a !=  b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }

    nok = (a * b) / a * (a, b);
    cout << nok;
}