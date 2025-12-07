#ifndef TREE_HPP
#define TREE_HPP

#include <vector>

// Предварительное объявление итератора
class AVLTreeIterator;
class AVLTreeContainer;

// Класс узла AVL-дерева
class AVLNode {
public:
    int val;
    AVLNode *left;
    AVLNode *right;
    AVLNode *parent;
    int height;
    
    AVLNode(int v);
};

// Класс AVL-дерева с автобалансировкой
class AVLTree {
private:
    AVLNode* root;
    
    // Вспомогательные методы
    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    void updateHeight(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* balance(AVLNode* node, int val);
    AVLNode* insert(AVLNode* node, AVLNode* parent, int val);
    void inOrder(AVLNode* node, std::vector<int>& result);
    AVLNode* minNode(AVLNode* node);
    AVLNode* deleteNode(AVLNode* node, int val);
    void clear(AVLNode* node);

public:
    // Конструктор и деструктор
    AVLTree();
    ~AVLTree();
    
    // Основные операции
    void insert(int val);
    void remove(int val);
    std::vector<int> inOrderTraversal();
    void printInOrder();
    
    // Методы для итераторов
    AVLNode* getRoot() const;
    
    // Дружественные классы для доступа к приватным данным
    friend class AVLTreeIterator;
    friend class AVLTreeContainer;
};

#endif 