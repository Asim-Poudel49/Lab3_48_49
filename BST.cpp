#include "BST.h"
#include <iostream>

using namespace std;

#include "BST.h"
#include <iostream>

using namespace std;

BST::BST(int size) {
    tree = new int[size];
    for (int i = 0; i < size; ++i)
        tree[i] = -1;
}

BST::~BST() {
    delete[] tree;
}
bool BST::isEmpty(){
    if(tree[0]== -1)
        return true;
        return false;


}

void BST::addBST(int key,int value){
    addBST(0, key,value);
}
void BST::addBST(int index,int key, int value){
    if (index >= size) {
        cout << "Tree is full, cannot insert more elements." << endl;
        return;
    }
    if (tree[index] == -1) {
        tree[index] = Data(key,value);
        return;
    }
    if(value<tree[index])
        addBST(2*index+1,value);
    else
        addBST(2*index+2,value);


}














