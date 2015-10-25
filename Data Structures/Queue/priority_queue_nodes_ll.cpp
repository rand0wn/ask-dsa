// Implementing priority queue from nodes like a linked list

#include<iostream>

struct node{ //Structure of Node of PQueue
	int data;
	struct node *next;
	int priority;
};

class Pq{ //Front and Rear elements of Pqueue
		struct node *front, *rear;
        
	public:
	Pq(){ // Initialise to NULL
			front = rear = NULL;
		}
		
	void insert(int x, int p){ //Insert into priority queue
			struct node *ptr = new node;
			ptr->data = x;
			ptr->priority = p;
			ptr->next = NULL;

			if(rear == NULL){ //New queue
				front = rear = ptr;
				std::cout<<"Queue created and Item Inserted\n";
				return;
			}else if(front -> next == NULL){

				front -> next = ptr;
				ptr -> next = rear;	
    		   std::cout<<"Item Inserted\n";

			}else{
					ptr -> next = rear;	
    		   std::cout<<"Item Inserted\n";

			}
			rear = ptr;
		}

	struct node *getHighestPriority(){ //Return node with highest priority
			struct node *f = front;
            int pmax = 0; //Max priority

			while(f != rear){ //Iterate through queue
				if(f -> priority > pmax)
					pmax = f -> priority;
				f = f -> next;
			}
			return f;
		}

		int deleteHighestPriority(){
			struct node *t, *k; // Temp and transfer nodes
			int l; // Value of element to delete
			
			t = getHighestPriority(); //Highest priority element
			l = t->data; //Value of element
				
			k = front; //Node = front node

			while(k->next != t) //Find last node before node to delete
				k = k->next;
			
			k->next = t->next; //Assign last node to next node to maintain link after deleting

			delete t;
			return l;
		}

		
};


int main(){

	Pq P;
	struct node *s;
		
	P.insert(5,1);
	P.insert(10,2);
    s = P.getHighestPriority();	
	std::cout<<s->data<<" : Highest Priority\n ";

	std::cout<<"Deleted : "<<P.deleteHighestPriority()<<"\n";

	return 0;
}
