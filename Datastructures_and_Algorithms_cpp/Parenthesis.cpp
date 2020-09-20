//Balanicing Parenthesis
#include<bits/stdc++.h>
using namespace std;
bool checkExp(string s)
{
	stack<char>S;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='[' or s[i]=='(' or s[i]=='{')
		{
			S.push(s[i]);
		}
		else if(s[i] == ']' or s[i] ==')' or s[i] =='}')
		{
			if(S.empty())
				return false;
			else
			{
				if(S.top()=='[' and s[i]==']')
					S.pop();
				else if(S.top()=='(' and s[i]==')')
					S.pop();
				else if(S.top()=='{' and s[i]=='}')
					S.pop();
				else
					return false;
			}
		}
	}
	if(S.empty())
		return true;
	else
		return false;
}
int main()
{
	string s = "{(A+B)+(A-B)+(A*B)(){}{}}";
	if(checkExp(s))
		cout<<"Correct"<<endl;
	else
		cout<<"Not Correct"<<endl;

}
