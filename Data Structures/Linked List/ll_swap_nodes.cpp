//Swap nodes by changing links not data in a linked list

#include<iostream>
#include<forward_list>
#include<algorithm>

/*Cases(if not using STL but struct node):
1) x and y may or may not be adjacent.
2) Either x or y may be a head node.
3) Either x or y may be last node.
4) x and/or y may not be present in linked list.
 */

void swap(std::forward_list<int> l, int x, int y){

//Find index
	
	auto ix = std::find(l.begin(), l.end(), x);
	auto iy = std::find(l.begin(), l.end(), y);

//Swap
	
	auto t = ix;
	ix = iy;
	iy = t;

	std::cout<<*ix<<" "<<*iy;
}

int main(){

	std::forward_list<int> k = {1,2,3};
	swap(k,2,3);
	return 0;
}
