// CPP program to check for balanced brackets.
#include <bits/stdc++.h>
using namespace std;

// function to check if brackets are balanced
bool isValid(string s)
{
	stack<char> Stack;

        
		for(int i=0;i<s.size();i++)
		{
			if(Stack.empty())
			{
				Stack.push(s[i]);
			}
			else if((Stack.top()=='('&& s[i]==')') || (Stack.top()=='{' && s[i]=='}') || (Stack.top()=='[' && s[i]==']'))
			{
				Stack.pop();
			}
			else
			{
				Stack.push(s[i]);
			}
		}
        
        if(Stack.empty())
		{
			return true;
		}

		return false;
}

// Driver code
int main()
{
	string s = "{()()}";

	// Function call
	if (isValid(s))
		cout << "Balanced";
	else
		cout << "Not Balanced";

	return 0;
}
