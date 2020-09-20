#include<bits/stdc++.h>
using namespace std;
bool IsOperand(char c)
{
    if(c>='a' && c<='z')return true;
    else if(c>='A' && c<='Z')return true;
    else if(c>='0' && c<='9')return true;
    else return false;
}
bool IsOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')return true;
    else return false;
}
int GetWeight(char c)
{
    int weight = -1;
    switch(c)
    {
        case '*':
        case '/':
            weight = 2;
            break;
        case '+':
        case '-':
            weight = 1;
            break;
    }
    return weight;
}
bool HasHigherPrecedence(char char1,char char2)
{
    return GetWeight(char1)>=GetWeight(char2);
}
string InfixtoPostfix(string s)
{
    stack<int> S;
    string postfix = "";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ' || s[i]==',')continue;
        else if(IsOperand(s[i]))
        {
            postfix+=s[i];
        }
        else if(IsOperator(s[i]))
        {
            while(!S.empty() && S.top()!=')' && HasHigherPrecedence(S.top(),s[i]))
            {
                postfix+=S.top();
                S.pop();
            }
            S.push(s[i]);
        }
        else if(s[i]=='(')
        {
            S.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!S.empty() && S.top()!='(')
            {
                postfix+=S.top();
                S.pop();
            }
            S.pop();
        }
    }
    while(!S.empty())
    {
        postfix+=S.top();
        S.pop();
    }
    return postfix;
}
int main()
{
    string s;
    cin>>s;
    cout<<InfixtoPostfix(s)<<endl;
}

