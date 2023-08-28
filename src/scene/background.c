#include "raylib.h"
#include "background.h"

Texture2D image_board;

Rectangle recSrc;
Rectangle recDest;
Vector2 origin;

void setup_background(int w, int h){

    image_board = LoadTexture("../assets/board.png"); 

    recSrc = (Rectangle){0, 0, (float)image_board.width, (float)image_board.height};
    recDest = (Rectangle){0, 0, (float)w, (float)h};
    origin = (Vector2){0, 0};
}

void draw_background(void){
    DrawTexturePro(image_board, recSrc, recDest, origin, 0, WHITE);;
}

void unload_background(void){
    UnloadTexture(image_board);   
}