#ifndef _List_H_
#define _List_H_

#include <math.h>
#include "Objeto3D.h"
#include <GL/freeglut.h>

class List {
public:
	struct Node {
		Objeto3D* elem;
		Node* next;
	};

	Node* head;
	int size;

	List();
	~List();
	void add(Objeto3D* obj);
};
#endif