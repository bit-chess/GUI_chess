#include "raylib.h"
#include "../scene/background.h"
#include "../scene/piece.h"
#include "../serial/serial_com.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(void) {

    open_serial();
    setup_com();

    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "bit-chess | Board Status");

    setup_background(screenWidth, screenHeight);
    setup_pieces();

    SetTargetFPS(60);

    char board[8][8];

    while (!WindowShouldClose()){
        // Update
        //----------------------------------------------------------------------------------
        printf("\n-----------------\n");
        image_board buf;
        int n = read_data(&buf); 
        if(n == sizeof(image_board)){
            for(int i=0;i<8;i++) {
                for(int j=0;j<8;j++){
                    board[i][j] = buf.board[i][j];
                    printf("%c", board[i][j]);
                }
                printf("\n");
            }
        } 
        printf("\n-----------------\n");
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

    close_serial_connection();

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}