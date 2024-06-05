#include <iostream>
#include"BST.h"


using namespace std;

#define MAX_SIZE 100

class BSTArray : public BST{
private:

    int arr[MAX_SIZE];
    int size;
    int getLeftChildIndex(int index) {
            return 2 * index + 1;
    }

    int getRightChildIndex(int index) {
            return 2 * index + 2;
    }

public:
    BSTArray() :size(0){
        for(int i = 0; i < MAX_SIZE; i++) {
            arr[i] = -1; // Using -1 to indicate empty nodes
        }
    }

    void addBST(int value) {
        if (size == MAX_SIZE) {
            cerr << "Error: BST is full!" << endl;
            return;
        }

        if (isEmpty()) {
            arr[0] = value;
        } else {
            int index = 0;
            while (index < MAX_SIZE) {
                if (value <= arr[index]) {
                    index = getLeftChildIndex(index); // Go to left child
                } else {
                    index = getRightChildIndex(index); // Go to right child
                }

                if (arr[index] == -1) {
                    arr[index] = value;
                    break;
                }
            }
        }

        size++;
    }

    bool searchBST(int value) {
        int index = 0;
        while (index < size) {
            if (arr[index] == value) {
                return true;
            } else if (value < arr[index]) {
                index = getLeftChildIndex(index);// Go to left child
            } else {
                index = getRightChildIndex(index); // Go to right child
            }
        }

        return false;
    }

    void removeBST(int key) {
        int index = 0;
        while (index < size) {
            if (arr[index] == key) {
                // Node found, remove it
                if (arr[getLeftChildIndex(index)] == -1 && arr[getRightChildIndex(index)] == -1) {
                    // Node has no children
                    arr[index] = -1;
                } else if (arr[getLeftChildIndex(index)] != -1 && arr[getRightChildIndex(index)] == -1) {
                    // Node has only left child
                    arr[index] = arr[getLeftChildIndex(index)];
                    arr[getLeftChildIndex(index)] = -1;
                } else if (arr[getLeftChildIndex(index)] == -1 && arr[getRightChildIndex(index)] != -1) {
                    // Node has only right child
                    arr[index] = arr[getRightChildIndex(index)];
                    arr[getRightChildIndex(index)] = -1;
                } else {
                    // Node has both left and right children
                    int successorIndex = getRightChildIndex(index);
                    while (arr[getLeftChildIndex(successorIndex)] != -1) {
                        successorIndex = getRightChildIndex(successorIndex);
                    }
                    arr[index] = arr[successorIndex];
                    arr[successorIndex] = -1;
                }

                size--;
                return;
            } 
            else if (key < arr[index]) {
                index = getLeftChildIndex(index); // Go to left child
            } 
            else {
                index = getRightChildIndex(index); // Go to right child
            }
        }

        cerr << "Error: Node not found!" << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    void inorderTraversal(int index) {
        if (index >= size || arr[index] == -1) {
            return;
        }

        inorderTraversal(getLeftChildIndex(index)); // Left child
        cout << arr[index] << " ";
        inorderTraversal(getRightChildIndex(index)); // Right child
    }

    void preorderTraversal(int index) {
        if (index >= size || arr[index] == -1) {
            return;
        }

        cout << arr[index] << " ";
        preorderTraversal(getLeftChildIndex(index)); // Left child
        preorderTraversal(getRightChildIndex(index)); // Right child
    }

    void postorderTraversal(int index) {
        if (index >= size || arr[index] == -1) {
            return;
        }

        postorderTraversal(getLeftChildIndex(index)); // Left child
        postorderTraversal(getRightChildIndex(index)); // Right child
        cout << arr[index] << " ";
    }

    void leftmostnode(int index){
        if (index >= size || arr[index] == -1) {
            return;
        }
        leftmostnode(getLeftChildIndex(index));
        cout << arr[index] << " ";
    }
    void printTree() {
        for (int i = 0; i < MAX_SIZE; i++) {
            if (arr[i] != -1) {
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    BSTArray BT;

    cout<<"Is BST empty?"<<(BT.isEmpty() ? "Yes" : "No")<<endl;
    
    BT.addBST(35);
    BT.addBST(37);
    BT.addBST(42);
    BT.addBST(23);
    BT.addBST(16);
    BT.addBST(30);
    BT.addBST(99);
    BT.addBST(69);
    BT.addBST(369);
    BT.addBST(32);
    BT.addBST(24);
    BT.addBST(19);
    BT.addBST(10);

    cout<<"Inorder traversal:";
    BT.inorderTraversal(0);
    cout<<endl;

    cout<<"Preorder traversal:";
    BT.preorderTraversal(0);
    cout<<endl;

    cout<<"Postorder traversal:";
    BT.postorderTraversal(0);
    cout<<endl;

    cout<<"Is BST empty?"<<(BT.isEmpty() ? "Yes" : "No")<<endl;

    cout<<"Search 40:"<<(BT.searchBST(40) ? "Found" : "Not found")<<endl;
    cout<<"Search 100:"<<(BT.searchBST(100) ? "Found" : "Not found")<<endl;

    BT.removeBST(30);
    BT.removeBST(24);
    BT.printTree();
    
    
    /*cout<<"Upadated Binary tree in Inorder traversal";
    BT.inorderTraversal(0);
    cout<<endl;*/

    return 0;
}