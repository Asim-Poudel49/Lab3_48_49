#include "./BST.h"

class Node
{
    int data;
    int depth;
    Node *right;
    Node *left;

public:
    void setData(int data)
    {
        this->data = data;
    }
    void setDepth(int depth)
    {
        this->depth = depth;
    }
    void setRight(Node *right)
    {
        this->right = right;
    }
    void setLeft(Node *left)
    {
        this->left = left;
    }

    Node *getRight()
    {
        return right;
    }
    Node *getLeft()
    {
        return left;
    }

    int getData()
    {
        return data;
    }
    int getDepth()
    {
        return depth;
    }
};

class BST_LinkedList : public BST
{

    Node *root;
    void heapify(Node *node);
    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;

        deleteTree(node->getLeft());
        deleteTree(node->getRight());
        delete node;
    }
    Node *getSuccessor(Node *node);

public:
    BST_LinkedList()
    {
        root = nullptr;
    }
    ~BST_LinkedList()
    {
        deleteTree(root);
        root = nullptr;
    }

    bool isEmpty();
    void addBST(int data);
    void removeBST(int key);
    int searchBST(int key);
};
