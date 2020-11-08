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
void LevelOrder(BstNode* root)
{
    BstNode* current;
    queue<BstNode*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        current = Q.front();
        Q.pop();
        cout<<current->data<<" ";
        if(current->left!=NULL)Q.push(current->left);
        if(current->right!=NULL)Q.push(current->right);
    }
}
void PreOrder(BstNode* root)
{
    if(root == NULL) return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(BstNode* root)
{
    if(root == NULL) return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void PostOrder(BstNode* root)
{
    if(root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    BstNode* root = NULL;
    root = Insert(root,10);
    root = Insert(root,15);
    root = Insert(root,50);
    root = Insert(root,20);
    root = Insert(root,30);
    root = Insert(root,40);
    root = Insert(root,8);
    root = Insert(root,7);
    root = Insert(root,9);
    if(Search(root,12)==true)cout<<"Item Found"<<endl;else cout<<"Item not Found"<<endl;
    if(Search(root,10)==true)cout<<"Item Found"<<endl;else cout<<"Item not Found"<<endl;
    cout<<"The minimum element in an BST is: "<<Findmin(root)<<endl;
    cout<<"The maximum element in an BST is: "<<Findmax(root)<<endl;
    cout<<"Length of the BST is: "<<Findlength(root)<<endl;
    cout<<"Level-Order or Breath-For-Search Algorithm: ";
    LevelOrder(root);
    cout<<endl;
    cout<<"Pre-Order: ";
    PreOrder(root);
    cout<<endl;
    cout<<"In-Order: ";
    InOrder(root);
    cout<<endl;
    cout<<"Post-Order: ";
    PostOrder(root);
    cout<<endl;
}