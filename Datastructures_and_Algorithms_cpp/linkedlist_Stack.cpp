//Stack using Linked list
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *link;
};
Node *head = NULL;
Node *getNode(int data)
{
	Node *newNode = new Node();
	newNode->data = data;
	newNode->link = NULL;
}
void push(int n)
{
	Node *newNode = getNode(n);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	newNode->link = head;
	head = newNode;
}
void pop()
{
	if(head == NULL)
		return;
	Node *temp = head;
	head = head->link;
	delete temp;
}
void Print()
{
	Node *temp = head;
	if(head==NULL)
		return;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<endl;
}
int main()
{
	push(2);Print();
	push(3);Print();
	push(4);Print();
	push(5);Print();
	pop();
	pop();Print();
}
