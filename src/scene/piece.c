#include "piece.h"
#include "raylib.h"

Texture2D piece_pawn_white;
Texture2D piece_pawn_black;

Vector2 allof_pos[8][8];

void setup_pieces(void){
    piece_pawn_white = LoadTexture("../assets/SVG No shadow/pawn.png");
    piece_pawn_black = LoadTexture("../assets/SVG No shadow/pawn_b.png");

    for(int i = 0 ; i < 8; i++) {
        for(int j = 0 ; j < 8; j++) {
            allof_pos[i][j] = (Vector2){(float)(POS_X_INITAL + j * DISTANCE_PIECE), (float)(POS_Y_INITAL + (i * DISTANCE_PIECE))};
        } 
    }
}

void draw_pieces(char board[8][8]){
    for(int i = 0 ; i < 8; i++) {
        for(int j = 0 ; j < 8; j++) {
            switch (board[i][j]){
                case 'P':
                    DrawTextureRec(piece_pawn_white, (Rectangle){0, 0, 40, 50}, allof_pos[i][j], WHITE);
                    break;
                case 'p':
                    DrawTextureRec(piece_pawn_black, (Rectangle){0, 0, 40, 50}, allof_pos[i][j], WHITE);
                    break;
                
                default:
                    break;
            }
        } 
    }
}

void unload_pieces(void){
    UnloadTexture(piece_pawn_white);
    UnloadTexture(piece_pawn_black);
}