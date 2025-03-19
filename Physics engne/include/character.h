#ifndef CHARACTER_H
#define CHARACTER_H

#include <physics.h>

typedef struct Character
{
	struct Body body;
};

int initCharacter(struct Character* character);
int drawCharacter(struct Body* characterBody);
int characterMovement(struct Body* characterBody, float deltaTime);


#endif // !