// This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "raylib.h"
#include "physics.h"
#include "character.h"

int main()
{
    InitWindow(800, 600, "Terraria");
    SetTargetFPS(120);

    struct Character player;
    initCharacter(&player);


    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        characterMovement(&player.body, dt);
        updatePosition(&player.body, dt);
		wallCollisions(&player.body);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawCharacter(&player.body);
        DrawText(TextFormat("CURRENT FPS: %i", (int)(1.0f / dt)), 20, 20, 20, RED);
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
