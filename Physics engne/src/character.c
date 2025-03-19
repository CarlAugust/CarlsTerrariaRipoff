#include "raylib.h"
#include "character.h"
#include "math.h"

int drawCharacter(struct Character* character)
{
	DrawRectangle(character->position.x, character->position.y, 10, 10, RED);
}

int characterMovement(struct Character *character, float deltaTime)
{
	float maxVelocity = 4000.0f;
	float speed = 1600.0f;
	if (IsKeyDown(KEY_RIGHT) && character->velocity.x < maxVelocity)
	{
		character->velocity.x += speed * deltaTime;
	}
	if (IsKeyDown(KEY_LEFT) && character->velocity.x > -(maxVelocity))
	{
		character->velocity.x -= speed * deltaTime;
	}
	if (IsKeyDown(KEY_UP) && character->velocity.y > -(maxVelocity))
	{
		character->velocity.y -= speed * deltaTime;
	}
	if (IsKeyDown(KEY_DOWN) && character->velocity.y < (maxVelocity))
	{
		character->velocity.y += speed * deltaTime;
	}
	//if (IsKeyPressed(KEY_SPACE))
	//{
	//	character->velocity.x = fmodf((float)rand(), 5000.0f) - 2500.0f;
	//	character->velocity.y = fmodf((float)rand(), 5000.0f) - 2500.0f;
	//}
}