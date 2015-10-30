//Delete a linked list

#include<iostream>
#include<forward_list>

void delList(std::forward_list<int> l){
	delete l;

	std::cout<<"Deleted List";
}

//For Custom linked delete every element iterating  through head 
