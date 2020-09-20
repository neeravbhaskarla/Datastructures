#include<bits/stdc++.h>
using namespace std;
struct Node{
	char data;
	Node *next;
};
Node *head=NULL;
Node *Getnode(char x)
{
	Node *newNode = new Node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void push(char x)
{
	Node *newNode = Getnode(x);
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
	if(head == NULL)return;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp = temp->next;
	}
	cout<<endl;
}
int main()
{
	stack<Node *>S;
	push('n');push('e');push('e');push('r');push('a');push('v');
	Print();
	Node *temp = head;
	while(temp!=NULL)
	{
		S.push(temp);
		temp = temp->next;
	}
	temp = NULL;
	while(!S.empty())
	{
		temp = S.top();
		cout<<temp->data;
		S.pop();
	}
	cout<<endl;

}
