//Reversing a linked list

#include<iostream>
#include<forward_list>

//Recursive

int a = 0;

void rReverse(std::forward_list<int> &l){
	
	if(!l.empty()){
		 a = l.front();

		l.pop_front();  //Remove all elements until empty

		rReverse(l); 
	}else{

		l.push_front(a); //Insert elements from the function stack
		
	}
	
}

//Iterative
void iReverse(std::forward_list<int> &l){

	std::forward_list<int> s = l, r;
	
	for(auto i = l.begin(); i != l.end(); ++i) //Iterate, pop  and push into r
	{
		r.push_front(s.front());
		s.pop_front();	
	}
	l = r; //Assign s to l
}


int main(){
	std::forward_list<int> l = {1,2,3};
	rReverse(l);
		
	std::cout<<l.front()<<"\n";

	iReverse(l);

	std::cout<<l.front()<<"\n";

	return 0;
}
