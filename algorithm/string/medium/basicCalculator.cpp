#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution{
public:
	long long calculate(string s, bool isminus = false){
		int i;
		for (i = 0; i<s.size(); ++i){
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
				break;
			}
		}
		if (i == 0){
			cerr << "Invalid expression" << endl;
			exit(-1);
		}
		if (i != s.size()){
			long long left = stoll(s.substr(0, i - 0));
			if (s[i] == '+'){
				if (isminus)
					return left - calculate(s.substr(i+1), false);
				else
					return left + calculate(s.substr(i + 1), false);
			}
			else if (s[i] == '-'){
				if (isminus)
					return left + calculate(s.substr(i + 1), true);
				else
					return left - calculate(s.substr(i+1), true);
			}
			else if (s[i] == '*' || s[i] == '/'){
				int j;
				for (j = i + 1; j<s.size(); ++j){
					if (s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/'){
						break;
					}
				}
				if (j == i + 1){
					cerr << "Invalid expression" << endl;
					exit(-1);
				}
				if (j != s.size()){
					long long right = stoll(s.substr(i + 1, j - i));
					if (s[i] == '*'){
						return calculate(to_string(left * right) + s.substr(j), isminus);
					}
					else{
						return calculate(to_string(left / right) + s.substr(j), isminus);
					}
				}
				else{
					if (s[i] == '*')
						return left * stoll(s.substr(i + 1));
					else
						return left / stoll(s.substr(i + 1));
				}
			}
		}

		return stoll(s);
		
	}

	bool isOperator(const char ch) {
		return (ch=='+' || ch=='-' || ch=='*' || ch=='/');
	}


	int Priority(const char c) {
		if (c == '*' || c == '/') {
			return 2;
		} else if (c== '+' || c == '-') {
			return 1;
		} else {
			return 0;
		}
	}

	long long calculate_exp(long long x, long long y, char op) {
		switch(op) {
			case '+': return x + y;
			case '-': return x - y;
			case '*': return x * y;
			case '/': return x / y;
		}
		return -1;
	}


	//Two Stacks solution
	int calculate_two_stacks(string& s) {
		s += "+0";
		stack<long long> num_stack; 
		stack<char> op_stack;

		#define CALCULATE_IT { \
			long long y = num_stack.top(); num_stack.pop(); \
			long long x = num_stack.top(); num_stack.pop(); \
			char op = op_stack.top(); op_stack.pop(); \
			num_stack.push(calculate_exp(x, y, op));\
		}

		for(int i = 0; i < s.size(); i++){
			char ch = s[i];
			if (isspace(ch)) continue;
			if (isdigit(ch)) {
				string num;
				num += s[i];
				while(isdigit(s[i+1])){
					num += s[i+1];
					i++;
				}
				num_stack.push(stoll(num));
				continue;
			}
			if (isOperator(ch)) {
				while (!op_stack.empty() && Priority(op_stack.top()) >= Priority(ch) ) {
					CALCULATE_IT;
				}

				op_stack.push(ch);
			}

		}

		while(!op_stack.empty()){
			CALCULATE_IT;
		}
		
		return num_stack.top();
	}

	int calculate2(string s) {
		return calculate_two_stacks(s);
	}

	// version dealing with ()
	int calculate3(string s) {
        stack<int64_t> operands;
        stack<char> operators;
        string operand;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (isdigit(s[i])) {
                operand.push_back(s[i]);
                if (i == 0 || !isdigit(s[i - 1])) {
                    reverse(operand.begin(), operand.end());
                    operands.emplace(stol(operand));
                    operand.clear();
                }
            } else if (s[i] == ')' || s[i] == '*' ||
                       s[i] == '/') {
                operators.emplace(s[i]);
            } else if (s[i] == '+' || s[i] == '-') {
                while (!operators.empty() && (operators.top() == '*' ||
                       operators.top() == '/')) {
                     compute(operands, operators);
                }
                operators.emplace(s[i]);
            } else if (s[i] == '(') {
                // operators at least one element, i.e. ')'.
                while (operators.top() != ')') {
                    compute(operands, operators);
                }
                operators.pop();
            }
        }
        while (!operators.empty()) {
            compute(operands, operators);
        }
        return operands.top();
    }

    template<typename T>
    void compute(stack<T>& operands, stack<char>& operators) {
        const auto left = operands.top();
        operands.pop();
        const auto right = operands.top();
        operands.pop();
        const char op = operators.top();
        operators.pop();
        if (op == '+') {
            operands.emplace(left + right);
        } else if (op == '-') {
            operands.emplace(left - right);
        } else if (op == '*') {
            operands.emplace(left * right);
        } else if (op == '/') {
            operands.emplace(left / right);
        }
    }
};

int main()
{
	Solution sol;
	string s;
	while (getline(cin, s))
		cout << sol.calculate3(s) << endl;
	return 0;
}