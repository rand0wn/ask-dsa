//Implementing a queue from array

#include<iostream>

class Queue{
	int front, rear, size, ndeq;//ndeq is number of deque operations performed in queue
	int Array[100];

public:
	Queue(){   //Initialising
		front = rear = ndeq = size = 0;

		Array[100] = {0};
	}
	bool empty(){ //Check for empty queue
		if(size)
			return 0;
		else
			return 1;
	}

	bool full(){ //Check for full queue
		if(size == 100)
			return 1;
		else
			return 0;
	}

	void enqueue(int x){ //Insert element at the back
		if(full())
			std::cout<<"Queue Full\n";
		else{
			Array[size++] = x;
			rear = x;
			front = Array[ndeq];
			std::cout<<"Item Inserted\n";
		}
	}
	int dequeue(){ //Remove element from the front
			int x;
			if(empty())
				return 0;
			else{
				x = Array[ndeq];
				Array[ndeq] = 0;
				front = Array[++ndeq];
				return x;
            	}
		}
	int front1()//Return Front element
		{ return front;}
	int rear1() //Return Rear element
		{	return rear; }
	
};

int main(){
	Queue Q;

	for(int i = 1; i < 9; i++)
		Q.enqueue(i);
		std::cout<<Q.front1()<<"\n";
		std::cout<<Q.dequeue()<<"\n";
		std::cout<<" Front: "<<Q.front1()<<"\n";	
    	std::cout<<Q.front1()<<"\n";
		return 0;
}
