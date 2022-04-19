#include <iostream>
#include "BST.h"

BST::BST() : root(nullptr){};

// ** --------------------------------------- INITIALISATION OF  THE BST  ----------------------------------

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

// ** --------------------------------------- ADD NODE TO THE BST  ----------------------------------

void BST::displayHelper(Node_t *temp)
{
    if (temp != nullptr)
    {
        displayHelper(temp->left);
        std::cout << temp->value << " -> ";
        displayHelper(temp->right);
    }
}

void BST::display()
{
    displayHelper(root);
    std::cout << std::endl;
}

// ** --------------------------------------- DISPLAY THE BST (INFIX) ----------------------------------

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
        return nullptr;
    }
}

Node_t *BST::getNode(double value)
{
    return getNodeHelper(root, value);
}

// ** --------------------------------------- GET THE NODE FROM THE BST ----------------------------------

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

// ** --------------------------------------- GET SMALLEST NODE FROM THE BST ----------------------------------

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
            std::cout << "le noeud " << rootValue << " est supprimer..." << std::endl;
        }
        else if (root->left == nullptr && root->right != nullptr)
        {
            root = root->right;
            delptr->right = nullptr;
            delete delptr;
            std::cout << "le noeud " << rootValue << " est supprimer et remplacer par le noedu le de la valeur " << root->value << std::endl;
        }
        else if (root->left != nullptr && root->right == nullptr)
        {
            root = root->left;
            delptr->left = nullptr;
            delete delptr;
            std::cout << "le noeud " << rootValue << " est supprimer et remplacer par le noedu le de la valeur " << root->value << std::endl;
        }
        else if (root->left != nullptr && root->right != nullptr)
        {
            smallestValue = getSmallestNodeHelper(root->right);
            removeNodeHelper(root, smallestValue);
            root->value = smallestValue;
            std::cout << "le noeud " << rootValue << " est supprimer et remplacer par le noedu le de la valeur " << root->value << std::endl;
        }
    }
}
void BST::removeMatche(Node_t *parent, Node_t *child, bool left)
{
    if (root != nullptr)
    {
        Node_t *delptr;
        double smallestValue;
        double childValue = child->value;
        if (child->left == nullptr && child->right == nullptr)
        {
            delete child;
            left == 1 ? parent->left = nullptr : parent->right = nullptr;
            std::cout << "le noeud " << childValue << " est supprimer ..." << std::endl;
            return;
        }
        else if (child->left != nullptr && child->right == nullptr)
        {
            left == 1 ? parent->left = child->left : parent->right = child->left;
            delptr = child;
            delptr->left = nullptr;
            delete delptr;
            std::cout << "le noeud " << childValue << " est supprimer et remplacer par le noeud de la valeur " << parent->left->value << std::endl;
        }
        else if (child->left == nullptr && child->right != nullptr)
        {
            left == 1 ? parent->left = child->right : parent->right = child->right;
            delptr = child;
            child->right = nullptr;
            delete delptr;
            std::cout << "le noeud " << childValue << " est supprimer et remplacer par le noeud de la valeur " << parent->right->value << std::endl;
        }
        else if (child->left != nullptr && child->right != nullptr)
        {
            smallestValue = getSmallestNodeHelper(child->right);
            removeNodeHelper(child, smallestValue);
            child->value = smallestValue;
            std::cout << "le noeud " << childValue << " est supprimer et remplacer par le noeud de la valeur " << child->value << std::endl;
        }
    }
    else
    {
        std::cout << "larbre est vide ..." << std::endl;
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
        else if (value <= temp->value && temp->left != nullptr)
        {
            temp->left->value == value ? removeMatche(temp, temp->left, true) : removeNodeHelper(temp->left, value);
        }
        else if (value > temp->value && temp->right != nullptr)
        {
            temp->right->value == value ? removeMatche(temp, temp->right, false) : removeNodeHelper(temp->right, value);
        }
    }
    else
    {
        std::cout << "l'arbre est vide ..." << std::endl;
    }
}

void BST::removeNode(double value)
{
    removeNodeHelper(root, value);
}

// ** --------------------------------------- REMOVE NODE FROM THE BST ----------------------------------
