#include "raylib.h"
#include "character.h"
#include "physics.h"
#include "math.h"
#include "terrain.h"

int initCharacter(struct Character* character)
{
	character->body.position.x = WORLDWIDTH/2;
	character->body.position.y = 10000;
	character->body.velocity.x = 0;
	character->body.velocity.y = 0;
	character->body.height = 50;
	character->body.width = 20;
};

int drawCharacter(struct Body* characterBody)
{
	DrawRectangleV(characterBody->position, (Vector2) { characterBody->width, characterBody->height }, RED);
}

int characterMovement(struct Body* characterBody, float deltaTime)
{
	float maxVelocity = 4000.0f;
	float speed = 1600.0f;
	if (IsKeyDown(KEY_RIGHT) && characterBody->velocity.x < maxVelocity)
	{
		characterBody->velocity.x += speed * deltaTime;
	}
	if (IsKeyDown(KEY_LEFT) && characterBody->velocity.x > -(maxVelocity))
	{
		characterBody->velocity.x -= speed * deltaTime;
	}
	if (IsKeyDown(KEY_UP) && characterBody->velocity.x > -(maxVelocity))
	{
		characterBody->velocity.y -= speed * 3 * deltaTime;
	}
	//if (IsKeyPressed(KEY_SPACE))
	//{
	//	characterBody->velocity.x = fmodf((float)rand(), 5000.0f) - 2500.0f;
	//	characterBody->velocity.y = fmodf((float)rand(), 5000.0f) - 2500.0f;
	//}
}