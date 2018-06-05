#include<bits/stdc++.h>
#include<queue>
using namespace std;
#define li long long int
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

bstNode* levelOrderInsert(li arr[],int n)
{
	if(arr[0]==-1)
		return NULL;

	bstNode* root = newNode(arr[0]);
	//cout<<root->data<<endl;
	//queue<pair<bstNode*,int> > q;
	queue<bstNode*> q2;
	q2.push(root);
	//q.push({root,0});
	int i=1;
	while(!q2.empty())
	{	/*
		pair<bstNode*,int> p =q.front();
		if(2*p.second+1<n){
			if(arr[2*p.second+1]==-1)
				//p.first->left= NULL;
			else
				p.first->left= newNode(arr[2*p.second+1]);
			//cout<<arr[2*p.second+1]<<" "<<2*p.second+1<<" "<<endl;
			q.push({p.first->left,2*p.second+1});
		}
		if (2*p.second + 2 < n) {
			if(arr[2*p.second + 2]==-1)
				//p.first->right = NULL;
			else
      			p.first->right = newNode(arr[2*p.second + 2]);
      		//cout<<arr[2*p.second+2]<<" "<<2*p.second + 2<<" "<<endl;
      q.push({p.first->right, 2*p.second + 2});
	*/
		bstNode* p =q2.front();


    //cout<<i<<endl;
		if(i<n)
		{

			if(arr[i]!=-1)
			{
				p->left=newNode(arr[i]);
				//cout<<arr[i]<<endl;
				q2.push(p->left);
			}

		}
		i++;
    //cout<<i<<endl;
		if(i<n)
		{

			if(arr[i]!=-1)
			{
				p->right=newNode(arr[i]);
				//cout<<arr[i]<<endl;
				q2.push(p->right);
			}

		}
		i++;
    //cout<<i<<" "<<n<<endl;
	q2.pop();
}
  //cout<<root->left->left->data;
	return root;
}

void inorderTrverse1(bstNode* root)
{
	if(root==NULL)
		return;
	inorderTrverse1(root->left);
	cout<<root->data<<" ";
	inorderTrverse1(root->right);
}

void inorderTrverse(bstNode* root,vector<li> &arr)
{

	if(root==NULL)
		return;
	inorderTrverse(root->left,arr);
	//cout<<root->data<<" ";
	arr.push_back(root->data);
	inorderTrverse(root->right,arr);
}

bool CheckBST(bstNode* root,li n)

{
	vector<li> arr;
	//li arr[n];

	inorderTrverse(root,arr);
	int flag =0;
	for(int i=0;i<arr.size()-1;i++)
	{
		if(arr[i+1]<arr[i])
		{
			flag=1;
			break;
		}
	}

	if(flag==0)
		return true;
	else
		return false;
}

int main()
{
	li n;
	cin>>n;
	li arr[n];

	for(li i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	bstNode* root=NULL;

	root=levelOrderInsert(arr,n);

	//inorderTrverse1(root);

	if(CheckBST(root,n))
		cout<<"yes";
	else cout<<"no";

	//cout<<"yes";



	return 0;
}
