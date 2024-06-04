#include "./BST_LinkedList.h"

void BST_LinkedList::addBST(int data)
{
    Node *newNode = new Node();
    newNode->setData(data);
    newNode->setLeft(nullptr);
    newNode->setRight(nullptr);
    newNode->setDepth(0);

    if (isEmpty())
    {
        root = newNode;
    }
    else
    {
        Node *current = root;
        Node *parent = nullptr;

        while (true)
        {
            parent = current;

            if (data < current->getData())
            {
                current = current->getLeft();
                if (current == nullptr)
                {
                    parent->setLeft(newNode);
                    break;
                }
            }
            else
            {
                current = current->getRight();
                if (current == nullptr)
                {
                    parent->setRight(newNode);
                    break;
                }
            }
        }
    }
}

void BST_LinkedList::removeBST(int key)
{
    if (isEmpty())
    {
        throw "Tree is empty";
    }
    Node *current = root;
    Node *parent = nullptr;
    bool isLeft = true;

    while (current->getData() != key)
    {
        parent = current;

        if (key < current->getData())
        {
            isLeft = true;
            current = current->getLeft();
        }
        else
        {
            isLeft = false;
            current = current->getRight();
        }

        if (current == nullptr)
        {
            return;
        }
    }

    if (current->getLeft() == nullptr && current->getRight() == nullptr)
    {
        if (current == root)
        {
            root = nullptr;
        }
        else if (isLeft)
        {
            parent->setLeft(nullptr);
        }
        else
        {
            parent->setRight(nullptr);
        }
    }
    else if (current->getRight() == nullptr)
    {
        if (current == root)
        {
            root = current->getLeft();
        }
        else if (isLeft)
        {
            parent->setLeft(current->getLeft());
        }
        else
        {
            parent->setRight(current->getLeft());
        }
    }
    else if (current->getLeft() == nullptr)
    {
        if (current == root)
        {
            root = current->getRight();
        }
        else if (isLeft)
        {
            parent->setLeft(current->getRight());
        }
        else
        {
            parent->setRight(current->getRight());
        }
    }
    else
    {
        Node *successor = getSuccessor(current);

        if (current == root)
        {
            root = successor;
        }
        else if (isLeft)
        {
            parent->setLeft(successor);
        }
        else
        {
            parent->setRight(successor);
        }

        successor->setLeft(current->getLeft());
    }

    heapify(root);
}

void BST_LinkedList::heapify(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    Node *largest = node;
    Node *left = node->getLeft();
    Node *right = node->getRight();

    if (left != nullptr && left->getData() > largest->getData())
    {
        largest = left;
    }

    if (right != nullptr && right->getData() > largest->getData())
    {
        largest = right;
    }

    if (largest != node)
    {
        int temp = largest->getData();
        largest->setData(node->getData());
        node->setData(temp);
        heapify(largest);
    }
}

Node *BST_LinkedList::getSuccessor(Node *node)
{
    Node *successorParent = node;
    Node *successor = node;
    Node *current = node->getRight();

    while (current != nullptr)
    {
        successorParent = successor;
        successor = current;
        current = current->getLeft();
    }

    if (successor != node->getRight())
    {
        successorParent->setLeft(successor->getRight());
        successor->setRight(node->getRight());
    }

    return successor;
}

int BST_LinkedList::searchBST(int key)
{
    Node *current = root;
    if (isEmpty())
    {
        throw "Tree is empty";
    }

    while (current->getData() != key)
    {

        if (key < current->getData())
        {
            current = current->getLeft();
        }
        else
        {
            current = current->getRight();
        }
        if (current == nullptr)
        {
            return -1;
        }
    }

    return current->getData();
}

bool BST_LinkedList::isEmpty()
{
    return root == nullptr;
}
