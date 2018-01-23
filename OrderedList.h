/*
21/01/2018
LCC Abraham Saul Sansoval Meneses
Data Structures
ORDERED LIST
*/


#include <iostream>
using namespace std;

template <class T>
struct node{
	T value;
	node *next;
};

enum Where {VOID, FIRST, MIDDLE, END};
enum Found {NO, YES};
template <class T>
class OrderedList{

	int size;
	node<T> *first, *previous;
	Found found;
	Where where;
	public:
		OrderedList();
		~OrderedList();
		void search(T);
		void insert(T);
		int remove(T);
		void print(void);
		void destroy(void);
};

template<class T>
OrderedList<T>::OrderedList(void){
	size = 0;
	first = NULL;
	previous = NULL;
	found = NO;
	where = VOID;
}

template <class T>
OrderedList<T>::~OrderedList(void){
	this->destroy();
}

template <class T>
void OrderedList<T>::search(T a){
	node<T> *p = first;
	
	if(!p){
		found = NO;
		where = VOID;
		return;
	}
	
	while(p){
		if(p->value == a || p->value > a){
			found = (p->value == a)? YES: NO;
			if(p == first){
				where = FIRST;
			}
			else if(p->next == NULL){
				where = END;
			}
			else{
				where = MIDDLE;
			}
			return;
		}
		else if(p->value < a){
			found = NO;
			previous = p;
			p = p->next;
		}
	}
	found = NO;
	where = END;
}

template <class T>
void OrderedList<T>::insert(T a){

	node<T> *p = new node<T>;
	p->value = a;
	search(a);

	if(where == VOID){
		p->next = NULL;
		first = p; 
	}
	else if(where == FIRST){
		p->next = first;
		first = p;
	}
	else{
		p->next = previous->next;
		previous->next = p;
	}
	size++;
}

template <class T>
int OrderedList<T>::remove(T a){
	node<T> *p = new node<T>;
	search(a);
	if(found == NO){
		return 0;
	}
	
	if(where == FIRST){
		p = first;
		first = first->next;
	}
	else if(where == MIDDLE){
		p = previous->next;
		previous->next = p->next;
	}
	else{
		p = previous->next;
		previous->next = NULL;
	}
	
	size--;
	return 1;
}

template <class T>
void OrderedList<T>::destroy(){
	node<T>* p = first;
	while(p){
		first = p->next;
		delete p;
		p = first;
	}
	size = 0;
}

template <class T>
void OrderedList<T>::print(){
	node<T> *p = first;
	while(p){
		cout<<p->value<<endl;
		p = p->next;
	}
}




