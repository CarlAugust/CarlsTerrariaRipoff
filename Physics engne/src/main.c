// This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "raylib.h"
#include "physics.h"
#include "terrain.h"
#include "character.h"
#include "math.h"
#include "universal.h"

int main()
{
	int screenWidth = 800;
	int screenHeight = 600;

    //Init world
    int** world = createWorld(1000);

    InitWindow(screenWidth, screenHeight, "Terraria");
    SetTargetFPS(60);

    // Init player
    struct Character player;
    initCharacter(&player);

    // Init camera
    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.body.position.x + 20.0f, player.body.position.y + 20.0f };
    camera.offset = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();


        // Game
        characterMovement(&player.body, dt);
        updatePosition(&player.body, dt);
		wallCollisions(&player.body);
        
        camera.target = (Vector2){ player.body.position.x + 20.0f, player.body.position.y + 20.0f };

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(camera);
        DrawRectangle(0, 0, 100, 100, GREEN);
        DrawRectangle(-screenWidth, screenHeight, screenWidth * 2, screenHeight, BLUE);

        int playerTileX = (int)floor(player.body.position.x / TILESIZE);
        int playerTileY = (int)floor(player.body.position.y / TILESIZE);

        int renderDistance = 50;

        for (int x = playerTileX - renderDistance; x <= playerTileX + renderDistance; x++)
        {
            for (int y = playerTileY - renderDistance; y <= playerTileY + renderDistance; y++)
            {
                if (x >= 0 && x < WORLDWIDTH && y >= 0 && y < WORLDHEIGHT)
                {
                    Color color = BLUE;
                    if (world[x][y] == DIRT)
                    {
                        color = BROWN;
                    }
                    DrawRectangle(x * TILESIZE, y * TILESIZE, TILESIZE, TILESIZE, color);
                }
            }
        }

        drawCharacter(&player.body);
        EndMode2D();

        DrawText(TextFormat("CURRENT FPS: %i", (int)(1.0f / dt)), 20, 20, 20, RED);
        DrawText(TextFormat("CURRENT POSITION: x, %f y, %f", player.body.position.x, player.body.position.y), 20, 40, 20, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
