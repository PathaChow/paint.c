#include <stdio.h>
#include <stdlib.h>

typedef struct board_Dimension {
   int rows;
   int cols;
} boardDimension;

char** makeCanvas (int numRows, int numCols);
void printCanvas(int numRows, int numCols, char** canvas);


void setUp (char*** canvas, int numRows, int numCols){
	*canvas = makeCanvas(numRows, numCols);
	return; 
}

void printCanvas(int numRows, int numCols, char** canvas){
int i;
int j;
for (i = 0 ; i < numRows; ++i){
	printf("%d", numRows - i -1);
	for(j = 0; j < numCols; ++j){
		printf(" %c", canvas[i][j]);
		       }
	printf("\n");
}
printf(" "); 	 
for (j = 0 ; j < numCols; ++j){
	printf(" %d", j);
}
return; 
}
		
		
char** makeCanvas (int numRows, int numCols){	
char** canvas = (char**) malloc(numRows * sizeof(char*)); 
		 
int i;
int j; 
		 	 
for (i = 0; i < numRows; ++i){
	(canvas)[i] = (char*) malloc(numCols *sizeof(char));
	for (j = 0; j < numCols; ++j){
	(canvas)[i][j] = '*'; 
	}
}		 		 
return canvas; 
}

		 
		 
int main(int argc, char* argv[]){
	
	if (argc < 2){
		boardDimension.rows = 10; 
		boardDimension.cols = 10; 
	} else {
		boardDimension.rows = atoi(argv[1]);
		boardDimension.cols = atoi(argv[2]);
	} 

	 
	char** canvas; 
	
	setUp(&canvas, boardDimension.rows, boardDimension.cols);
	printCanvas(boardDimension.rows, boardDimension.cols, canvas);
	
	//input(); 
	//cleanup(); 
	
	return 0;
}
