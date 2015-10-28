//Search for element in linked list iterative and recursive

#include<iostream>
#include<forward_list>


//Iterative search
bool iSearch(std::forward_list<int> l, int s){

	for(auto i = l.begin(); i != l.end(); ++i){

		if( *i == s)
			return 1;
	}

	return 0;
}

//Recursive Search
bool rSearch(std::forward_list<int> l, int s){

	if(l.front() == s)
		return 1;
	else if(l.empty())
		return 0;

	l.pop_front();
	rSearch(l, s);
}

int main(){

  std::forward_list<int> mylist = {2, 16, 77};
  std::cout<<iSearch(mylist, 2)<<" "<<rSearch(mylist, 2);
  
  
  return 0;
} 
