#ifndef PHYSICS_H
#define PHYSICS_H

#include <raylib.h>
// A struct to apply physics to all enteties
struct Body {
    Vector2 position;
    Vector2 velocity;
	float width;
	float height;
};

int	updatePosition(struct Body* body, float deltaTime);
float lerp(float a, float b, float t);
int wallCollisions(struct Body* body);

#endif // !

