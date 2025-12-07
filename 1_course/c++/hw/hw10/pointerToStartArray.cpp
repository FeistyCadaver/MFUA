#include <iostream>

int main()
{
    int arr[10];
    int *ptr = arr;
    int size = sizeof(arr);
    std::cout << arr << *ptr << std::endl;
    std::cout << size << std::endl;
    return 0;
}