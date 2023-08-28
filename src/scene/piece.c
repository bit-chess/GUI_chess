#include "piece.h"
#include "raylib.h"

Texture2D piece_pawn_white, piece_pawn_black, piece_bishop_black, piece_king_black, piece_rook_white, 
        piece_knight_black, piece_queen_black, piece_rook_black, piece_bishop_white, 
        piece_king_white, piece_knight_white, piece_queen_white;

Vector2 allof_pos[8][8];

void setup_pieces(void){
    piece_pawn_white = LoadTexture("../assets/SVG No shadow/pawn.png");
    piece_pawn_black = LoadTexture("../assets/SVG No shadow/pawn_b.png");
    piece_bishop_black = LoadTexture("../assets/SVG No shadow/bishop_b.png");
    piece_king_black = LoadTexture("../assets/SVG No shadow/king_b.png");
    piece_rook_white = LoadTexture("../assets/SVG No shadow/rook_w.png");
    piece_knight_black = LoadTexture("../assets/SVG No shadow/knight_b.png");
    piece_queen_black = LoadTexture("../assets/SVG No shadow/queen_b.png");
    piece_rook_black = LoadTexture("../assets/SVG No shadow/rook_b.png");
    piece_bishop_white = LoadTexture("../assets/SVG No shadow/bishop_w.png");
    piece_king_white = LoadTexture("../assets/SVG No shadow/king_w.png");
    piece_knight_white = LoadTexture("../assets/SVG No shadow/knight_w.png");
    piece_queen_white = LoadTexture("../assets/SVG No shadow/queen_w.png");

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
                case 'b':
                    DrawTextureRec(piece_bishop_black, (Rectangle){0, 0, 45, 50}, allof_pos[i][j], WHITE);
                    break;
                case 'k':
                    DrawTextureRec(piece_king_black, (Rectangle){0, 0, 50, 50}, allof_pos[i][j], WHITE);
                    break;
                case 'T':
                    DrawTextureRec(piece_rook_white, (Rectangle){0, 0, 47, 50}, allof_pos[i][j], WHITE);
                    break;
                case 'c':
                    DrawTextureRec(piece_knight_black, (Rectangle){0, 0, 45, 50}, allof_pos[i][j], WHITE);
                    break;
                case 'q':
                    DrawTextureRec(piece_queen_black, (Rectangle){0, 0, 55, 50}, allof_pos[i][j], WHITE);
                    break;
                case 't':
                    DrawTextureRec(piece_rook_black, (Rectangle){0, 0, 47, 50}, allof_pos[i][j], WHITE);
                    break;
                case 'B':
                    DrawTextureRec(piece_bishop_white, (Rectangle){0, 0, 45, 50}, allof_pos[i][j], WHITE);
                    break;
                case 'K':
                    DrawTextureRec(piece_king_white, (Rectangle){0, 0, 50, 50}, allof_pos[i][j], WHITE);
                    break;
                case 'C':
                    DrawTextureRec(piece_knight_white, (Rectangle){0, 0, 45, 50}, allof_pos[i][j], WHITE);
                    break;
                case 'Q':
                    DrawTextureRec(piece_queen_white, (Rectangle){0, 0, 55, 50}, allof_pos[i][j], WHITE);
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
    UnloadTexture(piece_bishop_black);
    UnloadTexture(piece_king_black);
    UnloadTexture(piece_rook_white);
    UnloadTexture(piece_knight_black);
    UnloadTexture(piece_queen_black);
    UnloadTexture(piece_rook_black);
    UnloadTexture(piece_bishop_white);
    UnloadTexture(piece_king_white);
    UnloadTexture(piece_knight_white);
    UnloadTexture(piece_queen_white);
}