//Sorting a Stack using recursion

#include<iostream>
#include<stack>

void sortedInsert(std::stack<int>&s, int x){

	if(s.empty() || x > s.top()){ //If either empty stack or element greator than top and others
		s.push(x);
		return;
	}

	int t = s.top();
	s.pop(); //Most important line for arrangement in order
	sortedInsert(s, x);//Remove the top and sort again

	s.push(t);
	
}

void sortStack(std::stack<int> &s){

	if(!s.empty()){

		int x = s.top();
		s.pop();

		sortStack(s);
		sortedInsert(s, x);
		
	}
}

int main(){

	std::stack<int> k;

	k.push(4);
	k.push(6);
	k.push(2);

	sortStack(k);

	std::cout<<k.top()<<" ";
    	k.pop();
	std::cout<<k.top()<<" ";
	k.pop();  	
	std::cout<<k.top()<<"\n";

	
	return 0;
	
}
