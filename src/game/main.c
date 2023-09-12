#include "raylib.h"
#include "../scene/background.h"
#include "../scene/piece.h"
#include <stdio.h>
#include <fcntl.h> 
#include <termios.h> 
#include <unistd.h>
#include <string.h>
#include <stdint.h>

typedef struct{
    char board[8][8];
}image_board;

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "bit-chess | Board Status");

    setup_background(screenWidth, screenHeight);
    setup_pieces();

    SetTargetFPS(60);

    int serialPort = open("/dev/ttyACM0", O_RDWR | O_NOCTTY); 
    if (serialPort < 0) { 
        printf("falhou\n"); 
        return -1; 
    } 

    struct termios serialOptions;
    tcgetattr(serialPort, &serialOptions);

    // Configure as opções da porta serial
    cfsetispeed(&serialOptions, B115200); // Taxa de baud de entrada
    cfsetospeed(&serialOptions, B115200); // Taxa de baud de saída
    serialOptions.c_cflag |= (CLOCAL | CREAD); // Habilitar leitura e ignorar controle de modem
    serialOptions.c_cflag &= ~PARENB; // Desabilitar paridade
    serialOptions.c_cflag &= ~CSTOPB; // 1 stop bit
    serialOptions.c_cflag &= ~CSIZE; // Limpar bits de tamanho de caractere
    serialOptions.c_cflag |= CS8; // Configurar para 8 bits de dados
    tcsetattr(serialPort, TCSANOW, &serialOptions);

    char board[8][8];
    char initPosBlack[] = { 't', 'c', 'b', 'q', 'k', 'b', 'c', 't' };
    char initPosWhite[] = { 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T' };

    // for(int i=0;i<8;i++) {
    //     board[1][i] = 'p';
    //     board[6][i] = 'P';
    //     board[7][i] = initPosWhite[i];
    //     board[0][i] = initPosBlack[i];
    // } 
    
    while (!WindowShouldClose()){
        //for(int i=0;i<8;i++) for(int j=0;j<8;j++) board[i][j] = 'x';
        // Update
        //----------------------------------------------------------------------------------
        printf("\n-----------------\n");
        image_board buf;
        int n = read(serialPort, &buf, sizeof(image_board)); 
        if(n == sizeof(image_board)){
            for(int i=0;i<8;i++) {
                for(int j=0;j<8;j++){
                    board[i][j] = buf.board[i][j];
                    printf("%c", board[i][j]);
                }
                printf("\n");
            }
        } 
        printf("\n-----------------\n");
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            draw_background();
            draw_pieces(board);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    unload_background();
    unload_pieces();

    close(serialPort); 

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}