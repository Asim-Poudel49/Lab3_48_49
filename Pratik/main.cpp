#include <iostream>
#include "./BST_LinkedList.cpp"
using namespace std;

int main()
{
    BST_LinkedList b;

    cout << "Checking if BST is empty: " << std::boolalpha << b.isEmpty() << endl;
    b.addBST(40);
    b.addBST(87);
    b.addBST(38);
    b.addBST(57);

    cout << "Checking if BST is empty: " << std::boolalpha << b.isEmpty() << endl;
    cout << "Searching for 40: " << b.searchBST(40) << endl;
    cout << "Searching for 87: " << b.searchBST(87) << endl;
    cout << "Searching for 8: " << b.searchBST(8) << endl;

    try
    {
        b.removeBST(87);
    }
    catch (const char *e)

    {
        std::cerr << e << '\n';
    }
    try
    {
        cout << "Searching for 87(after removing): " << b.searchBST(87) << endl;
        b.~BST_LinkedList();
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }

    try
    {

        cout << "Checking if BST is empty(after emptying): " << std::boolalpha << b.isEmpty() << endl;
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }
    cout << "Searching after clearing the tree: " << endl;
    try
    {
        b.searchBST(2);
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }
    cout << "Remove after clearing the tree: " << endl;
    try
    {
        b.removeBST(87);
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }
    cout << "BST Linked List terminated" << endl;
    return 0;
}
