//Counting elements from linked list

#include<iostream>
#include<forward_list>
#include<algorithm>

void count(std::forward_list<int> l){

	int max = *std::max_element(l.begin(), l.end()) + 1;
	int c[max];
	std::fill_n(c, max, 0); //Initialise array with zero
	
	for(auto i = l.begin(); i != l.end(); ++i)
		c[*i]++; //Count element

	for(int j = 0; j < max; j++) //Print counted elements
	{
		if(c[j] != 0)
			std::cout<<"Element "<<j<<" occurs "<<c[j]<<" times\n";
	}
	
}

int main(){
	
	std::forward_list<int> l = {1,1,2,2,3,3};
	count(l);
}
