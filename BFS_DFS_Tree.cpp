#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

void DFS_Traversal(TreeNode* root){
    stack<TreeNode* > pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size()>0){
        TreeNode* top = pendingNodes.top();
        cout<<top->data<<" ";
        pendingNodes.pop();
        if(top->right)pendingNodes.push(top->right);
        if(top->left)pendingNodes.push(top->left);
    }
}

void BFS_Traversal(TreeNode* root){
    queue<TreeNode* > pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size()>0){
        TreeNode* front = pendingNodes.front();
        cout<<front->data<<" ";
        pendingNodes.pop();
        if(front->left)pendingNodes.push(front->left);
        if(front->right)pendingNodes.push(front->right);
    }
}


int main(){
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node9 = new TreeNode(9);

    TreeNode* root = node1;

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node4->left = NULL;
    node4->right = NULL;
    node5->left = node8;
    node5->right = NULL;
    node6->left = NULL;
    node6->right = node9;
    node7->left = NULL;
    node7->right = NULL;
    node8->left = NULL;
    node8->right = NULL;
    node9->left = NULL;
    node9->right = NULL;

    cout<<"BFS traversal: ";
    BFS_Traversal(root);
    cout<<endl<<"DFS traversal: ";
    DFS_Traversal(root);
    
    return 0;
}