#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "tree.hpp"
#include <vector>
#include <algorithm>
#include <stack>

// Итератор для in-order обхода AVL-дерева
class AVLTreeIterator {
private:
    // Указатель на текущий узел
    AVLNode* current;
    
    // Стек для хранения узлов при обходе
    std::stack<AVLNode*> nodeStack;
    
    // Вспомогательная функция для инициализации стека
    void pushLeft(AVLNode* node);

public:
    // Конструкторы
    AVLTreeIterator();
    AVLTreeIterator(AVLNode* root);
    
    // Операции итератора
    int operator*() const;           // Разыменование
    AVLTreeIterator& operator++();   // Префиксный инкремент
    AVLTreeIterator operator++(int); // Постфиксный инкремент
    bool operator==(const AVLTreeIterator& other) const;
    bool operator!=(const AVLTreeIterator& other) const;
    
    // Типы для совместимости с STL
    typedef std::forward_iterator_tag iterator_category;
    typedef int value_type;
    typedef int difference_type;
    typedef int* pointer;
    typedef int& reference;
};

// Класс контейнера для использования в range-based for
class AVLTreeContainer {
private:
    AVLTree& tree;
    
public:
    AVLTreeContainer(AVLTree& t);
    AVLTreeIterator begin();
    AVLTreeIterator end();
};

#endif 