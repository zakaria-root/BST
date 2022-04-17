#include <iostream>
#include "BST.h"

void BST::addHelper(Node_t *root, double value)
{

    if (root->value >= value)
    {
        if (root->left == nullptr)
        {
            root->left = new Node_t(value);
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
            root->right = new Node_t(value);
        }
        else
        {
            addHelper(root->right, value);
        }
    }
}

void BST::displayHelper(Node_t *temp)
{
    if (temp != nullptr)
    {
        displayHelper(temp->left);
        std::cout << temp->value << " -> ";
        displayHelper(temp->right);
    }
}

BST::BST() : root(nullptr){};

void BST::addElement(double value)
{
    if (root == nullptr)
    {
        root = new Node_t(value);
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

Node_t *BST::getNodeHelper(Node_t *temp, double value)
{
    if (temp != nullptr)
    {
        if (temp->value == value)
            return temp;

        if (temp->value >= value)
        {
            getNodeHelper(temp->left, value);
        }
        else
        {
            getNodeHelper(temp->right, value);
        }
    }
    else
    {
        std::cout << "\n ce node est introuvable ..." << std::endl;
    }
}

Node_t *BST::getNode(double value)
{
    return getNodeHelper(root, value);
}