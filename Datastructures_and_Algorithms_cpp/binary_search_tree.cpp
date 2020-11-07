#include<bits/stdc++.h>
using namespace std;
struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};
BstNode* GetnewNode(int data)
{
    BstNode* temp = new BstNode();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
BstNode* Insert(BstNode* root,int data)
{
    if(root == NULL)
        root = GetnewNode(data);
    else if(data<=root->data)
        root->left = Insert(root->left,data);
    else if(data>=root->data)
        root->right = Insert(root->right,data);
    return root;
}
bool Search(BstNode* root,int data)
{
    if(root==NULL)
        return false;
    else if(data == root->data)
        return true;
    else if(data<root->data)
        return Search(root->left,data);
    else
        return Search(root->right,data);
    return false;
}
int main()
{
    BstNode* root = NULL;
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,30);
    root = Insert(root,2);
    if(Search(root,12)==true)cout<<"Item Found"<<endl;else cout<<"Item not Found"<<endl;
    if(Search(root,10)==true)cout<<"Item Found";
}