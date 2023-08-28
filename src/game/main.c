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

    char board[8][8];
    char initPosBlack[] = { 't', 'c', 'b', 'q', 'k', 'b', 'c', 't' };
    char initPosWhite[] = { 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T' };
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) board[i][j] = 'o';

    for(int i=0;i<8;i++) {
        board[1][i] = 'p';
        board[6][i] = 'P';
        board[7][i] = initPosWhite[i];
        board[0][i] = initPosBlack[i];
    }
    while (!WindowShouldClose()){
        // Update
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            draw_background();
            draw_pieces(board);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    unload_background();
    unload_pieces();

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}