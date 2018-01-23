/*
20/01/2018
LCC Abraham Saul Sansoval Meneses
Data Structures
QUEUE
*/

#include <iostream>
using namespace std;

template <class T>
struct node{
	node *next;
	T value;
};

template <class T>
class Queue{
	
	node<T> *first, *last;
	public:
		int size;
		Queue();
	    ~Queue();
	    void add(T);
	    T out(void);
	    void print(void);
	    void destroy(void);
};

template <class T>
Queue<T>::Queue(){
	first = NULL;
	last = NULL;
	size = 0;
}

template <class T>
Queue<T>::~Queue(){
	this->destroy();
}

template <class T>
void Queue<T>::destroy(){
	node<T>* p = first;
	while(p){
		first = p->next;
		delete p;
		p = first;
	}
	size = 0;
}

template <class T>
void Queue<T>::add(T a){
	node<T>* p = new node<T>;
	p->value = a;
	p->next = NULL;
	if(first == NULL){
		first = p;
		last = p;
	}
	else{
		last->next = p;
		last = last->next;
	}
	size++;
}

template <class T>
T Queue<T>::out(void){
	node<T> *p;
	int a;
	if(first != NULL){
		p = first;
		first = first->next;
		a = p->value;
		delete p;
		size--;
		return a;
	}
	return -1;
}

template <class T>
void Queue<T>::print(void){
	node<T> *p = first;
	int n = 0;
	while(p){
		cout<<p->value;
		(p -> next != NULL)?cout<<", ":"";
		p = p->next;
	}
}

