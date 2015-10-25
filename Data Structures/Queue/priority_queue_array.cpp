//Implementing Priority Queue using array

#include<iostream>

struct item{ //Item of a priority queue
	int item;
	int priority;
};

class Pq{
	item *i = new item[100]; //Array Of Struct item of queue
    int x, p, size, ndeq;
	
public:
	Pq(){ //Constructor for initialising
		ndeq = 0;
		size = 0;
	}
	int empty(){ //Check for Empty Queue
		if(size == 0)
			return 1;
		else
			return 0;
	}
	int full(){ //Check for Full queue
		if(size == 100)
			return 1;
		else
			return 0;
	}

	void insert(int x, int p){
		if(empty()){ //if empty create queue
			i[size].item = x;
			i[size++].priority = p;

			std::cout<<"Priority Queue Created and Item Inserted\n";

		}else if(full()){ //if full don't insert
			std::cout<<"Queue is full\n";

		}else{ //Insert item
			i[size].item = x;
			i[size++].priority = p;

			std::cout<<"Item Inserted\n";	 
		}
	}

	int getHighestPriority(){ //Get Highest priority from queue
		int pmax = 0,index; //Max Priority and Index of item
		for(int k = 0; k <= size; k++){
			if(i[k].priority > pmax)
			{	pmax = i[k].priority;
				index = k;
			}
		}
		return index;
	}

	void deleteHighestPriority(){ //Delete item with highest priority
		int del; //Item to delete

		if(empty()){ //Empty then exit
			std::cout<<"Nothing to Delete\n";

		}else{ //Delete item
			del = i[getHighestPriority()].item;
			i[getHighestPriority()].item = 0;
            i[getHighestPriority()].priority = 0;
			ndeq++;
			std::cout<<"Deleted : "<<del<<"\n";
		}
		
	}

	void print(int ix){ //Print item at index
		std::cout<<"Item at index "<<ix<<" is "<<i[ix].item<<"\n";
	}
};

int main(){
	Pq P;
	P.insert(5,1);
	P.insert(10,2);
	int i = P.getHighestPriority();
    P.print(i);
	P.deleteHighestPriority();
	i = P.getHighestPriority();
    P.print(i);
	return 0;	
}
