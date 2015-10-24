// Program to convert infix to postfix expression using stack

#include<iostream>
#include<stack>
#include<string>

// Function to check if the given character is operand
int isOp(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
 
// Precedence of Operators
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

// Function to change infix to postfix
int infix2postfix(std::string infix){
	std::stack<char> tempStack; // New Stack
    int i,k; //Index variables
	
	for(i = 0, k = -1; infix[i]; ++i){ //Main Iteration for Infix

		if(isOp(infix[i])) //Check for Operands
			infix[++k] = infix[i];

		else if(infix[i] == '(') //Open bracket : Push to stack
			tempStack.push(infix[i]);

		else if(infix[i] == ')'){ //Close bracket : Pop until last open bracket

			while(!tempStack.empty() && tempStack.top() != '('){
				infix[++k] = tempStack.top();
		        tempStack.pop();
			}
			if(!tempStack.empty() && tempStack.top() != '(')
				return -1;
			else
				tempStack.pop();
		}
		else{ //Operators arrangement in stack
			while(!tempStack.empty() && Prec(infix[i]) <= Prec(tempStack.top())){//Quite Similar to Stock Span Problem arrangement of element wrT other elements
               	infix[++k] = tempStack.top();
                tempStack.pop();
		}
		
			tempStack.push(infix[i]);
	}
	}

while(!tempStack.empty()){
infix[++k] = tempStack.top();
	tempStack.pop();
}
    infix[++k] = '\0';
	std::cout<<infix<<"\n";
}

int main(){

	std::string infix;

	std::cout<<"Enter an infix Expression : ";
	std::cin>>infix;
	
    infix2postfix(infix);
	return 0;

}
