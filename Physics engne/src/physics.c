#include "physics.h"
#include <raylib.h>
#include <character.h>

float lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}

int	updatePosition(struct Character* character, float deltaTime)
{
	float gravity = 500.0f;
	character->position.x += character->velocity.x * deltaTime;
	character->position.y += character->velocity.y * deltaTime;

	float damping = 0.9f;
	character->velocity.x = lerp(character->velocity.x, 0, damping * deltaTime);
	character->velocity.y = lerp(character->velocity.y, 0, damping * deltaTime);

	character->velocity.x *= 1.0f - 3.0f * deltaTime;
	character->velocity.y *= 1.0f - 0.5f * deltaTime;

	character->velocity.y += gravity * deltaTime;
}

int wallCollisions(struct Character* character)
{
	if (character->position.x < 0)
	{
		character->position.x = 0;
		character->velocity.x = 0;
	}
	if (character->position.x > 800 - character->playerWidth)
	{
		character->position.x = 800 - character->playerWidth;
		character->velocity.x = 0;
	}
	if (character->position.y < 0)
	{
		character->position.y = 0;
		character->velocity.y = 0;
	}
	if (character->position.y > 600 - character->playerHeight)
	{
		character->position.y = 600 - character->playerHeight;
		character->velocity.y = 0;
	}
}