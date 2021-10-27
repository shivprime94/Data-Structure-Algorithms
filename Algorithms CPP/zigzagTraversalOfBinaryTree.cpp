#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

class Solution
{
    public:
        vector<vector<int> > zigzagLevelOrder(Node* A) {
        vector<vector<int>> ans;
        if(!A) return ans;
        int n, level = 0;
        queue<Node*> q;
        q.push(A);
        while(!q.empty()){
            vector<int> tmp;
            n = q.size();
            if(level%2==0){
                for(int i=0;i<n;i++){
                    Node *temp = q.front();
                    q.pop();
                    tmp.push_back(temp->data);
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }else {
                for(int i=n-1;i>=0;i--){
                    Node *temp = q.front();
                    q.pop();
                    tmp.push_back(temp->data);
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
                reverse(tmp.begin(),tmp.end());
            }
            
            level++;
            ans.push_back(tmp);
        }
        return ans;
    }


    
};

int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        
        Solution obj;
    	Node* root = buildTree(s);
    	
    	cout<<"Inorder of given tree: "; printInorder(root); cout<< endl;
    	
    	vector<vector<int>> ans = obj.zigzagLevelOrder(root);
    	cout<<"Levelorder zigzag Traversal of the tree: \n";
    	for(int i=0;i<ans.size();i++){
    	    for(int j=0;j<ans[i].size();j++){
    	        cout<<ans[i][j]<<" ";
    	    }
    	    cout<<endl;
    	}
        cout << endl;
    }
	return 0;
}
