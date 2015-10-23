// Reverse a stack using recursion

#include<iostream>
#include<stack>

void insertBottom(std::stack<int> s, int x){ // Insert element x to bottom of stack s
    int t;
	if(!s.empty()){
		s.push(x);
	}else{
		t = s.top();
		s.pop();
		insertBottom(s, x);

		s.push(x);
	}
}

void reverse(std::stack<int> s){ // Reverse the stack

	int t;
	if(!s.empty()){

		t = s.top();
		s.pop();

		insertBottom(s, t);
	}
}

int main(){

	std::stack<int> s,l;
	s.push(5);
	s.push(10);
	s.push(15);
    l = s;
	std::cout<<l.top()<<" ";
	l.pop();
	std::cout<<l.top()<<" ";
	l.pop();
   	std::cout<<	l.top()<<" ";

	return 0;
}
