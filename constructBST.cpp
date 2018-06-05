#include<bits/stdc++.h>
using namespace std;


struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};

bstNode* newNode (int data)
{
    bstNode* temp = new bstNode();

    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

bstNode* constructTreeUtil( int pre[], int* preIndex, int key,
                                int min, int max, int size )
{

    if( *preIndex >= size )
        return NULL;

     bstNode* root = NULL;

    if( key > min && key < max )
    {

        root = newNode ( key );
        *preIndex = *preIndex + 1;

        if (*preIndex < size)
        {

            root->left = constructTreeUtil( pre, preIndex, pre[*preIndex],min, key, size );

            root->right = constructTreeUtil( pre, preIndex, pre[*preIndex],key, max, size );
        }
    }

    return root;
}


node *constructTree (int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil ( pre, &preIndex, pre[0], INT_MIN, INT_MAX, size );
}

void printInorder (bstNode* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

// Driver program to test above functions
int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    bstNode* root = constructTree(pre, size);

    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);

    return 0;
}
