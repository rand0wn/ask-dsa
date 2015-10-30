//Find middle element of linked list

#include<iostream>
#include<forward_list>
#include<iterator>

int midList(std::forward_list<int> l){

	int mid = std::distance(l.begin(), l.end()); //Size of Linked List
	
	
	if( mid % 2 == 0) //Even digits two mid
	{
		int k = 0;
		for(auto i = l.begin(); i != l.end(); ++i){

			if(++k == mid/2)
				return *i; 
		}

	}else{ //Odd Digits mid + 1

	int k = 0;
	for(auto i = l.begin(); i != l.end(); ++i){

		if(++k == mid/2 + 1)
				return *i; 

	}
        }
	return -1;
}
	int main(){

		std::forward_list<int> l = {1,2,3,4};
		
		std::cout<<midList(l);

		return 0;
}	
