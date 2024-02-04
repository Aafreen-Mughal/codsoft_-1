#include<iostream>
using namespace std;
class node
{
	public:
		string data;
		bool status;
		node* next;
		node(){
			data="\0";
			next=NULL;
			status=false;
		}
		node(string d,bool s){
			data=d;
			next=NULL;
			status=s;
		}
};
class linkedList{
	public:
		node* head;
		linkedList(){
			head=NULL;
		}
		void insertion(string s,bool t){
			if(head==NULL){
				head=new node(s,t);
			}
			else{
				node* temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=new node(s,t);
			}
		}
		void deletion(string name){
			node* temp=head;
			node* prev=NULL;
			node* dlt;
			if(head->data==name){
				head=head->next;
				delete temp;
			}
			while(temp!=NULL&& temp->data!=name) {
			 prev=temp;
			 temp=temp->next;
			}	
			if(temp==NULL) {
			 cout<<"Task not found.\n";
		    	return;
			}
			if(prev==NULL) {
			 head=temp->next;
			}
			else{
			 prev->next=temp->next;
			}
			delete temp;
        }
		void display(){
			node*  n=head;
			cout<<"\nTASK NAMES\tSTATUS\n";
			while(n!=NULL){
				cout<<n->data<<"\t"<<n->status<<endl;
				n=n->next;
			}
			cout<<"\n";
		}
		void update(string n){
			node* temp=head;
			while(temp!=NULL){
				if(temp->data==n){
					temp->status=true;
				}
				temp=temp->next;
			}
		}
};
main(){
	linkedList l;
	int u=1;
	string name;
	bool status=false;
	while(u!=0){
		cout<<"\nEnter task name: ";
		cin>>name;
		l.insertion(name,status);
		cout<<"\nDo you want to add more tasks?\nEnter 1 for yes and 0 for No.\n";
		cin>>u;
	}
	l.display();
	cout<<"Do you want to remove a task?\nEnter 1 for yes and 0 for No.\n";
	cin>>u;
	if(u){
		cout<<"Enter task name to remove.\n";
		cin>>name;
		l.deletion(name);
		cout<<"\nTo do list after removing tasks.\n";
		l.display();
	}
	cout<<"Do you want to update the status of task.\nEnter 1 for yes and 0 for no.\n";
	cin>>u;
	if(u){
		cout<<"Enter task name: \n";
		cin>>name;
		l.update(name);
		l.display();
	}
}
