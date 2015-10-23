//Implementing two stacks from a single array

#include<iostream>

class tStack{

private:
	int *A;   // Array of Stack
    int n; // Combined size of Stack
    int t1,t2; // Top indexes of both stacks
	int d; //Difference in top indexes between two stacks
public:
	void createStacks(int size){
		n = size;
	    A = new int[n];
        t2 = n + 1;
		t1 = -1;
		std::cout<<"Stacks are created\n";
	}

	void push(int x, int s){ // Element and Stack number

        d = t2 - t1;
		
		if(d > 1  && s == 1){

			A[++t1] = x;
			std::cout<<"\n Item Inserted ";
			
		}else if(d > 1 && s == 2){

			A[--t2] = x;
			std::cout<<"\n Item Inserted ";
		}else{

			std::cout<<"Cannot insert the element in Stack : Error\n";
		}

		
	} 

	int pop(int s){

		int x;

		d = t2 - t1;
		
		if(d <= n && s == 2 ){

			x = A[t2++];
			std::cout<<"\n Item Removed ";
			
		}else if(d >= 0 && s == 1){

			x = A[t1--];
			std::cout<<"\n Item Removed ";
			
		}else{
			std::cout<<"Stack Underflow \n";
		}
		return x;
	}

	void show(){

		std::cout<<"\nStack-1 : ";

		for(int i = t1; i>= 0; i--)
			std::cout<<A[t1]<<" ";

		std::cout<<"\nStack-2 : ";

		for(int i = t2; i<=n; i++)
			std::cout<<A[t2]<<" ";

		
	}
	
};


int main(){

	tStack S;
    S.createStacks(10);
	S.push(5,1);
	S.push(10,2);
	S.push(15,1);
	S.push(15,2);
	S.show();
	S.pop(1);
	S.pop(2);
	S.show();

	return 0;
}
