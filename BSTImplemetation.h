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
double BST::getSmallestNodeHelper(Node_t *temp)
{
    if (temp != nullptr)
    {
        if (temp->left != nullptr)
        {
            getSmallestNodeHelper(temp->left);
        }
        else
        {
            return temp->value;
        }
    }
    else
    {
        std::cout << "l'arbre est vide ..." << std::endl;
    }
}

double BST::getSmallestNode()
{
    return getSmallestNodeHelper(root);
}

void BST::removeRootMatche()
{
    if (root != nullptr)
    {
        double rootValue = root->value;
        double smallestValue;
        Node *delptr = root;
        if (root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
            delete delptr;
        }
        if (root->left == nullptr && root->right != nullptr)
        {
            root = root->right;
            root->right = nullptr;
            delete delptr;
            std::cout << "le noeud " << rootValue << "est supprimer et remplacer par le de la valeur " << root->value << std::endl;
        }

        if (root->left != nullptr && root->right == nullptr)
        {
            root = root->left;
            root->left = nullptr;
            delete delptr;
            std::cout << "le noeud " << rootValue << "est supprimer et remplacer par le de la valeur " << root->value << std::endl;
        }

        if (root->left != nullptr && root->right != nullptr)
        {
            smallestValue = getSmallestNodeHelper(root);
            removeNodeHelper(root, smallestValue);
            root->value = smallestValue;
            std::cout << "le noeud " << rootValue << "est supprimer et remplacer par le de la valeur " << root->value << std::endl;
        }
    }
}
void BST::removeNodeHelper(Node_t *temp, double value)
{
    if (temp != nullptr)
    {
        if (temp->value == value)
        {
            removeRootMatche();
        }
        if (value <= temp->value && temp->left != nullptr)
        {
            temp->left->value == value ? removeMatche(temp, temp->left, true) : removeNodeHandler(temp->left, value);
        }
        else if (value > temp->value && temp->right != nullptr)
        {
            temp->right->value == value ? removeMatche(temp, temp->right, true) : removeNodeHandler(temp->right, value);
        }
        std::cout << "le node est introuvable" << std::endl;
    }
    else
    {
        std::cout << "l'arbre est vide ..." << std::endl;
    }
}