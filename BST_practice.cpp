#include<bits/stdc++.h>
using namespace std;

#define uli unsigned long int
struct bstNode
{
  int data;
  struct bstNode* left;;
  struct bstNode* right;
};

bstNode* newNode(int data)
{
  bstNode* newnode = new bstNode();
  newnode->data=data;
  newnode->left=NULL;
  newnode->right = NULL;
  return newnode;
}

int height(bstNode* root)
{
  if(root==NULL)
  return 0;
  else
  return max(height(root->left),height(root->right))+1;
}

void printGivenLevel(bstNode* root,int i)
{
  if(root==NULL)
  return;
  if(i==1)
  cout<<root->data<<"  ";
  else if(i>1)
  {
    printGivenLevel(root->left,i-1);
    printGivenLevel(root->right,i-1);
  }
}

void printLevelOrder(bstNode* root)
{
  int h=height(root);
  for(int i=1;i<=h;i++)
  {
    printGivenLevel(root,i);
  }
}

bstNode* insert(bstNode* root, int data)
{

  if(root==NULL)
  {
    root =newNode(data);
  }

  else if(data<=root->data)
  {
    root->left=insert(root->left,data);
  }
  else
  {
    root->right=insert(root->right,data);
  }

  return root;
}

bool Search(bstNode* root,int data)
{
  if(root==NULL)
  return false;
  else if(root->data==data)
  return true;
  else if(root->data>=data)
  {

  return Search(root->left,data);

  }
  else {return Search(root->right,data);}
}

bstNode* minValueNode(bstNode* root)
{
  bstNode* current = root;

  while(current->left!=NULL)
  {
    current=current->left;
  }

  return current;
}

bstNode* maxValueNode(bstNode* root)
{
  bstNode* current=root;
  while(current->right!=NULL)
  {
    current=current->right;
  }
  return current;
}

void inorderTraverse(bstNode* root)
{
  if (root!=NULL)
  {
    inorderTraverse(root->left);
    {
      cout<<root->data;
    }
    inorderTraverse(root->right);
  }
}

bstNode* deleteNode(bstNode* root,int data)
{
if(root==NULL)
  return root;

  if (data < root->data)
        root->left = deleteNode(root->left, data);
  else if (data > root->data)
        root->right = deleteNode(root->right, data);

  else
  {
    if (root->left == NULL)
        {
            bstNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bstNode* temp = root->left;
            free(root);
            return temp;
        }

       bstNode* temp = minValueNode(root->right);

      root->data = temp->data;

      root->right = deleteNode(root->right, temp->data);
  }
    return root;
}

bstNode* lca(bstNode* root,int v1,int v2)
{
  while(root!=NULL)
    {
    if(root->data>v1 && root->data >v2)
        root=root->left;

    else if(root->data<v1 && root->data<v2)
        root=root->right;
   else break;

    }
    return root;
}

bstNode* lcaMulti(bstNode* root,int v1,int v2,int v3)
{
  while(root!=NULL)
    {
    if(root->data>v1 && root->data >v2 && root->data >v3)
        root=root->left;

    else if(root->data<v1 && root->data<v2 && root->data <v3)
        root=root->right;
   else break;

    }
    return root;
}

bstNode* levelOrderInsert(int arr[],int n)
{
	bstNode* root = newNode(arr[0]);

	queue<pair<bstNode*,int>> q;
	q.push({root,0});
	while(!q.empty())
	{
		pair<bstNode*,int> p =q.front();
		if(2*p.second+1<n){
			p.first->left= newNode(arr[2*p.second+1]);
			q.push({p.first->left,2*p.second+1});
		}
		if (2*p.second + 2 < n) {
      p.first->right = newNode(arr[2*p.second + 2]);
      q.push({p.first->right, 2*p.second + 2});
    }

		q.pop();
	}

	return root;
}

void inOrder(bstNode* root,vector<bstNode*> &arr)
{

  if(root==NULL)
  return;
 inOrder(root->left,arr);

 arr.push_back(root);
 //cout<<root->data;
 inOrder(root->right,arr);

}

bstNode* inOrderSuc(bstNode* root,int value)
{

  vector<bstNode*> arr;

  bstNode* temp=NULL;
  inOrder(root,arr);

  if(arr[arr.size()-1]->data==value)
  return temp;
  bstNode* succ=NULL;
  for(int i=0;i<arr.size()-1;i++)
  {//cout<<arr[i]->data<<"    ";

  if(arr[i]->data==value && arr[i+1]!=NULL)
  {
    temp=arr[i+1];
  }


}
  return temp;
}

void printElementInRange(bstNode* root, int k1,int k2)
{

  if(root==NULL)
  return;

  if(k1<root->data)
  {
    printElementInRange(root->left,k1,k2);
  }
  if(root->data>=k1 && root->data<=k2)
  cout<<root->data<<"  ";

  if(k2>root->data)
  {
    printElementInRange(root->right,k1,k2);
  }

}


