//Return value from nth node from the end or (length - n + 1) position

#include<iostream>
#include<forward_list>
#include<iterator>

//Using iteration

int iReturn(std::forward_list<int> l, int n){

	int k = 0;

	for(auto i = l.begin(); i != l.end(); ++i){
		if(++k == std::distance(l.begin(), l.end()) - n + 1)
			return *i;
	}
}


//Using recursion
int rReturn(std::forward_list<int> l, int n){

    static int i = 0;

	if(i == n)
 	return l.front();

	if(!l.empty())
		
	{
	int a = l.front();
	
	l.pop_front();

	rReturn(l, n);
	
	l.push_front(a);

	i++;
	
     }
	
}

//Using two pointers
int pReturn(std::forward_list<int> l, int n){

	auto i1 = l.begin(), i2 = l.begin();

	std::advance(i1, n); //Move iterator to n places
	
	while(i1 != l.end()){
		++i1;
		++i2;
	}

	return *i2; 
}

int main(){
	
	std::forward_list<int> s = {1,2,3,4,5,6};
	std::cout<<iReturn(s, 1)<<" "<<rReturn(s, 1)<<" "<<pReturn(s, 1)<<"\n";
	
	return 0;
}
