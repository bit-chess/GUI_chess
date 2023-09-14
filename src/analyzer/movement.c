#include "movement.h"
#include "../data_board/board.h"
#include <string.h>
#include <stdio.h>

movement ans;
image_board initial_image;
image_board final_image;

int sequential_flag;

void build_analyzer(void){
    sequential_flag = 0;

    ans.x0 = -1;
    ans.xF = -1;
    ans.y0 = -1;
    ans.yF = -1;

    strcpy(ans.movement_, "XXXX");
}

int counter_piece(image_board board){
    int acc = 0;
    for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) if(board.board[i][j] != 'x') acc++;
    return acc;
}

void analyzer(void){
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(initial_image.board[i][j] != final_image.board[i][j]){
                if(initial_image.board[i][j] != 'x') {
                    ans.x0 = i;
                    ans.y0 = j;
                } else {
                    ans.xF = i;
                    ans.yF = j;
                }

            }
            
        }
    }
    sprintf(ans.movement_, "%c%d%c%d", letters[ans.x0], numbers[ans.y0], letters[ans.xF], numbers[ans.yF]);
}

void find_movement_FSM(image_board curr_board, int how_many_piece){
    switch (sequential_flag)
    {
        case 0:
            if(how_many_piece > counter_piece(curr_board)) sequential_flag = 1;
            else initial_image = curr_board;
            break;
        
        case 1:
            if(how_many_piece == counter_piece(curr_board)) sequential_flag = 2;
            break;

        case 2:
            final_image = curr_board;
            analyzer();
            sequential_flag = 0;
            break;
        
    }
}

movement get_answer(void){
    return ans;
}

int is_a_movement_equals(movement a, movement b){
    return (a.x0 == b.x0 && a.y0 == b.y0 && a.xF == b.xF && a.yF == b.yF && !strcmp(a.movement_, b.movement_));
}