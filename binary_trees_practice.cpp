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

void preOrder(Node* root)
{
  if(root==NULL)
    return;
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node* root)
{
  if(root==NULL)
    return;
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

void postOrder(Node* root){
  if(root==NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
}

int height(Node* root)
{
	if (root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

void LevelOrderTraverse(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		int n=q.size();
		while(n!=0)
		{
		Node* currentNode=q.front();
		cout<<currentNode->data<<" ";

		if(currentNode->left!=NULL)
		q.push(currentNode->left);
		if(currentNode->right!=NULL)
		q.push(currentNode->right);
		q.pop();
		n--;
	  }
		cout<<endl;
	}

}

void leftViewUtil(Node* root,int h,int &minh)
{
	if(root==NULL)
	return;
	if(h>minh)
	{
		minh=h;
		cout<<root->data<<" ";
	}
	leftViewUtil(root->left,h+1,minh);
	leftViewUtil(root->right,h+1,minh);
}
void leftView(Node* root)
{
	int minh=0;
	leftViewUtil(root,1,minh);
  //cout<<endl;
}

void rightViewUtil(Node* root,int h,int &minh)
{
	if(root==NULL)
	return;
	if(h>minh)
	{
		minh=h;
		cout<<root->data<<" ";
	}
	rightViewUtil(root->right,h+1,minh);
	rightViewUtil(root->left,h+1,minh);
}
void rightView(Node* root)
{
	int minh=0;
	rightViewUtil(root,1,minh);
  //cout<<endl;
}

void bottomViewUtil(Node* root,int hd,int &minhd){
  if(root==NULL)
    return;
  bottomViewUtil(root->left,hd-1,minhd);
  if(hd>minhd){
    minhd = hd;
    cout<<root->data<<" ";
  }
  bottomViewUtil(root->right,hd+1,minhd);
}

void bottomView(Node* root){
  int minhd=INT_MIN;
  bottomViewUtil(root,0,minhd);
  cout<<endl;
}

void botView(Node* root)
{
	if(root==NULL)
	return;

	int hd=0;
	map<int,int> m;
	queue<Node*> q;
	root->hd=hd;
	q.push(root);

	while(!q.empty())
	{
		Node* temp=q.front();
		q.pop();
		hd=temp->hd;
		m[hd]=temp->data;
		if(temp->left!=NULL)
		{
			temp->left->hd=hd-1;
			q.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			temp->right->hd=hd+1;
			q.push(temp->right);
		}
	}

		for(auto i=m.begin();i!=m.end();i++)
	{
		cout<<i->second<<" ";
	}
}

void verticalview(struct Node* root){
   queue<pair<struct Node *,int> > q;
   map<int,vector<int> > m;
   q.push(make_pair(root,0));

   while(q.empty() == false){
      struct Node *temp = q.front().first;
      int hori = q.front().second;
      q.pop();
      m[hori].push_back(temp->data);
      if(temp->left)
        q.push(make_pair(temp->left,hori-1));
      if(temp->right)
        q.push(make_pair(temp->right,hori+1));
   }

   map<int,vector<int>> :: iterator it;
   for(it = m.begin();it!=m.end();it++){
     vector<int> t = it->second;
     for(int i=0;i<t.size();i++){
      cout<<t[i]<<" ";
     }
     //cout<<endl;
   }
   cout<<endl;
}

void spiral(Node* root){
  stack<Node*> st0rl,st1lr;
  if(root==NULL)
    return;
  int flag=0;
  st0rl.push(root);
  while((!flag && !st0rl.empty()) || (flag && !st1lr.empty())){
    if(!flag){
      while(!st0rl.empty()){
        Node *n = st0rl.top();
        st0rl.pop();
        cout<<n->data<<" ";
        if(n->right)
          st1lr.push(n->right);
        if(n->left)
          st1lr.push(n->left);
      }
      flag=!flag;
    }
    else{
      while(!st1lr.empty()){
        Node *n = st1lr.top();
        st1lr.pop();
        cout<<n->data<<" ";
        if(n->left)
          st0rl.push(n->left);
        if(n->right)
          st0rl.push(n->right);
      }
      flag=!flag;
    }
  }
  cout<<endl;
}

void topView(struct Node* root)
{
    if (root == NULL)
        return;

    unordered_map<int, int> m;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node*, int> p = q.front();
        Node *n = p.first;
        int val = p.second;
        q.pop();
        if (m.find(val)==m.end())
        {
            m[val] = n->data;
            printf("%d ", n->data);
        }

        if (n->left != NULL)
            q.push(make_pair(n->left, val-1));

        if (n->right != NULL)
            q.push(make_pair(n->right, val+1));
    }
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

	cout<<"LevelOrderTraverse :"<<endl;LevelOrderTraverse(root);
	cout<<endl<<"preOrder :";preOrder(root);
	cout<<endl<<"postOrder :";postOrder(root);
	cout<<endl<<"inOrder :";inOrder(root);
	cout<<endl<<"Left View :";leftView(root);
	cout<<endl<<"Right View :";rightView(root);

	cout<<endl<<"bottom :";bottomView(root);
	cout<<endl<<"bottom2 :";botView(root);
	cout<<endl<<"vertical :";verticalview(root);
	cout<<endl<<"spiral :";spiral(root);
  return 0;
}
