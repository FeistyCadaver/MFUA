//Решить задачу нахождения третьего угла 
//треугольника, если известны два других угла

#include <iostream>
using std::cin, std::cout, std::endl;

int main()
{
    float a;
    cout << "Input first side of triangle: ";
    cin >> a;
    float b;
    cout << "Input second side of triangle: ";
    cin >> b;

    float c = 180 - a - b;
    cout << "Third side of triangle = " << c;
    return 0;
}