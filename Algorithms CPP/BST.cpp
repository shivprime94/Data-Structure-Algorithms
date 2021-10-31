#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
node* root=NULL;
node* getnewnode(int data){
	node* newnode=new node();
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
bool search(node*root, int data){
	if(root==NULL) return false;
	if(data==root->data) return true;
	if(data<root->data) return search(root->left,data);
	else return search(root->right,data);
}
node* insert(node* root, int data){
	if(root == NULL){
		root=getnewnode(data);
		return root;
	}
	if(data > root->data){
		root->right=insert(root->right,data);
	}
	else{
		root->left=insert(root->left,data); 
	}
	return root;
}
int main(){
	root=insert(root,20);
	root=insert(root,5);
	root=insert(root,10);
	root=insert(root,15);
	root=insert(root,30);
	root=insert(root,25);
	if(search(root,15)) cout<<"Found\n";
	else cout<<"Not found\n";
	return 0;
}
