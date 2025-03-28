#include "physics.h"
#include <raylib.h>
#include <character.h>
#include <terrain.h>

float lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}

int	updatePosition(struct Body* body, float deltaTime)
{
	float gravity = 2000.0f;
	body->position.x += body->velocity.x * deltaTime;
	body->position.y += body->velocity.y * deltaTime;

	float damping = 0.95f;
	body->velocity.x = lerp(body->velocity.x, 0, damping * deltaTime);
	body->velocity.y = lerp(body->velocity.y, 0, damping * deltaTime);

	body->velocity.x *= 1.0f - 3.0f * deltaTime;
	body->velocity.y *= 1.0f - 0.5f * deltaTime;

	body->velocity.y += gravity * deltaTime;
}

int wallCollisions(struct Body* body)
{
	if (body->position.x <= 0)
	{
		body->position.x = 0;
		body->velocity.x = 0;
	}
	if (body->position.x > WORLDWIDTH * 10 - body->width)
	{
		body->position.x = WORLDWIDTH * 10 - body->width;
		body->velocity.x = 0;
	}
	if (body->position.y < 0)
	{
		body->position.y = 0;
		body->velocity.y = 0;
	}
	if (body->position.y > WORLDHEIGHT * 10 - body->height)
	{
		body->position.y = WORLDHEIGHT * 10 - body->height;
		body->velocity.y = 0;
	}
}