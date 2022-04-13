#ifndef Ball_HEADER
#define Ball_HEADER

#include "GameObject.h"

class Ball : public GameObject
{
public:
	void move(double deltaTime);
};

#endif
