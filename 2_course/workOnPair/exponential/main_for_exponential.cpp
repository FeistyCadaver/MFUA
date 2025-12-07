#include "exponential.hpp"
using std::cout, std::cin, std::endl;

int main()
{
    double value;
    cout << "Enter a real number ";
    cin >> value;
    
    double result = exponential(value);
    cout << " e^" << value << " = " << result << endl;

    return 0;
}