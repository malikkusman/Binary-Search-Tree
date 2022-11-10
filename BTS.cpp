#include <iostream>
using namepace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class BST
{   
    private:
    Node *root;
    public:
        BST()
        {
            root = NULL;
        }
        bool isEmpty()
        {
            return root == NULL;
        }
        Node *getRoot()
        {
            return root;
        }
        Node *Insert(int x)
        {
            Node *temp = new Node(x);
            if(isEmpty())
            {
                root = temp;
            }
            else
            {
                Node *record = root;
                Node *parent = NULL;
                while(record != NULL)
                {
                    parent = record;
                    if(x < record->data)
                    {
                        record = record->left;
                    }
                    else
                    {
                        record = record->right;
                    }
                }
                if(x < parent->data)
                {
                    parent->left = temp;
                    temp->parent = parent;
                }
                else
                {
                    parent->right = temp;
                    temp->parent = parent;
                }
            }
            return temp;
        }

        // FIND 
        Node *find(int x)
        {
            Node *record = root;
            while(record != NULL)
            {
                if (x == record->data)
                {
                    return record;
                }
                else if (x < record->data)
                {
                    record = record.left;
                }
                else
                {
                    record = record->right;
                }
            }
            return NULL;
        }
};
int main()
{

}