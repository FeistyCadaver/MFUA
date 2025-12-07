#include <iostream>
using std::cin, std::cout, std::endl;
//Решить задачу нахождения корня уравнения 
//вида kx + b = a, если известны параметры k, b и a 
int main()
{
    cout << "Нахождение x из уравнения kx + b = a" << endl;
    float k;
    cout << "Введите переменную k: " << endl;
    cin >> k;
    float b;
    cout << "Введите переменную b: " << endl;
    cin >> b;
    float a;
    cout << "Введите переменную a: " << endl;
    cin >> a;
    float x = (a - b) / k;
    cout << "x = " << x;
    return 0;
}