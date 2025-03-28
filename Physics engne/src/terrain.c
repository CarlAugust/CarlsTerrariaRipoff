#include <terrain.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Plan for terrain generation
/*
1. Generate 1d perlin noise for overworld shape aka what is overworld and what is sky
2. Generate 1d perlin noise for undeground, aka when dirt and when stone
3. Generate 2d perlin noise for caves which i will simply map over the world
4. Generate 2d perlin noise for ores and such, with smaller volumes for each type of ore

Perhaps more to make it more natural later i will see...
...

...

*/

int** getWorld()
{
	int** world = malloc(WORLDWIDTH * sizeof(int*));
	if (world == NULL)
	{
		printf("Error when allocating\n");
		exit(1);
	}
	for (int i = 0; i < WORLDWIDTH; i++)
	{
		world[i] = malloc(WORLDHEIGHT * sizeof(int));
		if (world[i] == NULL)
		{
			printf("Error when allocating\n");
			exit(1);
		}
		for (int j = 0; j < WORLDHEIGHT; j++)
		{
			world[i][j] = AIR;
		}
	}
	return world;
}

// Might be used idk
float dotProduct(Vector2 a, Vector2 b)
{
	return a.x * b.x + a.y * b.y;
}

// x, y and seed in case i need higher dimensions than 2d
// Creds: Polygonz2007
float getRandomVector(int x, int y, int seed)
{
	x += y * 100;
	x -= seed * 827;

	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = (x >> 16) ^ x;

	double r = (float)x / 2147483648.0f; // to float, 0 - 1

	return r * r * (3.0f - 2.0f * r);

}

float perlinGenerate1d(int x, int seed)
{
	float rmix = fmodf(x, 1.0f);

	float A = getRandomVector(x, 0, seed);
	float B = getRandomVector(x + 1, 0, seed);


	// Interpolate
	float result = lerp(A, B, rmix);

	// Clamp
	if (result < -1.0f)
	{
		result = -1.0f;
	}
	else if (result > 1.0f)
	{
		result = 1.0f;
	}

	return result;
}

float perlinGenerate2d(int x, int y, int seed)
{
	float rmix = fmodf(x, 1.0f);
	float rmiy = fmodf(y, 1.0f);

	float A = getRandomVector(x, y, 0);
	float B = getRandomVector(x, y + 1, 0);
	float C = getRandomVector(x + 1, y, 0);
	float D = getRandomVector(x + 1, y + 1, 0);

	// Interpolate
	float AC = lerp(A, C, rmix);
	float BD = lerp(B, D, rmix);

	float result = lerp(AC, BD, rmiy);

	// Clamp
	if (result < -1.0f)
	{
		result = -1.0f;
	}
	else if (result > 1.0f)
	{
		result = 1.0f;
	}

	return result;
}

int shapeOverworld(int seed, int startHeight, int** world)
{
	for (int x = 0; x < WORLDWIDTH; x++)
	{
		float height = floor(perlinGenerate1d(x, seed) * 20);
		for (int y = 0; y < height + startHeight; y++)
		{
			world[x][y] = AIR;
		}
		for (int y = height + startHeight; y < WORLDHEIGHT; y++)
		{
			world[x][y] = DIRT;
		}
	}
}

int** createWorld(int seed)
{
	printf("STARTING GENERATION\n");
	int** world = getWorld();
	int count = 0;

	printf("GOT WORLD\n");
	shapeOverworld(seed, 1000, world);
	printf("FINISHED GENERATION\n");

	return world;
}





