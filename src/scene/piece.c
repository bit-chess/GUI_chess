#include "piece.h"
#include "raylib.h"

Texture2D piece_pawn_white[QTD_PAWN];
Vector2 pos_pawn_white[QTD_PAWN];

Texture2D piece_pawn_black[QTD_PAWN];
Vector2 pos_pawn_black[QTD_PAWN];

void setup_pieces(void){
    //white
    for(int i = 0 ; i < QTD_PAWN; i++) {
        piece_pawn_white[i] = LoadTexture("../assets/SVG No shadow/pawn.png");
        pos_pawn_white[i] = (Vector2){(float)(POS_X_INITAL + i * DISTANCE_PIECE), POS_Y_INITAL + (6 * DISTANCE_PIECE)};
    
        piece_pawn_black[i] = LoadTexture("../assets/SVG No shadow/pawn_b.png");
        pos_pawn_black[i] = (Vector2){(float)(POS_X_INITAL + i * DISTANCE_PIECE), POS_Y_INITAL + (1 * DISTANCE_PIECE)};

    }
}

void draw_pieces(void){
    for(int i = 0 ; i < QTD_PAWN; i++) {
        DrawTextureRec(piece_pawn_white[i], (Rectangle){0, 0, 40, 50}, pos_pawn_white[i], WHITE);
        DrawTextureRec(piece_pawn_black[i], (Rectangle){0, 0, 40, 50}, pos_pawn_black[i], WHITE);
    }
}

void unload_pieces(void){
    for(int i = 0 ; i < QTD_PAWN; i++) {
        UnloadTexture(piece_pawn_white[i]);
        UnloadTexture(piece_pawn_black[i]);
    }
}