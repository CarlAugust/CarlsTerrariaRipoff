// Physics engne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "raylib.h"
#include "physics.h"
#include "character.h"

int main()
{
    InitWindow(800, 600, "Terraria");

    struct Character player;
    player.position.x = 400.0f;
    player.position.y = 400.0f;
    player.velocity.x = 0.0f;
    player.velocity.y = 0.0f;


    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        characterMovement(&player, dt);
        updatePosition(&player, dt);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawCharacter(&player);
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
