#include <stdio.h>

quit(char** canvas, char c);



void printCanvas(int numRows, int numCols, char** canvas){

for (i = 0 ; i < numRows; i++){
	printf("%d", numRows - i -1)
	for(j = 0; j < numCols; j++){
		printf("%c", canvas[i][j]);
		       }
	printf("\n");
}
printf("  "); 	 
for (j = 0 ; j < numCols, ; j++){
	printf("%d", j)
}
return 0; 
}
		
		
char** makeCanvas (numRows, int numCols){	
char** canvas = (char** malloc(numRows * sizeof(char*)); 
		 
int i;
int j; 
		 	 
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
	printCanvas();
	makeCanvas();
	input(); 
	cleanup(); 
	
	return 0;
}
		 
		 
		 

void input(){
	
quit(char** canvas, char c);
help();

		
}

		 
		 
		 
		 
void quit(char** canvas, char c){		 
	if(c == "q"){
		free(canvas);
		exit (0);
}
return; 
}
