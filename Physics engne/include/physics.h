#ifndef PHYSICS_H
#define PHYSICS_H

int	updatePosition(struct Character* character, float deltaTime);
float lerp(float a, float b, float t);
int wallCollisions(struct Character* character);

#endif // !

