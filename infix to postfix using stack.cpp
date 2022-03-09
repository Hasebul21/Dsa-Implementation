/*#include<iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>
#include <utility>*/
#include<bits/stdc++.h>
using namespace std;

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

bool operand(char x)
{
    if(x>='a'&&x<='z') return true;
    if(x>='A'&&x<='Z') return true;
    return false;
}
string infixToPostfix(string s)
{
        stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(operand(s[i])) ans=ans+s[i];
            else if(s[i]=='(') st.push('(');
            else if(s[i]==')')
            {
                while(st.top()!='(')
                {
                   ans=ans+st.top();
                   st.pop();
                }
                st.pop();
            }
            else
            {
               bool inside=false;
               while(st.size()>0)
               {
                   if(Prec(s[i])<=Prec(st.top())&&s[i]!='^')
                   {
                      ans=ans+st.top();
                      st.pop();
                   }
                   else
                   {
                       st.push(s[i]);
                       inside=true;
                       break;
                   }
               }
               if(inside==false) st.push(s[i]);

            }

        }
        while(st.size()>0)
        {
            ans=ans+st.top();
            st.pop();
        }
        return ans;
    }
int main()
{
    string s="a+b*(c^d-e)^(f+g*h)-i";
    cout<<infixToPostfix(s)<<endl;

}
