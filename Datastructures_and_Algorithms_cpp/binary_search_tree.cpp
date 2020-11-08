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
int Findmin(BstNode* root)
{
    if(root == NULL)
        throw "Error: bst is Empty";
    else
        while(root->left!=NULL)
            root = root->left;
    return root->data;
}
int Findmax(BstNode* root)
{
    if(root==NULL)
        return false;
    else
        while(root->right!=NULL)
            root=root->right;
    return root->data;
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
int Findlength(BstNode* node,int count=0)
{
    if(node == NULL)
        return count;
    return max(Findlength(node->left,count+1),Findlength(node->right,count+1));
}
//      or
// int Findlength(BstNode* node)
// {
//     if(node == NULL)
//         return 0;
//     return(Findlength(node->left)+1+Findlength(node->right));
// }
int main()
{
    BstNode* root = NULL;
    root = Insert(root,10);
    root = Insert(root,15);
    root = Insert(root,50);
    root = Insert(root,20);
    root = Insert(root,30);
    root = Insert(root,40);
    if(Search(root,12)==true)cout<<"Item Found"<<endl;else cout<<"Item not Found"<<endl;
    if(Search(root,10)==true)cout<<"Item Found"<<endl;else cout<<"Item not Found"<<endl;
    cout<<"The minimum element in an BST is: "<<Findmin(root)<<endl;
    cout<<"The maximum element in an BST is: "<<Findmax(root)<<endl;
    cout<<Findlength(root)<<endl;
}