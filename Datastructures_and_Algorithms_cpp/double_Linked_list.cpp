#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node *prev;
	Node *next;
};
Node *head;
Node *GetNewNode(int x)
{
	Node *newNode = new Node();
	newNode->data=x;
	newNode->prev=NULL;
	newNode->next=NULL;
	return newNode;
}
void InsertAtHead(int x)
{
	Node *newNode = GetNewNode(x);
	if(head == NULL)
	{
		head = newNode;
		return;
	}	
	head->prev=newNode;
	newNode->next=head;
	head=newNode;
}
void InsertAtTail(int x)
{
	Node *newNode = GetNewNode(x);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	Node *temp = head;
	while(temp->next!=NULL)temp=temp->next;
	newNode->prev = temp;
	temp->next = newNode;
}
void Print()
{
	Node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void Reverse()
{
	if(head==NULL)return;
	Node *temp = head;
	while(temp->next!=NULL)temp=temp->next;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->prev;
	}
	cout<<endl;
}
int main()
{
	InsertAtHead(1);Print();
	InsertAtHead(2);Print();
	InsertAtTail(3);Print();
	Reverse();
}