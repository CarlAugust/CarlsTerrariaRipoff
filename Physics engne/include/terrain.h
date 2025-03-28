#ifndef TERRAIN_H
#define TERRAIN_H
#define WORLDWIDTH 10000
#define WORLDHEIGHT 2000

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
float perlinGenerate1d(int x, int seed);
float perlinGenerate2d(int x, int y, int seed);
float getRandomVector(int x, int y, int seed);
float dotProduct(Vector2 a, Vector2 b);
int shapeOverworld(int seed, int startHeight, int** world);
int** createWorld(int seed);

#endif // !
