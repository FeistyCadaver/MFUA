#include <iostream>

int g_code, g_code2;

bool check(int a, int b)
{
    return a == b;
}

int main()
{
    int code;
    std::cout << "Input something: ";
    std::cin >> code;
    g_code = code;
    g_code2 = code + 1;
    if(!check(g_code, g_code2))
        abort();
    std::cout << "Urrrrraaaaaa!!!@!!!!!";
    return 0;
}