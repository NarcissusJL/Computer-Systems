// node.h
// This is the node class for the Huffman tree.
//Zuoyu Wang and Huiyang Li
#ifndef _NODE_H
#define _NODE_H

#include <iostream>
#include <sstream>

class HuffmanTree;

class HuffmanTreeNode
{
    friend class HuffmanTree;

public:
    HuffmanTreeNode(char c, int frequency) : HuffmanTreeNode(c, frequency, nullptr, nullptr)
    {
    }

    HuffmanTreeNode(char c, int frequency, HuffmanTreeNode *left, HuffmanTreeNode *right)
    {
        this->c = c;
        this->frequency = frequency;
        this->left = left;
        this->right = right;
    }

    bool operator<(const HuffmanTreeNode &obj)
    {
        return frequency < obj.frequency;
    }

    bool operator>(const HuffmanTreeNode &obj)
    {
        return frequency > obj.frequency;
    }

    bool operator<=(const HuffmanTreeNode &obj)
    {
        return frequency <= obj.frequency;
    }

    bool operator>=(const HuffmanTreeNode &obj)
    {
        return frequency >= obj.frequency;
    }

    std::ostream &operator<<(std::ostream &stream)
    {
        stream << toString();
        return stream;
    }

    bool isLeaf()
    {
        return left == nullptr && right == nullptr;
    }

    char getChar() { return c; }

    HuffmanTreeNode *getLeft() { return left; }

    HuffmanTreeNode *getRight() { return right; }

private:
    char c;
    int frequency;
    HuffmanTreeNode *left;
    HuffmanTreeNode *right;

    std::string toString() const
    {
        std::stringstream ss;
        ss << '<' << c << ':' << frequency << '>';
        return ss.str();
    }
};

#endif
