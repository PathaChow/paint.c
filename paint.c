#include <stdio.h>
#include <stdlib.h>


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
	int numRows;
	int numCols;
	
	if (argc < 2){
		numRows = 10; 
		numCols = 10; 
	} else {
		numRows = atoi(argv[1]);
		numCols = atoi(argv[2]);
	} 

	 
	char** canvas; 
	
	setUp(&canvas, numRows, numCols);
	printCanvas(numRows, numCols, canvas);
	
	//input(); 
	//cleanup(); 
	
	return 0;
}
