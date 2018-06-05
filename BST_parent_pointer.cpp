#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right, *parent;
};

Node *newNode(int item)
{
    Node *temp =  new Node();
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->parent = NULL;
    return temp;
}


void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->key;
        if (root->parent == NULL)
        cout<<"Parent NULL  ";
        else
          cout<<"Parent :"<<root->parent->key;
        inorder(root->right);
    }
}


Node* insert(struct Node* node, int key)
{

    if (node == NULL) return newNode(key);

    if (key < node->key)
    {
        Node *lchild = insert(node->left, key);
        node->left  = lchild;

        lchild->parent = node;
    }
    else if (key > node->key)
    {
        Node *rchild = insert(node->right, key);
        node->right  = rchild;

        rchild->parent = node;
    }

    return node;
}

int main()
{
    /*
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);


    inorder(root);

    return 0;
}
