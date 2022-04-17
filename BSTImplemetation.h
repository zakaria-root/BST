#include <iostream>
#include "BST.h"

void BST::addHelper(Node *root, double value)
{

    if (root->value >= value)
    {
        if (root->left == nullptr)
        {
            root->left = new Node(value);
        }
        else
        {
            addHelper(root->left, value);
        }
    }
    else
    {
        if (root->right == nullptr)
        {
            root->right = new Node(value);
        }
        else
        {
            addHelper(root->right, value);
        }
    }
}

void BST::displayHelper(Node *temp)
{
    if (temp != nullptr)
    {
        displayHelper(temp->left);
        std::cout << temp->value << " -> " ;
        displayHelper(temp->right);
    }
}

BST::BST() : root(nullptr){};

void BST::addElement(double value)
{
    if (root == nullptr)
    {
        root = new Node(value);
    }
    else
    {

        addHelper(root, value);
    }
}
void BST::display()
{
    displayHelper(root);
}
