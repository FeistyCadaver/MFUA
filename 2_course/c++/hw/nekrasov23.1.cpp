#include <iostream>
#include <cstring>
using std::cin, std::cout, std::endl, std::string;

template <typename T>
struct ListNode 
{
    T val;
    ListNode* next;
    ListNode(T x) : val(x), next(nullptr)
    {}
};

template <typename T>
ListNode<T>* getIntersectionNode(ListNode<T>* headA, ListNode<T>* headB)
{
    if (!headA || !headB) return nullptr;

    ListNode<T>* pA = headA;
    ListNode<T>* pB = headB;

    while (pA != pB)
    {
        pA = pA ? pA -> next : headB;
        pB = pB ? pB -> next : headA;
    }
q
    return pA;
}

int main()
{
    auto* c1 = new ListNode<string>("c1");
    auto* c2 = new ListNode<string>("c2");
    auto* c3 = new ListNode<string>("c3");
    c1 -> next = c2;
    c2 -> next = c3;

    auto* a1 = new ListNode<string>("a1");

    auto* c2 = new ListNode<string>("a2");

    auto* a1 = new ListNode<string>("a1");
    auto* a2 = new ListNode<string>("a2");
    auto* a3 = new ListNode<string>("a3");
    a1 -> next = a2;
    a2 -> next = c1;

    auto* b1 = new ListNode<string>("b1");
    auto* b2 = new ListNode<string>("b2");
    auto* b3 = new ListNode<string>("b3");
    b1 -> next = b2;
    b2 -> next = b3;
    b3 -> next = c1;

    auto* intersection = getIntersectionNode(a1, b1);
    if (intersection)
        cout << "peresecheniye nachinayetsa s yzla: " << intersection -> val << endl;
    else
        cout << "peresecheniy net " << endl;
        return 0;
