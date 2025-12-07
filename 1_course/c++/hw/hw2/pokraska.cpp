#include <iostream>
using std::cin, std::cout, std::endl;

//Помещение стена 1 и 3: 3x2
//Помещение стена 2 и 4: 3.5x2
//Стоимость краски на 1 метр = 230 руб

int main()
{
    float odnaStena = 3;
    float vtorayaStena = 3.5;
    float price = 230;

    float room = odnaStena * 2 + vtorayaStena * 2;
    float finalPrice = room * price;

    cout << "Цена за покраску комнаты: " << finalPrice  << " руб"<< endl;
    return 0;
}