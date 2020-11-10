#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char error(){
	printf("ERROR! Plase enter: <Filename> <N> <M> <Seed>\n");
	exit(-1);
}

void* mat_mult(int rows,int cols,int **mat_1, int **mat_2, int seed){
    
    srand(seed);
    int i, j;
    mat_1 = (int **)malloc(rows * sizeof(int *));
    for (i=0; i<rows; i++){
         mat_1[i] = (int *)malloc(cols * sizeof(int));
    }
    printf("Matrix 1:\n");
   for (i = 0; i <  rows; i++){
    	for (j = 0; j < cols; j++){
			mat_1[i][j] = rand()%100;
			printf("%d ",mat_1[i][j]);
	  	}
	  	printf("\n");
	}

	mat_2 = (int **)malloc(cols * sizeof(int *));
    for (i=0; i<cols; i++){
         mat_2[i] = (int *)malloc(rows * sizeof(int));
	}
    printf("\nMatrix 2:\n");
    for (i = 0; i <  cols; i++)
    {
    	for (j = 0; j < rows; j++){
			mat_2[i][j] = rand()%100;
			printf("%d ",mat_2[i][j]);
	  	}
	  	printf("\n");
	}

	int **finalMat;
	finalMat = (int **)malloc(rows * sizeof(int *));
	for (i=0; i<rows; i++)
         finalMat[i] = (int *)malloc(rows * sizeof(int));
         printf("\nResult:\n");
    for (i = 0; i <  rows; i++){
    	for (j = 0; j < rows; j++){
			finalMat[i][j] = 0;
			for(int k = 0; k < cols; k++){
				finalMat[i][j] = finalMat[i][j] + mat_1[i][k] * mat_2[k][j];
			}
			printf("%d ", finalMat[i][j]);
    	}printf("\n");
    }
	for(i = 0; i < rows; i++){
		free(mat_1[i]);
	}
	for(i = 0; i < rows; i++){
		free(mat_2[i]);
	}
	for(i = 0; i < rows; i++){
		free(finalMat[i]);
	}
	free(mat_1);
	free(mat_2);
    free(finalMat);
}
int main(int argc, char *argv[] ){

	clock_t time = clock();
    int rows,cols;
    int random_generator;
    int **matrix_1;
    int **matrix_2;
	if( argc != 4 )
	{
		printf("ERROR: INVALID NO. OF ARGUMENTS.\n");
		error();
	}
	long args[3];
	for(int i = 0; i < 3; i++){
		char* eptr;
		args[i] =  strtol(argv[i+1], &eptr, 10);
		if (eptr == argv[i+1] || eptr[0] != '\0') {
			printf("INVALID ARGUMENT\n");
			error();
        }
	}
	rows = atoi(argv[1]);
    cols = atoi(argv[2]);
    random_generator = atoi(argv[3]);
    mat_mult(rows,cols,matrix_1,matrix_2,random_generator);
    time = clock() - time;
	double time_spent = ((double)time) / CLOCKS_PER_SEC;
	printf("TIME TAKEN FOR EXECUTION: %fs\n", time_spent);
}