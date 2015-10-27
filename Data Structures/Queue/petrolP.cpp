//Array of elements to visit cricular tour

/*Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.

1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.

Calculate the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). Expected time complexity is O(n). Assume for 1 litre petrol, the truck can go 1 unit of distance.

For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}. The first point from where truck can make a circular tour is 2nd petrol pump. Output should be ¡°start = 1¡å (index of 2nd petrol pump).
 */

//Visits are in a order with operations on two points, so queue will be appropriate
//no order of visits and set could be start or end


#include<iostream>

struct PP{ //Str. of Data
	int petrol;
	int dist;
};

int ctour(struct PP a[], int n){

//Start and ending point
	
	int start = 0, end = 1;

	int petrol = a[start].petrol - a[start].dist;
//Either tour completed or petrol remaining, end is changing here
	while(end != start || petrol < 0){


		//Either petrol becomes less than 0 or tour's completed
		while(petrol < 0 && start != end){ //Only start is changing here

			petrol -= a[start].petrol - a[start].dist;
			//Circular increment
			start = (start + 1) % n;

//If start is unchanged no tour
			if(!start)
				return -1;
		}
		
//Insertion of new petrol pump at end in same order as deletion (petrol - dist)
		petrol += a[end].petrol - a[end].dist;
//Circular Increment
		end = (end + 1) % n;
	}

	return start;
}
	
int main(){
	struct PP arr[] = {{6, 4}, {3, 6}, {7, 3}};

	std::cout<<ctour(arr, 3)<<"\n";
	
	return 0;
}
