#include "piece.h"
#include "raylib.h"

Texture2D piece_pawn_white[QTD_PAWN];
Vector2 pos_pawn_white[QTD_PAWN];

void setup_pieces(void){
    //white
    for(int i = 0 ; i < sizeof(piece_pawn_white) / sizeof(Texture2D); i++) {
        piece_pawn_white[i] = LoadTexture("../assets/SVG No shadow/pawn.png");
        pos_pawn_white[i] = (Vector2){(float)(POS_X_INITAL + i * DISTANCE_PIECE), POS_Y_INITAL + (6 * DISTANCE_PIECE)};
    }
}

void draw_pieces(void){
    for(int i = 0 ; i < sizeof(piece_pawn_white) / sizeof(Texture2D); i++) DrawTextureRec(piece_pawn_white[i], (Rectangle){0, 0, 40, 50}, pos_pawn_white[i], WHITE);
}

void unload_pieces(void){
    for(int i = 0 ; i < sizeof(piece_pawn_white) / sizeof(Texture2D); i++) UnloadTexture(piece_pawn_white[i]);
}