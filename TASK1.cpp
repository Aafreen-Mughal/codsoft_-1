#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
main(){
  int num,u_num;
  srand(time(0));
 
  //generate random number till the range of 1000
  num=rand()%1000;
   cout<<num;
  cout<<"\nEnter number to guess it: ";
  label:
  cin>>u_num;
  if(u_num==num){
  	cout<<"\n******Congrats!!!******\nNumber guessed by you is correct.";
  }
  else if(u_num<num){
  	cout<<"Oops!!\nEnter number again greater than "<<u_num<<" : ";
  	goto label;
  }
  else if(u_num>num){
  	cout<<"Oops!!\nEnter number again lesser than "<<u_num<<" : ";
  	goto label;
  }
}
