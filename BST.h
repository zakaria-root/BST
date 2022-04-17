#ifndef __BST
#define __BST

typedef struct Node
{
    double value;
    struct Node *left;
    struct Node *right;
    Node(double value)
    {
        this->value = value;
        left = right = nullptr;
    }
} Node_t;

class BST
{
private:
    Node_t *root;
    void addHelper(Node *root, double value);
    void displayHelper(Node *temp);

public:
    BST();
    void addElement(double value);
    void display();
};
#endif
