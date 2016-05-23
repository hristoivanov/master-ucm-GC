#ifndef _QuadtreeNode_H_
#define _QuadtreeNode_H_

#include <math.h>
#include "PuntoVector3D.h"
#include "Objeto3D.h"
#include "Simple2D.h"
#include "List.h"
#include <GL/freeglut.h>

class QuadtreeNode {
private:
	float bl_x, bl_z, tr_x, tr_z;
	float halfSize;

	Simple2D* _2d;
	QuadtreeNode *SWChild, *NWChild, *NEChild, *SEChild;
	List* objectList;
	void build();
public:
	QuadtreeNode(float bl_x, float bl_z, float tr_x, float tr_z, List* objectList);
	void draw(Simple2D* toCheck);
};
#endif