#include<iostream>
#include "BST.h"

using namespace std;

class node { 
    public:
        int data; 
        node* left; 
        node* right; 

        node(int value){
            this->data=value;
            this->left=NULL;
            this->right=NULL;
        }

};

class BSTLinkedList: public BST{
    private:
        node* root;
    public:
        BSTLinkedList(){
            root=NULL;
        }
        bool isEmpty(){
            return root==NULL;
        }

        void addBST(int value) {
            if (isEmpty()) {
                cout <<"Node Added with data:" << value << endl;
                root = new node(value);
                return;
            }
            addBST(root, value);
            return;
        }

        node* addBST(node* temp, int value) {
            if (temp == NULL) {
                cout <<"Node Added with data:" << value << endl;
                return new node(value);
            }

            if (value < temp->data) {
                temp->left = addBST(temp->left, value);
            } else if (value > temp->data) {
                temp->right = addBST(temp->right, value);
            }
            return temp;
        }

        node* removeBST(node* temp, int value){
            if (temp == NULL) {
                cout << "Node with data:" << value << " not found." << endl;
                return NULL;
            }
            if (temp->data == value){
                // Node with 0 child
                if (temp->left == NULL && temp->right == NULL) {
                    delete temp;
                    return NULL;
                }
                // Node with 1 child 
                if (temp->left!=NULL && temp->right==NULL){
                    temp = temp->left;
                    delete temp->left;
                    return temp ;
                }
                if (temp->right!=NULL && temp->left==NULL){
                    temp = temp->right;
                    delete temp->right;
                    return temp;
                }
                // Node with 2 children
                if (temp->left!=NULL && temp->right!=NULL){
                    // Either find the maximum in the left subtree or minimum in the right subtree and replace by it and delete that node
                    node* minNode = temp->right;
                    while (minNode->left != NULL){
                        minNode = minNode->left;
                    }
                    temp->data = minNode->data;
                    temp->right=removeBST(temp->right, minNode->data);
                }
            } else if (value < temp->data) {
                temp->left = removeBST(temp->left, value);
            } else {
                temp->right = removeBST(temp->right, value);
            }
        }

        void removeBST(int value){
            if (isEmpty()){
                cerr<<"Binary Search Tree is Empty."<<std::endl;
                return;
            }
            cout << "Node Deleted with data:" << value << endl;
            removeBST(root, value);

        }



        bool searchBST(node* temp, int value){
            if (temp == NULL) {
                cout << "False (Not Found)" << endl;
                return false;
            }
            if (temp->data == value) {
                cout << "True (Found)" << endl;
                return true;
            }
            if (value < temp->data) {
                return searchBST(temp->left, value);
            } else {
                return searchBST(temp->right, value);
            }
        }

        bool searchBST(int value){
            cout<<""<<value<<" : ";
            searchBST(root, value);
        }

  void InOrderTraversal(){
        cout << "InOrder Traversal: ";
            InOrder(root);
        cout << endl;
        }


        void InOrder(node* node){
            if(node == NULL){
                return;
            }
            InOrder(node->left);
            cout << node->data << " ";
            InOrder(node->right);
        }

        void PreOrderTraversal(){
            cout << "PreOrder Traversal: ";
            PreOrder(root);
            cout << endl;
        }

        void PreOrder(node* node){
            if(node == NULL){
                return;
            }
            cout << node->data << " ";
            PreOrder(node->left);
            PreOrder(node->right);
        }

        void PostOrderTraversal(){
            cout << "PostOrder Traversal: ";
            PostOrder(root);
            cout << endl;
        }

        void PostOrder(node* node){
            if(node == NULL){
                return;
            }
            PostOrder(node->left);
            PostOrder(node->right);
            cout << node->data << " ";
        }
};


int main(){
    BSTLinkedList BT;
    BT.addBST(10);
    BT.addBST(20);
    BT.addBST(5);
    BT.addBST(15);
    BT.addBST(25);
    BT.addBST(2);
    BT.addBST(7);
    BT.addBST(12);
    BT.addBST(37);
    BT.addBST(6);
    BT.InOrderTraversal();
    BT.removeBST(5);
    BT.removeBST(10);
    BT.removeBST(20);
    BT.PreOrderTraversal();
    BT.searchBST(15);
    BT.searchBST(20);
    BT.addBST(69);
    BT.addBST(1);
    BT.PostOrderTraversal();
    BT.isEmpty();
    return 0;
}