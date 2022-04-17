#include "BSTImplemetation.h"

int main(int argc, char const *argv[])
{
    BST bst;
    bst.addElement(2);
    bst.addElement(21);
    bst.addElement(4);
    bst.addElement(26);
    bst.addElement(5);
    bst.addElement(1);
    bst.display();
    Node *node = bst.getNode(0);
    std::cout << "\nle node a rechercher est : " << node->value << std::endl;
    return 0;
}
