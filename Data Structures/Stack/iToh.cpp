// Iterative tower of Hanoi

#include<iostream>
#include<stack>
#include<cmath>


void move(char, char, int);
void movementbw2(std::stack<int> &src, std::stack<int> &dest, char s, char d){

	int p1t = 0, p2t = 0;
   
    if(!src.empty()){
	 p1t = src.top();
	src.pop();}
	if(!dest.empty()){
	 p2t = dest.top();
	dest.pop();}

	if(p1t == 0){
		src.push(p2t);
		move(d, s, p2t);
	}else if (p2t == 0){
		dest.push(p1t);
		move(s, d, p1t);
	}else if(p1t > p2t){
		src.push(p1t);
		src.push(p2t);
		move(d, s, p2t);
	}else{
		dest.push(p2t);
		dest.push(p1t);

		move(s, d, p1t);
	}
	
}

void move(char fPeg, char tPeg, int disk){

	std::cout<<"Move the disk "<<disk<<" from "<<fPeg<<" to "<<tPeg<<"\n";
	
}

void iToh(int n, std::stack<int> &src, std::stack<int> &aux, std::stack<int> &dest){
	int i, tmoves;
	char s = 'S', d = 'D', a = 'A';

	if(n % 2 == 0){
		char temp = d;
		d = a;
		a = temp;
	}

	tmoves = pow(2, n) - 1;
	
	for(int i = n; i>= 1; i--) //Filling the source, fixed SIGKILL due to i++
		src.push(i);

	for(i = 1; i <= tmoves; i++){

		if(i % 3 == 1)
			movementbw2(src, dest, s, d);
		else if(i % 3 == 2)
			movementbw2(src, aux, s, a);
		else if(i % 3 == 0)
    		movementbw2(aux, dest, a, d);
	}
}

int main(){

	int n = 3;
	std::stack<int> s, a, d;

	iToh(n, s, a, d);

	return 0;
	
}
