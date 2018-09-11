//Ayesha Perwaiz
//main.cpp

#include <iostream>
#include "BSTree.h"
#include "Node.h"

int main()
{
    BSTree tree;

    //cout << "Adding 300" << endl;
    tree.addNode(300);
    cout << "Adding 100" << endl;
    tree.addNode(100);
    cout << "Adding 200" << endl;
    tree.addNode(200);
    cout << "Adding 400" << endl;
    tree.addNode(400);
    cout << endl;

    //prints Preorder
    cout << "Preorder Print:" << endl;
    tree.printPreorder(tree.Root());
    //prints Inorder
    cout << endl << "Inorder Print:" << endl;
    tree.printInorder(tree.Root());
    //prints PostOrder
    cout << endl << "Postorder Print:" << endl;
    tree.printPostorder(tree.Root());

    if(tree.findNode(500,tree.Root()) == nullptr)
        cout<<endl<<endl<<"Node 500 not found!"<<endl;
    if(tree.findNode(600,tree.Root()) == nullptr)
        cout<<"Node 600 not found!"<<endl;

    cout << endl << "Min = " << tree.min(tree.Root())->Key() << endl; //prints min
    cout << "Max = " << tree.max(tree.Root())->Key() << endl; //prints max

    cout << endl << "Successor to 300 = " << tree.successor(300,tree.Root())->Key() << endl;
    cout << "Predecessor to 300 = "<<tree.predecessor(300,tree.Root())->Key() << endl;

    cout << "Deleting 300" << endl;
    tree.deleteNode(300);
    //prints preorder after 300 has been deleted
    cout << endl << "Preorder Print:" << endl;
    tree.printPreorder(tree.Root());
}