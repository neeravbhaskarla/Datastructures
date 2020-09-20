#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
Node *head = NULL;
Node *GetnewNode(int x)
{
	Node *newNode = new Node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void push(int x)
{
	Node *newNode = GetnewNode(x);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	newNode->next = head;
	head = newNode;
}
void Print()
{
	Node *temp = head;
	if(head == NULL)
		return;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
void Reverse()
{
	stack<Node *> S;
	Node *temp = head;
	if(head == NULL)
		return;
	while(temp!=0)
	{
		S.push(temp);
		temp=temp->next;
	}
	temp = S.top();
	head = temp;
	S.pop();
	while(!S.empty())
	{
		temp->next=S.top();
		temp=S.top();
		S.pop();
	}
	temp->next=NULL;
}
int main()
{
	cout<<"Normal Linkedlist"<<endl;
	push(4);push(3);push(2);push(1);
	Print();
	//Reversing the string
	cout<<"Reversed Linkedlist"<<endl;
	Reverse();Print();
}
