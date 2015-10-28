//Count elements of linked list using iteration and recursion

#include<iostream>
#include<forward_list> //Single linked list


//Iterative Count
int iCount(std::forward_list<int> l){

	int count = 0;

	for(auto i = l.begin(); i != l.end(); ++i)
		count++;

	return count;
}

//Recursive Count
int rCount(std::forward_list<int> l){

	if(l.empty())
		return 0;

	else{

		l.pop_front();
		return (1 + rCount(l));
		
	}

}

int main(){

	std::forward_list<int> mylist = {2, 16, 77};

	std::cout<<iCount(mylist)<<" "<<rCount(mylist)<<"\n";

	return 0;
}
