#include "raylib.h"
#include "../scene/background.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "bit-chess");

    setup_background(screenWidth, screenHeight);

    SetTargetFPS(60);

    while (!WindowShouldClose()){
        // Update
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            draw_background();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    unload_background();

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}