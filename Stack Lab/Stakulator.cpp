#include <iostream>
#include "SequenceStack.h"
using namespace std;
int Stakulator(string s);
int calc(char opr, int num1, int num2);

void Stakulator_test() {
	string s;
	cout << "Input your sentence:" << endl;
	cin >> s;
	cout << "Result is: " << Stakulator(s) << "." << endl;
}

int Stakulator(string s)
{
	int iCatcher[2];
	char chCatcher;
	SequenceStack<char> OprStack(s.length());
	SequenceStack<int> NumStack(s.length());
	for (auto it : s) {
		switch (it) {
		case '0':case '1':case '2':case '3':case '4':
		case '5':case '6':case '7':case '8':case '9':
			NumStack.push(it - '0');
			break;
		case '+':case '-':
			while (OprStack.GetTop(chCatcher) && chCatcher != '(') {
				OprStack.pop(chCatcher);
				NumStack.pop(iCatcher[1]);
				NumStack.pop(iCatcher[0]);
				NumStack.push(calc(chCatcher, iCatcher[0], iCatcher[1]));
			}
			OprStack.push(it);
			break;
		case '*':case '/':
			while (OprStack.GetTop(chCatcher) && (chCatcher == '*' || chCatcher == '/')) {
				OprStack.pop(chCatcher);
				NumStack.pop(iCatcher[1]);
				NumStack.pop(iCatcher[0]);
				NumStack.push(calc(chCatcher, iCatcher[0], iCatcher[1]));
			}
			OprStack.push(it);
			break;
		case '(':
			OprStack.push(it);
			break;
		case ')':
			while (OprStack.GetTop(chCatcher) && chCatcher != '(') {
				OprStack.pop(chCatcher);
				NumStack.pop(iCatcher[1]);
				NumStack.pop(iCatcher[0]);
				NumStack.push(calc(chCatcher, iCatcher[0], iCatcher[1]));
			}
			OprStack.pop(chCatcher);
		}
	}
	while (!OprStack.IsEmpty()) {
		OprStack.pop(chCatcher);
		NumStack.pop(iCatcher[1]);
		NumStack.pop(iCatcher[0]);
		NumStack.push(calc(chCatcher, iCatcher[0], iCatcher[1]));
	}
	NumStack.pop(iCatcher[0]);
	return iCatcher[0];
}

int calc(char opr, int num1, int num2) {
	switch (opr) {
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	case '/': return num1 / num2;
	default:cout << "Calc error." << endl;
	}
}
