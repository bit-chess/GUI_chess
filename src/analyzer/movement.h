#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../data_board/board.h"

typedef struct{
    int x0, xF, y0, yF;
    char movement_[5];
}movement;

const char letters[] = {'A','B','C','D','E', 'F', 'G', 'H'};
const int numbers[] = {8,7,6,5,4,3,2,1}; 

void build_analyzer(void);
int counter_piece(image_board board);
int analyzer(void);
void find_movement_FSM(image_board curr_board, int how_many_piece);
movement get_answer(void);
int is_a_movement_equals(movement a, movement b);
char get_letter(int x);
int number_letter(int x);

#endif