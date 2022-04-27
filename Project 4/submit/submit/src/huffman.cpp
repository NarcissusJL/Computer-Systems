// huffman.cpp
// Two major classes have been provided in the file: HuffmanFrequencyTable and
// HuffmanTree. The former class records the occurrences of each input character
// and the latter class takes the responsibility of building a huffman tree.
//Zuoyu Wang and Huiyang Li

#include "node.h"
#include "pq.h"
#include <cmath>
#include <fstream>
#include <unordered_map>

using namespace std;

#define MAX_ENCODING_LENGTH 1024

class HuffmanFrequencyTable
{
    friend class HuffmanTree;

public:
    void build(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            add(s[i]);
        }
    }

    void put(char c, string code)
    {
        codeTable[c] = code;
    }

    string lookup(char c)
    {
        return codeTable[c];
    }

private:
    unordered_map<char, int> table;
    unordered_map<char, string> codeTable;

    void add(char c)
    {
        if (table.find(c) != table.end())
        {
            table[c]++;
        }
        else
        {
            table[c] = 1;
        }
    }
};

class HuffmanTree
{
public:
    HuffmanTreeNode *root;

    HuffmanTree(HuffmanFrequencyTable &table)
    {
        MinPriorityQueue<HuffmanTreeNode> queue;
        for (auto entry : table.table)
        {
            HuffmanTreeNode *node = new HuffmanTreeNode(entry.first, entry.second);
            queue.insert(node);
        }
        build(queue);
        traverse(table);
    }

    HuffmanTree(ifstream &input)
    {
        read(input);
    }

    void build(MinPriorityQueue<HuffmanTreeNode> &q)
    {
        while (q.length() > 1)
        {
            HuffmanTreeNode *left = q.extractMin();
            HuffmanTreeNode *right = q.extractMin();
            HuffmanTreeNode *root =
                new HuffmanTreeNode((char)0, left->frequency + right->frequency, left, right);
            q.insert(root);
        }
        // When there is only one node remaining in the PQ, assign it to the root of the tree
        root = q.extractMin();
    }

    void traverse(HuffmanFrequencyTable &table)
    {
        traverseWithCode(root, "", table);
    }

    void traverseWithCode(HuffmanTreeNode *root, string code, HuffmanFrequencyTable &table)
    {
        if (root == nullptr)
            return;
        if (root->isLeaf())
            table.put(root->c, code);
        else
        {
            string leftCode = code + "0";
            traverseWithCode(root->left, leftCode, table);
            string rightCode = code + "1";
            traverseWithCode(root->right, rightCode, table);
        }
    }

    void read(ifstream &input)
    {
        read(&root, input);
    }

    void write(ofstream &output)
    {
        write(root, output);
    }

    void read(HuffmanTreeNode **node, ifstream &input)
    {
        bool flag;
        input.read((char *)&flag, sizeof(bool));
        HuffmanTreeNode *tmp;
        if (flag)
        {
            char c;
            input.read((char *)&c, sizeof(char));
            tmp = new HuffmanTreeNode(c, 0);
            *node = tmp;
            return;
        }
        tmp = new HuffmanTreeNode(0, 0);
        read(&tmp->left, input);
        read(&tmp->right, input);
        *node = tmp;
    }

    void write(HuffmanTreeNode *node, ofstream &output)
    {
        bool flag = false;
        if (node->isLeaf())
        {
            flag = true;
            output.write((char *)&flag, sizeof(bool));
            char c = node->getChar();
            output.write((char *)&c, sizeof(char));
            return;
        }
        flag = false;
        output.write((char *)&flag, sizeof(bool));
        write(node->getLeft(), output);
        write(node->getRight(), output);
    }
};

unsigned char stringToBinary(const string &s)
{
    int val = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            val += pow(2, s.length() - 1 - i);
    }
    return val;
}

string binaryToString(unsigned char byte)
{
    int val = byte;
    string s;
    int remain;
    while (val / 2)
    {
        remain = val % 2;
        if (remain == 1)
            s.insert(0, "1");
        else
            s.insert(0, "0");
        val = val / 2;
    }
    remain = val % 2;
    s.insert(0, "1");
    int len = s.length();
    if (len < 8)
    {
        for (int i = 0; i < 8 - len; i++)
            s.insert(0, "0");
    }
    return s;
}

int compress(string text, HuffmanFrequencyTable &table, char *bytes)
{
    string s = "";
    for (int i = 0; i < text.length(); i++)
    {
        s.append(table.lookup(text[i]));
    }

    int nbytes = (s.length() + 7) / 8;
    int *plen = (int *)bytes;
    *plen = s.length();
    char *pointer = bytes + sizeof(int);
    string portion;
    for (int i = 0; i < nbytes - 1; i++)
    {
        portion = s.substr(i * 8, 8);
        *(pointer++) = stringToBinary(portion);
    }
    portion = s.substr(8 * (nbytes - 1));
    *pointer = stringToBinary(portion);
    return nbytes + 4;
}

int decodeChar(string encoding, int index, HuffmanTreeNode *root, string &sb)
{
    if (root == nullptr)
        return index;
    if (root->isLeaf())
    {
        sb += root->getChar();
        return index;
    }
    if (encoding[index] == '0')
    {
        return decodeChar(encoding, index + 1, root->getLeft(), sb);
    }
    else
    {
        return decodeChar(encoding, index + 1, root->getRight(), sb);
    }
}

string decompress(char *encoding, int nbits, HuffmanTree &tree)
{
    char *pointer = encoding;
    int nbytes = (nbits + 7) / 8;
    string s = "";
    for (int i = 0; i < nbytes - 1; i++)
    {
        s += binaryToString(*pointer++);
    }
    string portion = binaryToString(*pointer);
    int remain = nbits - 8 * (nbytes - 1);
    s += portion.substr(8 - remain);

    string text = "";
    int index = 0;
    while (index < s.length())
    {
        index = decodeChar(s, index, tree.root, text);
    }
    return text;
}

int main(int argc, char **argv)
{
    string opt(argv[1]);
    if (opt == "-c")
    {
        ifstream input(argv[2]);
        string text;
        getline(input, text);
        HuffmanFrequencyTable table;
        table.build(text);
        HuffmanTree tree(table);
        char encoding[MAX_ENCODING_LENGTH];
        int nbytes = compress(text, table, encoding);
        ofstream output(argv[3], ios::out | ios::trunc | ios::binary);
        tree.write(output);
        output.write(encoding, nbytes);
        output.close();
    }
    else
    {
        ifstream input(argv[2], ios::in | ios::binary);
        HuffmanTree tree(input);
        int nbits;
        input.read((char *)&nbits, sizeof(int));
        int nbytes = (nbits + 7) / 8;
        char bytes[nbytes];
        input.read(bytes, nbytes);
        string decodeText = decompress(bytes, nbits, tree);
        ofstream output(argv[3], ios::out | ios::trunc);
        output << decodeText;
        output.close();
    }

    return 0;
}
