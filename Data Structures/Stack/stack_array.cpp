// Implementation of Stack from array C++

#include<iostream>

class Stack{ 

private:
  int top; //Current elements in Stack
  int s[100]; //Array 's' with stack size

public:

  Stack(){
  top = -1; 
         }
  
  void push( int x ) { //Add a element to top of stack

    if( top == 100 ){ std::cout<<" Stack Full "<<std::endl;
                       return;
                     }     

    else{
      s[++top] = x; // Increment top and insert the element
      std::cout<<" Inserted "<<x<<" into stack at "<<top<<std::endl;
        }
  }

  int pop(){ //Remove and return top element in stack
            
    if( top == -1 ) return 0;
    
    else //Delete and return top element
      return s[top--];  
           }

  void display(){
               
    if( top == -1 ) std::cout<<"Stack Empty"<<std::endl;   
 
    else{
      std::cout<<"Stack : "; 
      for(int i = top; i>=0; i--)
	std::cout<<s[i]<<" ";        
         
    } std::cout<<std::endl;
              }
};

int main(){

  Stack S;
  S.push(5);
  S.push(10);
  S.push(15);
  S.display();
  S.pop();
  S.display();

  return 0;

}
