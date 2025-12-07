//#ifndef CONSTRUCTOR_UTILS_HPP
//#define CONSTRUCTOR_UTILS_HPP .... нужны ли они нам?

//АЛЕКСЕЙ И КИРИЛЛ ЗАПИХАЙТЕ ПОТОМ ВСЕ ИНКЛЮДЫ В МЭИН ЧТБ НЕ ПРОПИСЫВАТЬ ИХ ПОСТОЯННО
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <unordered_map>

struct Node;
class Tree;

namespace constructorUtils //Прогстранство имен дааа, вроде рабочее
{
    //Формат файла: каждая строка содержит 3 значения: текущий узел, левый ребеночек, правй ребеночек
    //Пример из задания: 
    //5 2 7
    //2 1 3
    //7 -1 8 (на лекциях отстутсвие чайлда как минус 1 обозначали)
    std::unique_ptr<Node> createFromEdgeList(const std::string& filename);
    
    template<typename TreeType>
    void createFromValueSequence(const std::string& filename, TreeType& tree);
    
    bool parseEdgeLine(const std::string& line, int& value, int& left, int& right);

    std::unique_ptr<Node> buildTreeFromMap(std::unordered_map<int, std::unique_ptr<Node>>& nodes, int rootValue);
};

//Шаблонные функции
template<typename TreeType>
void constructorUtils::createFromValueSequence(const std::string& filename, TreeType& tree)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            std::istringstream iss(line);
            int value;
            if (iss >> value)
            {
                tree.insert(value);
            }
        }
    }
}

//#endif 