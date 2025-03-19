#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct Character
{
	Vector2 position;
	Vector2 velocity;
};

int drawCharacter(struct Character* character);
int characterMovement(struct Character* character, float deltaTime);
int	updatePosition(struct Character* character, float deltaTime);
float lerp(float a, float b, float t);


#endif // !
