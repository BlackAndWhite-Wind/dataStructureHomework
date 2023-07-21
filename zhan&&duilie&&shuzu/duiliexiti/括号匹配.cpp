// 栈实现括号匹配问题

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;

typedef struct {
	char data[N];
	int top;
} SqStack;

void InitStack(SqStack &S) {
	S.top = -1;
}

bool StackEmpty(SqStack S) {
	return S.top == -1;
}

void Push(SqStack &S, char val) {
	if (S.top == N - 1) return;
	S.data[++S.top] = val;
}

char Pop(SqStack &S) {
	if (S.top == -1) return '\0';
	return S.data[S.top--];
}

bool isValid(string s) {
	SqStack S;
	InitStack(S);
	for (auto c : s) {
		if (c == '(' || c == '[' || c == '{') Push(S, c);
		else {
			if (StackEmpty(S)) return false;
			char top_val = Pop(S);
			if (c == ')' && top_val != '(') return false;
			if (c == ']' && top_val != '[') return false;
			if (c == '}' && top_val != '{') return false;
		}
	}
	return StackEmpty(S);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input1 = "()[]{}";
	string input2 = "([)]";
	string input3 = "{[()]}";
	cout << isValid(input1) << endl; // Output: 1 (true)
	cout << isValid(input2) << endl; // Output: 0 (false)
	cout << isValid(input3) << endl; // Output: 1 (true)


	return 0;
}
