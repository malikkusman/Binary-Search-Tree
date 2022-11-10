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

        // EMPTY NODE
        bool isEmpty()
        {
            return root == NULL;
        }

        // GET ROOT
        Node *getRoot()
        {
            return root;
        }

        // INSERT NODE
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

        // FIND NODE
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

        Node *deleteNode(int x)
        {
            Node *temp = find(x);
            if(temp == NULL)
            {
                return NULL;
            }
            else
            {
                if(temp->left == NULL && temp->right == NULL)
                {
                    if(temp->parent->left == temp)
                    {
                        temp->parent->left = NULL;
                    }
                    else
                    {
                        temp->parent->right = NULL;
                    }
                    delete temp;
                }
                else if(temp->left == NULL || temp->right == NULL)
                {
                    if(temp->left == NULL)
                    {
                        if(temp->parent->left == temp)
                        {
                            temp->parent->left = temp->right;
                        }
                        else
                        {
                            temp->parent->right = temp->right;
                        }
                        temp->right->parent = temp->parent;
                        delete temp;
                    }
                    else
                    {
                        if(temp->parent->left == temp)
                        {
                            temp->parent->left = temp->left;
                        }
                        else
                        {
                            temp->parent->right = temp->left;
                        }
                        temp->left->parent = temp->parent;
                        delete temp;
                    }
                }
                else
                {
                    Node *record = temp->right;
                    while(record->left != NULL)
                    {
                        record = record->left;
                    }
                    temp->data = record->data;
                    if(record->parent->left == record)
                    {
                        record->parent->left = record->right;
                    }
                    else
                    {
                        record->parent->right = record->right;
                    }
                    if(record->right != NULL)
                    {
                        record->right->parent = record->parent;
                    }
                    delete record;
                }
            }
            return temp;
        }
};
int main()
{

}