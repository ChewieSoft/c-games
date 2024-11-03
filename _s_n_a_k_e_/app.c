#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <Windows.h>
#include <stdbool.h>
#include "../tools/terminal_colors/terminal_colors.h"

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20
#define MAX_TAIL_LENGTH 100
#define SUCCESS 0

// Variáveis globais
int is_game_over, score;
int snake_head_x, snake_head_y, fruit_x, fruit_y;
int snake_tail_x[MAX_TAIL_LENGTH], snake_tail_y[MAX_TAIL_LENGTH];
int snake_tail_length;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction direction;

// Função para configurar o jogo
void initialize_game()
{
    is_game_over = false;
    direction = STOP;
    snake_head_x = BOARD_WIDTH / 2;
    snake_head_y = BOARD_HEIGHT / 2;
    fruit_x = rand() % BOARD_WIDTH;
    fruit_y = rand() % BOARD_HEIGHT;
    score = 0;
    snake_tail_length = 0;
}

// Desenha o tabuleiro, a cobra e a fruta
void draw_board()
{
    
    system("cls");
    printf("%s     _S_N_A_K_E_      %s\n", set_print(fgBLACK, bgORANGE, caNORMAL), RESET);
    for (int column = 0; column < BOARD_WIDTH +2; column++)
    {
        printf("%s %s", set_print(fgBLACK, bgORANGE, caNORMAL), RESET);
    }                
    printf("\n");

    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int column = 0; column < BOARD_WIDTH; column++)
        {
            if (column == 0)
            {
                printf("%s\xDC%s", set_print(fgORANGE, bgORANGE, caNORMAL), RESET);
            }                

            if (row == snake_head_y && column == snake_head_x)
            {
                printf("%sO%s", set_print(fgGREEN, bgBLACK, caNORMAL), RESET); // Cabeça da cobra
            }                
            else if (row == fruit_y && column == fruit_x)
            {
                printf("%s0%s", set_print(fgRED, bgBLACK, caNORMAL), RESET); // Fruta
            }                
            else
            {
                int is_tail_part = false;
                for (int tail_segment_index = 0; tail_segment_index < snake_tail_length; tail_segment_index++)
                {
                    if (snake_tail_x[tail_segment_index] == column && snake_tail_y[tail_segment_index] == row)
                    {
                        printf("%so%s", set_print(fgGREEN, bgBLACK, caNORMAL), RESET);
                        is_tail_part = true;
                        break;
                    }
                }
                if (!is_tail_part)
                    printf(" ");
            }

            if (column == BOARD_WIDTH - 1)
            {
                printf("%s\xDC%s", set_print(fgORANGE, bgORANGE, caNORMAL), RESET);
            }                
        }
        printf("\n");
    }

    for (int horizontal_position = 0; horizontal_position < BOARD_WIDTH + 2; horizontal_position++)
    {
        printf("%s\xDC%s", set_print(fgORANGE, bgORANGE, caNORMAL), RESET);
    }        
    printf("\n");

    printf("\n%sScore: %s%d%s\n", CYAN, YELLOW, score, RESET);    
}

// Captura a entrada do usuário
void capture_input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            direction = LEFT;
            break;
        case 'd':
            direction = RIGHT;
            break;
        case 'w':
            direction = UP;
            break;
        case 's':
            direction = DOWN;
            break;
        case 'x':
            is_game_over = true;
            break;
        }
    }
}

void update_game_logic()
{
    // Movimenta a cabeça da cobra de acordo com a direção
    int previous_x = snake_head_x;
    int previous_y = snake_head_y;

    switch (direction)
    {
    case LEFT:
        snake_head_x--;
        break;
    case RIGHT:
        snake_head_x++;
        break;
    case UP:
        snake_head_y--;
        break;
    case DOWN:
        snake_head_y++;
        break;
    default:
        break;
    }

    // Aplica wrap-around nas bordas para a cabeça antes de atualizar a cauda
    if (snake_head_x >= BOARD_WIDTH) snake_head_x = 0;
    else if (snake_head_x < 0) snake_head_x = BOARD_WIDTH - 1;

    if (snake_head_y >= BOARD_HEIGHT) snake_head_y = 0;
    else if (snake_head_y < 0) snake_head_y = BOARD_HEIGHT - 1;

    // Movimenta cada segmento da cauda para a posição do segmento anterior
    int temp_x, temp_y;
    for (int tail_segment_index = 0; tail_segment_index < snake_tail_length; tail_segment_index++)
    {
        temp_x = snake_tail_x[tail_segment_index];
        temp_y = snake_tail_y[tail_segment_index];
        snake_tail_x[tail_segment_index] = previous_x;
        snake_tail_y[tail_segment_index] = previous_y;
        previous_x = temp_x;
        previous_y = temp_y;
    }

    // Verifica colisão da cabeça com a cauda
    for (int tail_index = 0; tail_index < snake_tail_length; tail_index++)
    {
        if (snake_tail_x[tail_index] == snake_head_x && snake_tail_y[tail_index] == snake_head_y)
        {
            printf("\n%s> %s %sCollision detected with the tail!%s\n", GREEN, eCROSS, set_print(fgRED, bgBLACK, caNORMAL), RESET);
			printf("%s> %sGAME OVER!%s\n", GREEN, set_print(fgRED, bgBLACK, caBLINKING), RESET);
            is_game_over = true;
        }
    }

    // Verifica se a cobra comeu a fruta
    if (snake_head_x == fruit_x && snake_head_y == fruit_y)
    {
        score += 10;
        fruit_x = rand() % BOARD_WIDTH;
        fruit_y = rand() % BOARD_HEIGHT;
        snake_tail_length++;
        printf("Fruit eaten! New fruit position: (%d, %d)\n", fruit_x, fruit_y);
    }

    // Log de posição para debug
    printf("\nLog\n");
    printf("Head position: (%d, %d), Tail length: %d\n", snake_head_x, snake_head_y, snake_tail_length);
}



// Função principal do jogo
int main()
{

    // set console code page to utf-8
    SetConsoleOutputCP(CP_UTF8);
    initialize_game();
    
    while (!is_game_over)
    {       
        draw_board();
        capture_input();
        update_game_logic();
        Sleep(100); // Aumente ou diminua o valor para ajustar a velocidade
    }
    return SUCCESS;
}
