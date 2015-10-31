//Detect if a loop exists between nodes or check for graph

//Floyd cycle finding algorithm

#include<iostream>
#include<forward_list>
#include<iterator>

int detectLoop(std::forward_list<int> l){

	auto p1 = l.begin(), p2 = l.begin();	 //Initialise two pointers to head

	while(p1 != l.end() && p2 != l.end() && std::next(p2, 1) != l.end()){ //Move p1 by 1 and p2 by 2 positions
		
		if(*(++p1) == *(++(++p2))){ //Element p1 and p2 are equal -> loop
			return 1;
		}
	}
	return 0;
} 

int main(){

	std::forward_list<int> l = {1,2,1};
	
	auto i = l.begin();

	std::next(i, 3) = i; //Equivalent to a->next n times
	
	for(auto i = l.begin(); i != l.end(); ++i)
		std::cout<<*i<<"\n";

	std::cout<<"Loop "<<detectLoop(l)<<"\n";

	return 0;
	
}
