#ifndef SERIAL_COM_H
#define SERIAL_COM_H

#include <stdio.h>
#include "../data_board/board.h"

#define PORT "/dev/ttyACM0"

void open_serial(void);
void setup_com(void);
int read_data(image_board *buffer);
void close_serial_connection(void);

#endif