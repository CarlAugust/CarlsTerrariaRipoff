#include <terrain.h>
#include <stdio.h>
#include <stdlib.h>

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
	}
	return world;
}

