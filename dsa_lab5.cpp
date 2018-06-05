#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	int hd;
	Node* left;
	Node* right;
};

Node* getNewNode(int data)
{
	Node* newNode=new Node();
	newNode->data=data;
	newNode->hd=INT_MAX;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

Node* levelOrderInsert(int arr[],int n)
{
	Node* root = getNewNode(arr[0]);

	queue<pair<Node*,int> > q;
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

bool findPath(Node* root,vector<int> &path,int k)
{

  if(root==NULL)
  return false;

  path.push_back(root->data);
 //cout<<root->data<<"  inserted  ";

  if(root->data==k)
  return true;

  if((root->left && findPath(root->left,path,k))||(root->right && findPath(root->right,path,k)))
  return true;

  path.pop_back();
 //cout<<"   deleted   ";
  return false;
}

int findSum(Node* root,int n1,int n2)
{
  int sum=0;
  vector<int> p1,p2;

 if(!findPath(root,p1,n1)||!findPath(root,p2,n2))
 return -1;


 {

  int i,j,k;

  for(i=0;i<min(p1.size(),p2.size());i++)

  {
    if(p1[i]!=p2[i])
      break;
  }

  i-=1;



  for( j=i;j<p1.size();j++)
  {
    sum+=p1[j];
  }
  for( j=i;j<p2.size();j++)
  {
    sum+=p2[j];
  }



  //cout<<p1[i]<<"  "<<p2[j]<<"  ";
  //++i;
  //cout<<p1[i];
  sum-=p1[i];
  //cout<<p1[i];
   return sum;
 }

}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  Node* root=NULL;
  for (int i=0;i < n; i++)
  {
    cin>>arr[i];
  }
  root=levelOrderInsert(arr,n);
  int q;
  cin>>q;
  for(int i=0;i<q;i++)
  {
    int n1,n2;
    cin>>n1>>n2;
    int sum = findSum(root,n1,n2);
    cout<<sum<<endl;
  }

  return 0;
}
