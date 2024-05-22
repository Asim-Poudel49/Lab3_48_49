#ifndef BST_H
#define BST_H


struct Data {
    int key;
    int value;

    Data(int key,int value): key(key),value(value){}

};
class BST{
    protected:
        int size;
        Data *tree;
    public:

        BST(int size);
        virtual ~BST();
        virtual bool isEmpty()=0;
        virtual void addBST(int index,Data Data)=0;
        virtual void removeBST(int *keytoDelete)=0;
        virtual bool searchBST(int *targetKey)=0;
        //virtual void inorder=0();
        //virtual void preorder=0();
        //virtual void postorder=0();

};



#endif