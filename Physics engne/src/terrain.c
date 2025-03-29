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

Vector2 vectorSubtraction(Vector2 a, Vector2 b)
{
	return (Vector2) { a.x - b.x, a.y - b.y };
}

// x, y and seed in case i need higher dimensions than 2d
// Creds: Polygonz2007
Vector2 getRandomVector(int x, int y, int seed)
{
	// Get random normalised vector based off location of point
	srand((x * 8754327 + y * x * 298332 + y * 339812) & 34271);
	float angle = (rand() & 53554) + seed;

	return (Vector2) { cosf(angle), sinf(angle) };

}

float perlinGenerate1d(float x, int seed)
{
	int xi = floor(x);
	float rmix = x - xi;

	Vector2 A = (Vector2){ x, 0 };
	Vector2 B = (Vector2){ x + 1, 0 };

	float DA = dotProduct(A, getRandomVector(xi, 0, seed));
	float DB = dotProduct(B, getRandomVector(xi, 0, seed));

	float result = lerp(DA, DB, rmix);

	return result;
}

float perlinGenerate1dOctaves(int x, int seed, int octaves, float persistence)
{
	float total = 0.0f;
	float maxAmplitude = 400.0f;
	float amplitude = 1.0f;
	float frequency = 1.0f;

	for (int i = 0; i < octaves; i++)
	{
		float noise = perlinGenerate1d(x * frequency, seed);
		total += noise * amplitude;
		maxAmplitude += amplitude;
		amplitude *= persistence;
		frequency *= 2.0f;
	}

	// Normalize the result to keep values in range [-1, 1]
	return total / maxAmplitude;
}

float sample_perlin2d(float x, float y) {
	//// Vector pos
	//Vector2 pos = { x, y };

	//// Int and remainer pos
	//float fix = floorf(x), fiy = floorf(y);
	//int ix = (int)floor(x), iy = (int)floor(y);
	//float u = fmodf(x - (float)ix, 1.0f), v = fmodf(y - (float)iy, 1.0f);

	//// Corners
	//Vector2 c1 = { fix, fiy };
	//Vector2 c2 = { fix + 1, fiy };
	//Vector2 c3 = { fix, fiy + 1 };
	//Vector2 c4 = { fix + 1, fiy + 1 };

	//// Find vectors to grid points
	//Vector2 o1 = Vector2Subtract(pos, (Vector2) { fix, fiy });
	//Vector2 o2 = Vector2Subtract(pos, (Vector2) { fix + 1, fiy });
	//Vector2 o3 = Vector2Subtract(pos, (Vector2) { fix, fiy + 1 });
	//Vector2 o4 = Vector2Subtract(pos, (Vector2) { fix + 1, fiy + 1 });

	//float d1 = dotProduct(o1, getRandomVector(ix, iy));
	//float d2 = dotProduct(o2, getRandomVector(ix + 1, iy));
	//float d3 = dotProduct(o3, getRandomVector(ix, iy + 1));
	//float d4 = dotProduct(o4, getRandomVector(ix + 1, iy + 1));

	//float top = Lerp(d1, d2, fade(u));
	//float bottom = Lerp(d3, d4, fade(u));

	//return 0.5f + Lerp(top, bottom, fade(v)) * 0.5f;
}


int shapeOverworld(int seed, int startHeight, int** world)
{
	for (int x = 0; x < WORLDWIDTH; x++)
	{
		float height = perlinGenerate1dOctaves(x, seed, 8, 0.5f);
		printf("%f\n", height);
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





