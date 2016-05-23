#include "QuadtreeNode.h"

QuadtreeNode::QuadtreeNode(float bl_x, float bl_z, float tr_x, float tr_z, List* objectList){	
	this->bl_x = bl_x; this->bl_z = bl_z; this->tr_x = tr_x; this->tr_z = tr_z;
	halfSize = (tr_x - bl_x)/2.0f;

	_2d = new Simple2D(bl_x, bl_z, tr_x, tr_z);
	
	this->objectList = objectList;

	SWChild = NULL;
	NWChild = NULL;
	NEChild = NULL;
	SEChild = NULL;

	build();
}

void QuadtreeNode::build(){
	List* intersecting = new List();
	struct List::Node* n = objectList->head;

	while(n != NULL){
		if(n->elem->_2d->isCollinding(_2d)){
			intersecting->add(n->elem);
		}
		n = n->next;
	}

	objectList = intersecting;

	if (objectList->size <= 1){

	}else{	
		SWChild=new QuadtreeNode(bl_x, bl_z, bl_x + halfSize, bl_z + halfSize, objectList);
		NWChild=new QuadtreeNode(bl_x, bl_z + halfSize, bl_x + halfSize, tr_z, objectList);
		NEChild=new QuadtreeNode(bl_x + halfSize, bl_z + halfSize, tr_x, tr_z, objectList);
		SEChild=new QuadtreeNode(bl_x + halfSize, bl_z, tr_x, bl_z + halfSize, objectList);
	}
}

void QuadtreeNode::draw(Simple2D* toCheck){
	if(!toCheck->isCollinding(_2d))
		return;

	if(SWChild == NULL){
		struct List::Node* n = objectList->head;
		while(n != NULL){
			n->elem->dibuja();
			n = n->next;
		}
	}else{
		SWChild->draw(toCheck); NWChild->draw(toCheck); NEChild->draw(toCheck); SEChild->draw(toCheck);
	}
}