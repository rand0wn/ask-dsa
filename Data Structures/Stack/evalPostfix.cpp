//Evaluation of a numeric Postfix expression

#include<iostream>
#include<stack>
#include<string>
#include<cctype> //For isdigit()

int evalPostfix(std::string pos){
	std::stack<char> prs;

	for(int i = 0; pos[i]; i++){

		if(isdigit(pos[i]))
			prs.push(pos[i] - '0'); //Convert a char to int(x - '0') or (int)

		else{

			int a = prs.top();
			prs.pop();
			int b = prs.top();
			prs.pop();

			switch(pos[i]){

			case '+': prs.push(b + a); break;
			case '-': prs.push(b - a); break;
            case '*': prs.push(b * a); break;
			case '/': prs.push(b / a); break;
			}
                          			
			}		
	}

	return prs.top();
}

int main(){

	std::string postfix;

	std::cin>>postfix;

	std::cout<<evalPostfix(postfix)<<"\n";

	return 0;
	
}
