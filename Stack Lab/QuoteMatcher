#include <iostream>
#include "SequenceStack.h"
using namespace std;

bool QuoteMatch(string s) {
	SequenceStack<char>quoteStack(s.length());
	char pop_catcher;
	bool pop_success;
	try {
		for (auto it : s) {
			switch (it) {
			case '(':case '[':case '{':case '<':
				quoteStack.push(it);
				break;
			case ')':
				pop_success = quoteStack.pop(pop_catcher);
				if (!pop_success || pop_catcher != '(')throw runtime_error("Quote ')' unmatched");
				break;
			case ']':
				pop_success = quoteStack.pop(pop_catcher);
				if (!pop_success || pop_catcher != '[')throw runtime_error("Quote ']' unmatched");
				break;
			case '}':
				pop_success = quoteStack.pop(pop_catcher);
				if (!pop_success || pop_catcher != '{')throw runtime_error("Quote '}' unmatched");
				break;
			case '>':
				pop_success = quoteStack.pop(pop_catcher);
				if (!pop_success || pop_catcher != '<')throw runtime_error("Quote '>' unmatched");
				break;
			default:break;
			}
		}
		bool left_unmatched_flag = false;
		while (!quoteStack.IsEmpty()) {
			left_unmatched_flag = true;
			quoteStack.pop(pop_catcher);
			cout << "Quote " << pop_catcher << " unmatched" << endl;
		}
		if (left_unmatched_flag)throw runtime_error("Left unmatched");
	}
	catch (runtime_error e) {
		if (strcmp(e.what(), "Left unmatched"))cout << e.what() << endl;
		cout << "Quote not matched. Program exits." << endl;
		return false;
	}
	cout << "Perfect. Quotes all matched." << endl;
	return true;
}
