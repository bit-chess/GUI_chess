#include "raylib.h"
#include "../scene/background.h"
#include "../scene/piece.h"
#include "../serial/serial_com.h"
#include "../analyzer/movement.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define HOW_MANY_PIECE 1

int main(void) {

    open_serial();
    setup_com();

    build_analyzer();

    movement curr_movement;
    char last_movement[110] = "";

    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight + 100, "bit-chess | Board Status");

    setup_background(screenWidth, screenHeight);
    setup_pieces();

    SetTargetFPS(60);

    char board[8][8];
    int turn = 1;

    while (!WindowShouldClose()){
        // Update
        //----------------------------------------------------------------------------------
        
        
        printf("\n-----------------------\n");
        image_board buf;
        int size_read = read_data(&buf); 
        if(size_read == sizeof(image_board)){
            for(int i=0;i<8;i++) {
                for(int j=0;j<8;j++){
                    board[i][j] = buf.board[i][j];
                    printf("%c", board[i][j]);
                }
                printf("\n");
            }
        } 
        printf("\n-----------------------\n");

        //analisa o último movimento
        find_movement_FSM(buf, HOW_MANY_PIECE);
        curr_movement = get_answer();
        if((curr_movement.x0 != curr_movement.xF || curr_movement.y0 != curr_movement.yF) && (curr_movement.x0 != -1 && curr_movement.xF != -1 && curr_movement.y0 != -1 && curr_movement.yF != -1 )) {
            sprintf(last_movement, "Last movement: %s (%d, %d) -> (%d, %d)\n", curr_movement.movement_, curr_movement.x0, curr_movement.y0, curr_movement.xF, curr_movement.yF);
            printf("last movement: %s (%d, %d) -> (%d, %d)\n", curr_movement.movement_, curr_movement.x0, curr_movement.y0, curr_movement.xF, curr_movement.yF);
        
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            draw_background();
            draw_pieces(board);
            
            DrawRectangle(0, screenHeight, screenWidth, screenHeight + 100, Fade(ORANGE, 0.5f));
            DrawRectangleLines(0, screenHeight, screenWidth, screenHeight + 100, ORANGE);
            DrawText(last_movement, 10, screenHeight + 10, 20, DARKGRAY);
            DrawText((turn) ? "White turn" : "Black turn", 10, screenHeight + 50, 20, DARKGRAY);
            
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