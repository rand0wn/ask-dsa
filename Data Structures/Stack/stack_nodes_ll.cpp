// Implementation of stack using nodes like a linked list

#include<iostream>

// Node for stack
	struct node{
		int data;
		struct node *next;
	};


class Stack{

private:

	struct node *top; // Element pointing to top

public:
	Stack(){
		top = NULL;
	}

	void push(int x){ //Push element to top of stack
		struct node *ptr;
		ptr = new node;
		ptr->data = x;
		ptr->next = NULL;

		if(top != NULL)
			ptr->next = top;

		top = ptr;
		std::cout<<"Item Insterted"<<std::endl;
	}

	void pop(){ // Removing the top value and printing it
		struct node *temp;
		if(top == NULL) std::cout<<"Stack Empty"<<std::endl;
		temp = top;
        top = top->next;        
		std::cout<<"Removed Value : "<<temp->data;
		delete temp;
	}

	void show(){ //Display the stack
		struct node *ptr;

		ptr = top;

		while(ptr != NULL){
			std::cout<<ptr->data<<" ";
			ptr = ptr->next;
		}
		std::cout<<"\n";
	}

};
         
int main(){
	Stack S;
	S.push(5);
	S.push(10);
	S.push(15);
	S.push(20);
	S.show();

	return 0;
}
