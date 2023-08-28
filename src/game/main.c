#include "raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "bit-chess");

    Texture2D image_board = LoadTexture("../../assets/board.png");        // Texture loading

    Rectangle recSrc = {0, 0, image_board.width, image_board.height};
    Rectangle recDest = {0, 0, screenWidth, screenHeight};
    Vector2 origin = {0, 0};

    SetTargetFPS(60);

    while (!WindowShouldClose()){
        // Update
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexturePro(image_board, recSrc, recDest, origin, 0, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(image_board);        // Texture unloading

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}