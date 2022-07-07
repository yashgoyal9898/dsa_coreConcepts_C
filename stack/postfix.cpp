// C++ program to evaluate a Postfix expression.
#include <bits/stdc++.h>
using namespace std;
#include<math.h>

int evaluatePostfix(string s)
{
	stack<int> Stack;

	for (int j = 0; j<s.size(); j++) {

		// Push operand to Stack
		// To convert s[j] to digit subtract
		// '0' from s[j].
		
        if(s[j]>='0' && s[j]<='9')
			{
                Stack.push(s[j]-'0');
            } 
		else {

			// Operator encountered
			// Pop two elements from Stack
			double o2 = Stack.top();
			Stack.pop();
			double o1 = Stack.top();
			Stack.pop();

			// Use switch case to operate on o1
			// and o2 and perform o1 O o2.
			switch (s[j]) {
			case '+':
				Stack.push(o1 + o2);
				break;
			case '-':
				Stack.push(o1 - o2);
				break;
			case '*':
				Stack.push(o1 * o2);
				break;
			case '/':
				Stack.push(o1 / o2);
				break;
            case '^':
				Stack.push(pow(o1,o2));
				break;
			}
		}
	}

	return Stack.top();
}

// Driver code
int main()
{
	string s = "42*3+";
	cout << evaluatePostfix(s) << endl;
	return 0;
}
