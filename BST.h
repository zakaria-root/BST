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
    void addHelper(Node_t *, double);
    void displayHelper(Node_t *);
    Node_t *getNodeHelper(Node_t *, double);

public:
    BST();
    void addElement(double);
    Node_t *getNode(double);
    void display();
};
#endif
