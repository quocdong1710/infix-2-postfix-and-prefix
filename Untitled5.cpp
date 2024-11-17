#include<bits/stdc++.h>
using namespace std;

int precedence(char c){
	if(c == '*' || c== '/') return 2;
	else return 1;
}

vector<char> postfix(vector<char> c){
	vector<char> res(c.size());
	stack<char> operators;
	for(int i=0;i<c.size();i++){
		if(c[i] >= 'A' && c[i] <= 'Z'){
			res.push_back(c[i]);	
		}
		else if(c[i] == '(' ){
			operators.push(c[i]);
		}
		else if(c[i] == ')' ){
			while(!operators.empty() && operators.top() != '('){
				res.push_back(operators.top());	
				operators.pop();
			}
			if (!operators.empty()) {
                operators.pop();
            }
		}
		else{
			while(!operators.empty() && precedence(operators.top()) >= precedence(c[i])){
				res.push_back(operators.top());
				operators.pop();
			}
			operators.push(c[i]);
		}
	}
	while(!operators.empty()){
		res.push_back(operators.top());
		operators.pop();
	}
	return res;
}
vector<char> prefix(vector<char> c){
	reverse(c.begin(),c.end());
	for(int i=0;i<c.size();i++){
		if(c[i] == '('){
			c[i] = ')';
		}
		else if(c[i] ==  ')'){
			c[i] = '(';
		}
	}
	vector<char> postfixExpression = postfix(c);
	reverse(postfixExpression.begin(),postfixExpression.end());
	
	return postfixExpression;
}



int main() {
    vector<char> expression;
    int n;
    cout<<"cin n so hang"<<endl;
    cin >>n;
    for(int i=0;i<n;i++){
    	char a;
    	cin>> a;
    	expression.push_back(a);
	}
    vector<char> result = postfix(expression);
    
    for (char c : result) {
        cout << c << " ";
    }
    return 0;
}