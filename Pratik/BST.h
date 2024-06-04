#ifndef BST_H
#define BST_H

struct Data
{
    int key;
    int value;

    Data(int key, int value) : key(key), value(value) {}
};
class BST
{
public:
    int size;
    Data *tree;

    BST(){};
    BST(int size);
};

#endif