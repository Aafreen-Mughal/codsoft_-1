#include<iostream>
using namespace std;
int main(){
	int num1,num2;
    double div;
	char operation;
	cout<<"Enter operation to perform(+,-,*,/): ";
	cin>>operation;
	cout<<"\nEnter num1 and num2 to perform "<<operation<<" : ";
	cin>>num1>>num2;
	switch(operation){
		case '+':
			cout<<"\nAddition of "<<num1 <<" and "<<num2<<" is "<<num1+num2;
			break;
		case '-':
			cout<<"\nSubtraction of "<<num1 <<" and "<<num2<<" is "<<num1-num2;
			break;
		case '*':
			cout<<"\nMultiplication of "<<num1 <<" and "<<num2<<" is "<<num1*num2;
			break;
		case '/':
			div=num1/num2;
			cout<<"\nDivision of "<<num1 <<" and "<<num2<<" is "<<div;
			break;		
	}
	
}
