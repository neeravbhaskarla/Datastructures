#include<bits/stdc++.h>
using namespace std;
const char newline = '\n';
struct Node{
	int data;
	Node *next;
};
Node *head;
Node *CreateNewNode(int x)
{
	Node *newNode = new Node();
	newNode->data=x;
	newNode->next = NULL;
	return newNode;

}
void InsertAtHead(int x)
{
	Node *newNode = CreateNewNode(x);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	newNode->next = head;
	head = newNode;

}
void InsertAtTail(int x)
{
	Node *newNode = CreateNewNode(x);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	Node *temp = head;
	while(temp->next!=NULL)temp=temp->next;
	temp->next = newNode;
}
void InsertAtPos(int x,int pos)
{
	if(pos == 1)
	{
		InsertAtHead(x);
		return;
	}
	Node *newNode = CreateNewNode(x);
	if(head==NULL)
	{
		head = newNode;
		return;
	}
	Node *temp = head;
	int i=2;
	while(temp!=NULL)
	{
		if(i==pos)
		{
			newNode->next = temp->next;
			temp->next = newNode;
			return;
		}
		i++;
		temp=temp->next;
	}
	return;
}
void Print()
{
	if(head == NULL)return;
	Node *temp = head;
	while(temp!= NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}	
	cout<<newline;
}
int main()
{
	InsertAtPos(6,1);
	InsertAtHead(5);
	InsertAtHead(4);
	InsertAtHead(3);
	InsertAtTail(7);
	InsertAtTail(8);
	InsertAtTail(9);
	InsertAtHead(2);
	InsertAtPos(10,9);
	InsertAtPos(1,1);
	InsertAtPos(11,11);
	Print();
	// Output: 1 2 3 4 5 6 7 8 9 10 11
}
