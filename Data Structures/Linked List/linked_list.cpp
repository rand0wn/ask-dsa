//Linked List with three types of insetions and four types of deletions

#include<iostream>

struct node{
	int data;
	struct node *next;
};

class ll{

	struct node *head;

public:

	ll(){
		head = NULL;	
	}     
	
	/*Insertion:
	  1.Front : Like a stack
	  2.Rear : Like a queue
	  3.After : After a certain element
	 */

	//Always join left to right
	
	void insert(int n, char w, int s = 0){ //n as data and w f/r/a as Front, rear and after
		//k as element data for after element
		
		struct node *l = new node;
		struct node *k; //For iteration
		
        l -> data = n;
		l -> next = NULL;
		
		if(w == 'f'){ //Front insertion
			l -> next = head;

			head = l;

			std::cout<<"Element inserted at front\n";
		}

		else if(w == 'r'){ //Rear insertion
			k = head;

			while(k -> next != NULL)
				k = k -> next;
			
			k -> next = l; //Point last node to new

			std::cout<<"Element inserted at rear\n";
		}else{ //Insert after the element with value s

			k = head;

			while(k -> data != s)
				k = k -> next;
			
			l -> next = (k -> next) -> next;

			std::cout<<"Element inserted at position\n";
		}
	}

	/*
	  Deletion:
	  1. Delete last element
	  2. Delete element of given data
	 */

int ldelete(char w, int s = 0){

		struct node *k, *t;
		int d;
		
		if(w == 'r'){

			k = head;

			while(k -> next != NULL)
				k = k -> next;

			int d = k -> data;
			
			delete k;
			return d;
   		}else{


			k = head;

			while(k -> data != s)
				k = k -> next;

			t = k -> next; //Transform the link to a link after

			k -> next = t -> next;

			return s;
			
			delete k;
		}
		
	}
};


int main(){

	ll l;

	l.insert(1,'f');
	l.insert(2,'r');
	l.insert(3,'a',1);

	std::cout<<l.ldelete('r')<<"\n";
	std::cout<<l.ldelete('a',1)<<"\n";

	return 0;
}
