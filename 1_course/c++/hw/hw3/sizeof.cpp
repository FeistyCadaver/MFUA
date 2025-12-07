#include <iostream>
using std::cin, std::cout, std::endl;

int main()
{
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "bool: " << sizeof(bool) << " bytes" << endl;
    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "signed char: " << sizeof(signed char) << " bytes" << endl;
    cout << "unsigned char: " << sizeof(unsigned char) << " bytes" << endl;
    cout << "short int: " << sizeof(short int) << " bytes" << endl;
    cout << "long int: " << sizeof(long int) << " bytes" << endl;
    cout << "long long int: " << sizeof(long long int) << " bytes" << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
    cout << "unsigned short int: " << sizeof(unsigned short int) << " bytes" << endl;
    cout << "unsigned long int: " << sizeof(unsigned long int) << " bytes" << endl;
    cout << "unsigned long long int: " << sizeof(unsigned long long int) << " bytes" << endl;
    cout << "float: " << sizeof(float) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "long double: " << sizeof(long double) << " bytes" << endl;
    return 0;
}