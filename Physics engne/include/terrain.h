#ifndef TERRAIN_H
#define TERRAIN_H
#define WORLDWIDTH 10000
#define WORLDHEIGHT 2000
#define M_PI 3.14159265358979323846

#include <raylib.h>
#include <physics.h>

enum TileType
{
	AIR,
	DIRT,
	STONE,
	CAVE,
	ORE
};

int** getWorld();
float perlinGenerate1d(float x, int seed);
float perlinGenerate2d(float x, float y, int seed);
unsigned int hash(int x, int y, int seed);
Vector2 getRandomVector(int x, int y, int seed);
float dotProduct(Vector2 a, Vector2 b);
int shapeOverworld(int seed, int startHeight, int** world);
int** createWorld(int seed);
float interpolate(float a, float b, float x);
float smoothstep(float x);

#endif // !
