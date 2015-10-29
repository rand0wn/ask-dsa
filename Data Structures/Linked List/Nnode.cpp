//Return value from nth node from the end or (length - n + 1) position

#include<iostream>
#include<forward_list>

//Using iteration

int iReturn(std::forward_list<int> l, int n){

	int k;
	for(auto i = l.begin(); i <= (l.end() - n + 1); i++)
		k = *i;

	return k;
}

/*
//Using recursion
int rReturn(std::forward_list<int> l, int n){

    static int i = 0;
    auto it = l.begin();
	
	if(it != l.end())
		return;
	rReturn(++it, n);
	
	if(++i == n)
		return *it; 
}
*/

//Using two pointers
int pReturn(std::forward_list<int> l, int n){

	auto i1 = l.begin(), i2 = l.begin();

	i1 += n;
	
	while(i1 != l.end()){
		++i1;
		++i2;
	}

	return *i2; 
}

int main(){
	
	std::forward_list<int> s = {1,2,3};
	std::cout<<iReturn(s, 1)<<" "<<pReturn(s, 1)<<"\n";
	
	return 0;
}
