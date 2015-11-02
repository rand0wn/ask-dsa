// Inserting an element in sorted list at some position

#include<iostream>
#include<forward_list>
#include<iterator>

void insertSorted(std::forward_list<int> &l, int n){ //DO NOT FORGET &ALIAS; ELEMENT IS CHANGED

	int c = 1;
	
	for(auto i = l.begin(); i != l.end(); ++i){

		if(c == 1 && *std::next( i, 1 ) > n ) //Find position to insert and just once
		{
			std::cout<<"RUN "<<*i<<"\n";
			i = l.emplace_after( i, n ); //Insert element just after i
			
			std::cout<<"RUN "<<*i<<"\n";
			c--;
			break;
		}
		
	}
	
}

int main(){

	std::forward_list<int> l = {1,2,4,5};

	insertSorted(l, 3);

	for(auto j = l.begin(); j != l.end(); ++j)
		std::cout<<*j<<"\n";
	
	return 0;
}
