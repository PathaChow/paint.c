#include <stdio.h>




char** createCanvas (numRows, int numCols, char** board){
	
char** canvas = (char** malloc(numRows * sizeof(char*)); 
int i; 

for (i = 0; i < numRows; i++){
	canvas[i] = (char*)malloc(numCols *sizeof(char));
	for (j = 0; j < numCols; j++){
	
		canvas[i][j] = '*'; 
	}
}
return canvas; 
}

int main(argc, argv[]){
	
	
	if (!argv[2]){
		numRows = 10; 
		numCols = 10; 
	} else {
		numRows = atoi(argv[1]);
		numCols = atoi(argv[2]);
	}
	char*** canvas; 
	createCanvas();
	commands();
	input(); 
	cleanup(); 
	
	return 0;
}

void input(){
	
int numRow; 
int numCol; 


	
	
	
}

commands(char** canvas){
	char c;
	if(c == "q"){
		free(canvas);
		exit (0); 
	}
	else if (c == "h"){
		
	}
}