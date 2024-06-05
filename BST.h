#include<iostream>
#ifndef BST_H
#define BST_H




class BST{
    public:

        BST(){};
        virtual bool isEmpty()=0;
        virtual void addBST(int value)=0;
        virtual void removeBST(int key)=0;
        virtual bool searchBST(int Key)=0;

};



#endif
