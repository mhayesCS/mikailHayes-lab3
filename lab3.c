#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "lab3.h"

extern int** sudoku_board;
int* worker_validation;

int** read_board_from_file(char* filename){
    FILE *fp = fopen(filename, "r");
    int** board = NULL;

    // replace this comment with your code
    board = (int**)malloc(9*sizeof(int*));
    for (int col = 0; col < 9; col++)
    {
        board[col] = (int*)malloc(9*sizeof(int));
    }
    if(fp == NULL) return;

    int row = 0;
    while(row < 9){
        int col = 0;
        while(col < 9){
            fscanf(fp,"%d",&board[row][col]);
            col++;
        }
        row++;
    }
    fclose(fp);
    return board;
}


int is_board_valid(){
    pthread_t* tid;  /* the thread identifiers */
    pthread_attr_t attr;
    param_struct* parameter;
    
    // replace this comment with your code
    
}

int board_piece(int* row){
    int* checker[] ={0, 0,0,0,0,0,0,0,0}; 
    for (int value =0; value < 9; value++){
        checker[row[value]-1] = 1;
    }
    for (int value =0; value < 9; value++){
        if(checker[value] == 0){
            return 0;
        }
    }
    return 1;
}