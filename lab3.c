#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "lab3.h"

extern int** sudoku_board;
int* worker_validation;

int** read_board_from_file(char* filename){
    FILE *fp = NULL;
    sudoku_board = (int**)malloc(sizeof(int*)*ROW_SIZE);
    for(int row = 0; row < ROW_SIZE; row++)
	    sudoku_board[row] = (int*)malloc(sizeof(int)*COL_SIZE);
    fp = fopen(filename, "r");
    for(int i = 0; i < ROW_SIZE; i++)
        for(int j = 0; j < COL_SIZE; j++) 
            fscanf(fp, "%d%*c", &sudoku_board[i][j]);


    for(int i = 0; i<ROW_SIZE; i++){
        for(int j = 0; j<COL_SIZE; j++) printf("%d ", sudoku_board[i][j]);
        printf("\n");
    }

    fclose(fp);
    return sudoku_board;

}


int is_board_valid(){
    pthread_t* tid;  /* the thread identifiers */
    pthread_attr_t attr;
    tid = (pthread_t*) malloc(sizeof(int*) * NUM_OF_THREADS);
    param_struct* parameter = (param_struct*) malloc(sizeof(param_struct)* NUM_OF_THREADS);
    int index = 0;

    
    
    
    
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

int __unnamed_struct_0a48_1::is_board_valid()
{
    return 0;
}
