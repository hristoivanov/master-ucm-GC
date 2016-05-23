#include "List.h"

List::List(){
	head = NULL;
	size = 0;
}

List::~List(){
	while(head != NULL){
		Node* n = head->next;
		delete head;
		head = n;
	}
}

void List::add(Objeto3D* obj){
	Node* n = new Node;
	n->elem = obj;
	n->next = head;
	head = n;
	size += 1;
}

