/*
20/01/2018
LCC Abraham Saul Sansoval Meneses
Data Structures
STACK
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
struct node{	
	T value;
	node *next;
};

template <class T>
class Stack{
	
	node<T>* first;
	public:
	int size;
	Stack();//Contructor
	~Stack();//Destructor()
	void push(T);
	T pop(void);
	void print(void);
	void destroy(void);
};

template <class T>
Stack<T>::Stack(){
	first = NULL;
	size = 0;
}

template <class T>
void Stack<T>::push(T a){
	node<T> *p = new node<T>;
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

template <class T>
T Stack<T>::pop(void){
	node<T>* p = first;
	T a = p->value;
	first = p->next;
	
	delete p;
	size--;
	return a;
}

template <class T>
void Stack<T>::print(){
	node<T>* p = first;
	while(p){
		cout<<p->value;
		(p -> next != NULL)?cout<<", ":"";
		p = p->next;
	}
}

template <class T>
void Stack<T>::destroy(){
	node<T>* p = first;
	while(p){
		first = p->next;
		delete p;
		p = first;
	}
	size = 0;
}
template <class T>
Stack<T>::~Stack(void){
	this->destroy();
}



