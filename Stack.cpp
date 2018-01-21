/*
20/01/2018
LCC Abraham Saul Sansoval Meneses
Data Structures
ClASS STACK
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{	
	int value;
	node *next;
};

class Stack{
	
	node* first;
	public:
	int size;
	Stack();//Contructor
	~Stack();//Destructor()
	void push(int);
	int pop(void);
	void print(void);
	void destroy(void);
};

Stack::Stack(){
	first = NULL;
	size = 0;
}

void Stack::push(int a){
	node *p = new node;
	p->value = a;
	p->next = NULL;
	
	if(first == NULL){
		first = p;
	}
	else{
		p->next = first;
		first = p;		
	}
	size++;
}

int Stack::pop(void){
	node* p = first;
	int a = p->value;
	first = p->next;
	
	delete p;
	size--;
	return a;
}

void Stack::print(){
	node* p = first;
	int n = 0;
	while(p){
		cout<<p->value;
		(p -> next != NULL)?cout<<", ":"";
		p = p->next;
	}
}

void Stack::destroy(){
	node* p = first;
	while(p){
		first = p->next;
		delete p;
		p = first;
	}
	size = 0;
}

Stack::~Stack(void){
	this->destroy();
}

int main(int argc, char *argv[]){
	
	Stack stack;
	for(int  i = 0; i < 100; i++)
		stack.push(rand() % 100);
	stack.print();
	stack.destroy();
	cout<<endl<<stack.size;
	
	return 0;
}


