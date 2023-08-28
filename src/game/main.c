#include "raylib.h"
#include "../scene/background.h"
#include "../scene/piece.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "bit-chess");

    setup_background(screenWidth, screenHeight);
    setup_pieces();

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
            draw_pieces();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    unload_background();
    unload_pieces();

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}