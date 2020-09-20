#include<bits/stdc++.h>
using namespace std;
const char newline = '\n';
#define MAXSIZE 100
int top = -1;
int arr[MAXSIZE];
void push(int n)
{
	if(top == MAXSIZE-1)
	{
		cout<<"Error: Stack Overflow"<<newline;
		return;
	}
	arr[++top]=n;
	return;
}
void pop()
{
	if(top == -1)
	{
		cout<<"Error: Stack is Empty"<<newline;
		return;
	}
	top--;
}
void Top()
{
	if(top==-1)
		cout<<"Error: No Element is Present \n  Stack is Empty"<<newline;
	else
		cout<<arr[top]<<newline;
}
void IsEmpty()
{
	if(top==-1)
		cout<<"Error: Stack is Empty"<<newline;
	else
		cout<<"Stack is not Empty"<<newline;
}
void Print()
{
	for(int i=0;i<=top;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<newline;
}
int main()
{
	push(2);Print();// 2
	push(3);Print();// 2 3
	push(4);Print();// 2 3 4
	pop();Print();  // 2 3
	Top();          // 3
	IsEmpty();      // Stack is not Empty
	pop();Print();  // 2
	pop();Print();  //
	pop();		// Error: Stack is Empty
	pop();		// Error: Stack is Empty
	Top();		// Error: No Element is Present
			//          Stack is Empty
}
