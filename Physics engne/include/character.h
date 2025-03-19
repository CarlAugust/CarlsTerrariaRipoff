#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct Character
{
	Vector2 position;
	Vector2 velocity;
	int playerHeight;
	int playerWidth;
};

int drawCharacter(struct Character* character);
int characterMovement(struct Character* character, float deltaTime);


#endif // !