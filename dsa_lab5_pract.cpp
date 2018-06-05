#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* getNewNode(int data)
{
	Node* newNode=new Node();
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

int height(Node* root)
{
	if (root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

int noNodes(Node* root)
{
  int nn=0;
  queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		int n=q.size();
		while(n!=0)
		{
		Node* currentNode=q.front();
    nn++;


		if(currentNode->left!=NULL)
		q.push(currentNode->left);
		if(currentNode->right!=NULL)
		q.push(currentNode->right);
		q.pop();
		n--;
	  }
		cout<<endl;
	}
  return nn;

}

void preOrder(Node* root)
{
  if(root==NULL)
    return;
  cout<<(noNodes(root->left)-noNodes(root->right))<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

Node* levelOrderInsert(int arr[],int n)
{
	Node* root = getNewNode(arr[0]);

	queue<pair<Node*,int>> q;
	q.push({root,0});
	while(!q.empty())
	{
		pair<Node*,int> p =q.front();
		if(2*p.second+1<n){
			p.first->left= getNewNode(arr[2*p.second+1]);
			q.push({p.first->left,2*p.second+1});
		}
		if (2*p.second + 2 < n) {
      p.first->right = getNewNode(arr[2*p.second + 2]);
      q.push({p.first->right, 2*p.second + 2});
    }

		q.pop();
	}

	return root;
}



int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  Node* root = NULL;
  root=levelOrderInsert(arr,n);
  preOrder(root);

//cout<<noNodes(root);

  return 0;
}
