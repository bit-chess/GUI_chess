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

int analyzer(void){
    int analyser[8][8];
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            analyser[i][j] = initial_image.board[i][j] ^ final_image.board[i][j];          
        }
    }
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(analyser[i][j] && initial_image.board[i][j] != 'x'){
                ans.x0 = i;
                ans.y0 = j;
            }
            else if(analyser[i][j] && final_image.board[i][j] != 'x'){
                ans.xF = i;
                ans.yF = j;
            }     
        }
    }
    

    if(ans.x0 == ans.xF && ans.y0 == ans.yF && (ans.x0 != -1 || ans.y0 != -1 || ans.xF != -1 || ans.yF != -1)) return 0;
    sprintf(ans.movement_, "%c%d%c%d", get_letter(ans.y0), number_letter(ans.x0), get_letter(ans.yF), number_letter(ans.xF));
    return 1;
}

void find_movement_FSM(image_board curr_board, int how_many_piece){
    switch (sequential_flag)
    {
        case 0:
            if(how_many_piece - 1 == counter_piece(curr_board)) sequential_flag = 1;    
            else initial_image = curr_board;
            break;
        
        case 1:
            if(how_many_piece == counter_piece(curr_board)) sequential_flag = 2;
            else if(how_many_piece - 2 == counter_piece(curr_board)) sequential_flag = 3;  
            break;

        case 2:
            final_image = curr_board;
            if(analyzer()) sequential_flag = 0;
            break;
        
        case 3:
            if(how_many_piece - 1 == counter_piece(curr_board)) sequential_flag = 2;
            break;

    }
}

movement get_answer(void){
    return ans;
}

int is_a_movement_equals(movement a, movement b){
    return (a.x0 == b.x0 && a.y0 == b.y0 && a.xF == b.xF && a.yF == b.yF && !strcmp(a.movement_, b.movement_));
}

char get_letter(int x){
    if(x != -1) return letters[x];
    return 'X';
}
int number_letter(int x){
    if(x != -1) return numbers[x];
    return 9;
}