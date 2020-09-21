#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node *head=NULL;
Node* CreateNewNode(int data)
{
    Node* newnode = new Node();
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void enqueue(int data)
{
    Node* node = CreateNewNode(data);
    if(head == NULL)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next = node;
}
void dequeue()
{   
    if(head==NULL) return;
    head = head->next;
}
int top()
{
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    return temp->data;
}
bool empty()
{
    if(head==NULL)return true;
    return false;
}
void Print()
{
    if(head == NULL) return;
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    enqueue(2);
    Print();
    enqueue(3);
    Print();
    enqueue(4);
    Print();
    top();
    if(empty())
        cout<<"list is empty"<<endl;
    else
        cout<<"list is not empty"<<endl;
    enqueue(5);
    Print();
    dequeue();
    Print();
    dequeue();
    Print();
    dequeue();
    Print();
    dequeue();
    if(empty())
        cout<<"list is empty"<<endl;
    else
        cout<<"list is not empty"<<endl;
    dequeue();
}