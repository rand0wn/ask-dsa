// Largest multiple of three formed by addition of array elements only for unidigit

#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>

int osize;

int* largestmul3(int *A, int n){ //C++ does not have return type array but can use pointer*

	std::queue<int> q0, q1, q2;
	
	std::sort(A, A + n); //Sorting in ascending order

	int sum = 0; //Sum of Array
	
	for(int i = 0; i < n; i++){

		sum += A[i];
			
		if((A[i] % 3) == 0)  //Queue insertion
			q0.push(A[i]);
		else if((A[i] % 3))
			q1.push(A[i]);
		else
			q2.push(A[i]);
	}
	
	std::cout<<sum<<"\n"; //This line fixed the variable sum, Why?
	
	//Smallest reminder removed first will form largest number

	if(sum % 3 == 1){ //Check for sum of digits reminder

		if(!q1.empty())
			q1.pop(); //Pop one element with reminder 1

		else{

			if(!q2.empty())   //or Pop two elements with reminder 2
				q2.pop();
			else
				return 0;

			if(!q2.empty())
				q2.pop();
			else
				return 0;
			
		}

	}		if(sum % 3 == 2){ //Check for sum of digits reminder

		if(!q2.empty())
			q2.pop(); //Pop one element with reminder 2

		else{

			if(!q1.empty())   //or Pop two elements with reminder 1
				q1.pop();
			else
				return 0;

			if(!q1.empty())
				q1.pop();
			else
				return 0;
			
		}
	}
		osize = q0.size() + q1.size() + q2.size();
		int mul[osize]; //Size of merging arrray
		int index = 0;
		
		
		while( !q0.empty() || !q1.empty() || !q2.empty()){ //Merge all queues in array
			while(!q0.empty()){ //Fill array until all queues are empty
				mul[index++] = q0.front();
			    q0.pop();
            }
	while(!q1.empty()){
				mul[index++] = q1.front();
			    q1.pop();
            }
	while(!q2.empty()){
				mul[index++] = q2.front();
			    q2.pop();
            }

	}
//Decreasing order sort
    		std::sort(mul, mul + osize, std::greater<int>());
			
			return mul;
}

//Emplace and push: emplace calls contructor and creates a new section in the object while push transfers the temporary copy to the existing object

	int main(){
		int arr[] = {8, 1, 7, 6, 0};

		int *mul = largestmul3(arr, 5);
			
		for(int i = 0; i < osize ; i++)
			std::cout<<mul[i]<<" ";

		std::cout<<"\n"<<osize<<" \n";

		return 0;
	}	
