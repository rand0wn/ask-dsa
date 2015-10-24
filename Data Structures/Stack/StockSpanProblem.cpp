// Solving stock span problem through stack

#include<iostream>
#include<stack>

void stockSpan(int price[], int n, int S[] ){

	std::stack<int> st; //Stack to push spans
    st.push(0);

	S[0] = 1; //Span of first element is always one

	for(int i = 0; i < n; i++){

        //At first call i = 0, give s = 1
		//Check position of price with last prices and store order
		while((!st.empty()) && price[st.top()] <= price[i]  )
			st.pop();

		//Empty stack means prices at index is greator than every price else than the top in stack
		S[i] = (st.empty())? (i + 1) : (i - st.top());

		st.push(i); //Push current value to stack 
	}
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
		std:: cout << a[i] << " ";
}

int main(){

	int price[] = {10, 4, 5, 90, 120, 80};
    int S[6];

	stockSpan(price, 6, S);
    print(S,6);

	return 0;
 
}
