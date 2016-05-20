#include "Simple2D.h"


Simple2D::Simple2D(PuntoVector3D** puntos, int leght) {
	bl = puntos[0]->clonar();
	tr = puntos[0]->clonar();

	for (int i = 1; i < leght; i++){
		if (puntos[i]->getX() < bl->getX())
			bl->setX(puntos[i]->getX());
		if (puntos[i]->getX() > tr->getX())
			tr->setX(puntos[i]->getX());
		if (puntos[i]->getZ() < bl->getZ())
			bl->setZ(puntos[i]->getZ());
		if (puntos[i]->getZ() > tr->getZ())
			tr->setZ(puntos[i]->getZ());
	}
}

Simple2D::Simple2D(PuntoVector3D* center, float radius){
	bl = new PuntoVector3D(center->getX() - radius, 0.0f, center->getZ() - radius, 1.0f);
	tr = new PuntoVector3D(center->getX() + radius, 0.0f, center->getZ() + radius, 1.0f);
}


bool Simple2D::isCollinding(Simple2D* other){
	return !(
		other->bl->getZ() > tr->getZ() ||	// other->bottom >  mine->top
		other->tr->getZ() < bl->getZ() ||	// other->top    <  mine->bottom
		other->bl->getX() > tr->getX() ||	// other->left   >  mine->right
		other->tr->getX() < bl->getX()		// other->right  <  mine->left
	);
}