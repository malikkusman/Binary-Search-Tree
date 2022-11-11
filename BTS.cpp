#include <iostream>
using namespace std;

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
                    record = record->left;
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

        //Inorder Traversal
        void inordertraversal(Node *temp)
        {
            if(temp == NULL)
            {
                return;
            }
            inordertraversal(temp->left);
            cout << temp->data << " ";
            inordertraversal(temp->right);
        }

        // Preorder Traversal
        void preordertravesal(Node *T)
        {
            if (T != NULL)
            {
                cout << T->data << " ";
                preordertravesal(T->left);
                preordertravesal(T->right);
            }
        }

        // Postorder Traversal
        void postordertraversal(Node *T)
        {
            if (T != NULL)
            {
                postordertraversal(T->left);
                postordertraversal(T->right);
                cout << T->data << " ";
            }
        }

        //NUMBER OF NODES
        int NumberOfNodes(Node *T)
        {
            if (T == NULL)
            {
                return 0;
            }
            else 
            {
               return NumberOfNodes(T->left) + NumberOfNodes(T->right) + 1; 
            }
        }

        //HEIGHT OF TREE
        int Height(Node *T)
        {
            if (T == NULL)
            {
                return 0;
            }
            else

            {
                int left = Height(T->left);
                int right = Height(T->right);
                if (left > right)
                {
                    return left + 1;
                }
                else
                {
                    return right + 1;
                }
            }
        }

        // ISBST
        bool isBST(Node *T)
        {
            if (T == NULL)
            {
                return true;
            }
            else
            {
                if (T->left != NULL && T->left->data > T->data)
                {
                    return false;
                }
                if (T->right != NULL && T->right->data < T->data)
                {
                    return false;
                }
                if (!isBST(T->left) || !isBST(T->right))
                {
                    return false;
                }
                return true;
            }
        }

        // LEAF NOdes
        void LeafNodes(Node *T)
        {
            if (T == NULL)
            {
                return;
            }
            else
            {
                if (T->left == NULL && T->right == NULL)
                {
                    cout << T->data << " ";
                }
                LeafNodes(T->left);
                LeafNodes(T->right);
            }
        }

        //SPARSE TREE
        bool isSparseTree(Node *T) 
        {
            if (T == NULL)
            {
                return true;
            }
            else
            {
                if (T->left == NULL && T->right == NULL)
                {
                    return true;
                }
                if (T->left != NULL && T->right != NULL)
                {
                    return false;
                }
                return isSparseTree(T->left) && isSparseTree(T->right);
            }
        } 

        // VISUALIZE TREE
        void visualizeTree(Node *T)
        {
            if (T == NULL)
            {
                return;
            }
            else
            {
                if (T->left != NULL)
                {
                    cout << T->data << " -> " << T->left->data << endl;
                }
                if (T->right != NULL)
                {
                    cout << T->data << " -> " << T->right->data << endl;
                }
                visualizeTree(T->left);
                visualizeTree(T->right);
            }
        }

        // Print BST
        void printBST(Node *T)
        {
            if (T == NULL)
            {
                return;
            }
            else
            {
                cout << T->data << " ";
                printBST(T->left);
                printBST(T->right);
            }
        }    
};


int main()
{
    BST b;
    b.Insert(10);
    b.Insert(5);
    b.Insert(15);
    b.Insert(3);
    b.Insert(7);
    b.Insert(12);
    b.find(5);
    b.find(12); 
    b.find(3);
    b.deleteNode(10);
    b.inordertraversal(b.getRoot());
    cout << endl;   
    b.preordertravesal(b.getRoot());
    cout << endl;
    b.postordertraversal(b.getRoot());
    cout << endl;
    b.NumberOfNodes(b.getRoot());
    cout << endl;
    b.Height(b.getRoot());
    cout << endl;
    b.isBST(b.getRoot());
    cout << endl;
    b.LeafNodes(b.getRoot());
    cout << endl;
    b.isSparseTree(b.getRoot());
    cout << endl;
    b.visualizeTree(b.getRoot());
    cout << endl;
    b.printBST(b.getRoot());
    cout << endl;
    return 0;
}