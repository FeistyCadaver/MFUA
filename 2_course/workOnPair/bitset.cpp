#include <iostream>
#include <bitset>
using std::bitset, std::cout;

int main()
{
    bitset<24> s1 = 0x7ff00;
    bitset<24> s2 = 0xff0;
    s1[0] = 1;
    cout << s1 << "\n";
    cout << s2 << "\n";
    auto s3 = s1 & s2;
    cout << s3.to_ulong() << "\n";
    return 0;
}