void noOfBSTinRangeUtil(bstNode* root, int k1,int k2,int &n)
{

  if(root==NULL)
  return;

  if(k1<root->data)
  {
    noOfBSTinRangeUtil(root->left,k1,k2,n);
  }
  if(root->data>=k1 && root->data<=k2)
  {
    if((minValueNode(root)->data)>=k1 && (maxValueNode(root)->data)<=k2)
    n+=1;
  }

  if(k2>root->data)
  {
    noOfBSTinRangeUtil(root->right,k1,k2,n);
  }

}

int noOfBSTinRange(bstNode* root, int k1, int k2)
{
  int n=0;

  noOfBSTinRangeUtil(root,k1,k2,n);

  return n;
}

uli binomialCoeff(uli n, uli k)
{
  uli result=1;

  if(k>n-k)
  k=n-k;
  for (int i = 0; i < k; ++i)
    {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

uli catalan(uli n)
{
  uli result=binomialCoeff(2*n,n);

  return result/(n+1);
}

/*
bstNode* storeGivenLevel(bstNode* root,int i,vector<bstNode*> &arr)
{
  if(root==NULL)
  return root;
  if(i==1)
  arr.push_back(root);
  else if(i>1)
  {
    storeGivenLevel(root->left,i-1,arr);
    storeGivenLevel(root->right,i-1,arr);
  }

  sort(arr.begin(),arr.end());

  bstNode* newRoot =NULL;
  for(int i=0;i<arr.size();i++)
  {
    root=insert(newRoot,arr[i]->data);
  }

  retrn newRoot;
}

bstNode* correctBST(bstNode* root)
{
  int h = height(root);
  vector<bstNode*> arr;
  for(int i=0;i<h;i++)
  {
    storetGivenLevel(root,i,arr);
  }
}*/

//create bst from preorder array
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


bstNode *constructTree (int pre[], int size)
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


void preOrder(bstNode* root,vector<int> &arr)
{
  if(root==NULL)
    return;
  preOrder(root->left,arr);
  arr.push_back(root->data);
  preOrder(root->right,arr);
}

   bool checkBST(bstNode* root) {

       vector<int> arr;
       preOrder(root,arr);
       int flag=0;
       for(int i=0;i<arr.size()-1;i++)
       {
           if(arr[i+1]<=arr[i])
           {
               flag=1;
               break;
           }
       }

       if(flag==0)
           return true;
       else return false;

   }

bool isSameBSTUtil(int a[], int b[], int n, int i1, int i2, int min, int max)
{
      int j, k;
      for (j=i1; j<n; j++)
       if (a[j]>min && a[j]<max)
           break;
      for (k=i2; k<n; k++)
       if (b[k]>min && b[k]<max)
           break;

      if (j==n && k==n)
          return true;
      if (((j==n)^(k==n)) || a[j]!=b[k])
          return false;

      return isSameBSTUtil(a, b, n, j+1, k+1, a[j], max) &&
          isSameBSTUtil(a, b, n, j+1, k+1, min, a[j]);
}

bool isSameBST(int a[], int b[], int n)
{
   return isSameBSTUtil(a, b, n, 0, 0, INT_MIN, INT_MAX);
}

int main()
{

  bstNode* root=NULL;

  int arr[10]={15,8,35,5,11,20,9,14,26,25};
  //root=levelOrderInsert(arr,10);

  for(int i=0;i<10;i++)
  {
    root=insert(root,arr[i]);
  }

  printLevelOrder(root);


  cout<<endl;
  if(Search(root,3))
  cout<<"found";
  else cout<<"not found";
  cout<<endl;
  cout<<endl;
  bstNode* lca1=lca(root,11,20);
  cout<<"LCA of 11 20    :"<<lca1->data<<endl;
  cout<<endl;
  bstNode* lca2=lcaMulti(root,9,11,14);
  cout<<"LCA of 9 11 14   :"<<lca2->data<<endl;
  cout<<endl;
  bstNode* inOSuc=inOrderSuc(root,8);
  cout<<"inorder succ of 15 : "<<inOSuc->data<<endl;
  cout<<endl;
  cout<<"No of Elements in Range 8 15   :";printElementInRange(root,8,15);
  cout<<endl<<endl;

  cout<<"No of BST in Range 8 15 :  "<<noOfBSTinRange(root,8,15);
  cout<<endl;cout<<endl;

  cout<<"No of BST possible from 3 nodes :"<<catalan(3);
  cout<<endl;cout<<endl;

  cout<<"No of BST possible from 5 nodes :"<<catalan(4);
  cout<<endl;cout<<endl;

  int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    bstNode* root2=constructTree(pre,size);
    printInorder(root2);

    if(checkBST(root2))
    cout<<endl<<"True";

    cout<<endl<<endl;

    int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
   int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
   int n1=9;
   if(isSameBST(a,b,n1))
   cout<<"Same BST";
  return 0;
}
