//Implementing queues from nodes like that in a linked list


#include<iostream>


class Queue{
	struct Node{
		int data;
		struct Node *next;
	};

	struct Node *front, *rear;

public:

	Queue(){
		front = rear = NULL;
	}

	void enQueue(int x){ //Insertion of a element
        struct Node *q;
		q = new Node;
		q -> data = x;
		q -> next = NULL;
		
        if(rear == NULL) //Empty Queue front = rear
		{  front = rear = q;
			std::cout<<"Queue Created and Item inserted\n ";
			return;
		}
		else if(front != rear) //Insert at rear
			q -> next = rear;
		
		rear = q;
		std::cout<<"Item Inserted\n ";
	}

	int deQueue(){
        struct Node *t;
		if(front == NULL) //Empty Queue nothing to delete
			return 0;
		
        else if(front == rear) //Single element in queue  
        {   int x = front->data;
			front = rear = NULL;
			return x;
		}
		else{                 //Delete the rear element and reassign
			 t = rear;
			 int x = t->data;
			 struct Node *f = front;

			 while(f -> next != NULL)
				 f = f -> next;
			 rear = f;

			 delete t;
			 return x;
		}
	}

	int front1(){ //Return front element
			return front->data;
		}

	int rear1(){ //Return rear element
			return rear->data;
		}
		
};


int main(){

	Queue Q;
    	Q.enQueue(5);

	std::cout<<Q.front1()<<" "<<Q.rear1()<<"\n";
   	Q.enQueue(15);
	std::cout<<Q.front1()<<" "<<Q.rear1()<<"\n";
	std::cout<<"Dequeue : "<<Q.deQueue()<<"\n";
	std::cout<<Q.front1()<<" "<<Q.rear1()<<"\n";
	return 0;
	
}
