//Решить задачу нахождения объема куба по его стороне.
#include <iostream>
#include <cmath>
using std::cin, std::cout, std::endl, std::pow;

int main()
{
    cout << "Нахождение объема куба по его стороне: " << endl;
    float a;
    cout << "Введите известную сторону куба: " << endl;
    cin >> a;

    float sq = pow(a, 3);
    cout << sq;
    return 0;
}