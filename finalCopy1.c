/*献给钟会*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "input1.h"

char** makeCanvas(char** canvas, int numRows, int numCols);
void printCanvas(char** canvas);
void ReadInput();
void Help();
void Quit();
void Write();
void VerticalDash(int row1, int col1, int row2, int col2);
void LeftSlash(int row1, int col1, int row2, int col2);
void HorizontalDash(int row1, int col1, int row2, int col2);
void RightSlash(int row1, int col1, int row2, int col2);
void Erase();
void Resize ();
void Add();
void rowAdd();
void colAdd();
void Delete();
void rowDel();
void colDel();
void Save();
void Load();
int numRows;
int numCols;
char** canvas;
bool checkInt(char string[]);
bool assert_formatting(int num_args_read, int num_args_needed);



typedef struct charPosition{
	int RowNumber;
	int ColNumber; 
} charPosition; 


int main(int argc, char* argv[]){
    numRows = 0;
	numCols = 0;
	
    
    
if (argc < 3){
		numRows = 10; 
		numCols = 10; 
	} else {
		numRows = atoi(argv[1]);
		numCols = atoi(argv[2]);
        
if (argc >3){
            printf("Wrong number of command line arguements entered.\nUsage: ./paint.out [num_rows num_cols]\nMaking default board of 10 X 10.\n");
            numRows = 10;
            numCols = 10;
        }
		
		 if (checkInt(argv[1]) == false){
			 printf("The number of rows is not an integer.\n");
			 numRows = 10; 
			numCols = 10;
			printf("Making default board of 10 X 10.\n");
		 }
		 
		 if (checkInt(argv[2]) == false){
			 printf("The number of columns is not an integer.\n");
			 numRows = 10; 
			numCols = 10;
			printf("Making default board of 10 X 10.\n");
		 }
		
		if (numRows < 1){
			printf("The number of rows is less than 1.\n");
			numRows = 10; 
			numCols = 10;		
			printf("Making default board of 10 X 10.\n");
		}
		
		if (numCols < 1){
			printf("The number of columns is less than 1.\n");
			numRows = 10; 
			numCols = 10;	
			printf("Making default board of 10 X 10.\n");
		}
	}
	
	canvas = makeCanvas(canvas, numRows, numCols);
	printCanvas(canvas);
    
    ReadInput(canvas);
	
	return 0;
}
			 

	
	bool checkInt(char string[]){
		int i;
	
		for(i = 0; i < strlen(string); i++){
			if (string[i]!='-' && !(isdigit(string[i]))){
		return false; 
			}	
		}
		return true; 
	}
	



void printCanvas(char** canvas){
    int i,j;
    for(i = (numRows-1); i >=0; i--){
        printf("%d ", i);
        for(j = 0; j < numCols; j++){
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
    
    printf("  ");
    for(j = 0; j < numCols; ++j){
        printf("%d ", j);
    }
    printf("\n");
}



char** makeCanvas (char** canvas, int numRows, int numCols){
 canvas = (char**) malloc(numRows * sizeof(char*));
		 
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



void ReadInput(){
    char c;
    bool token = 1;
    while (token){
    printf("Enter your command: ");
    int num_args_read = scanf(" %c", &c);
    if (num_args_read == 1){
        if(c == 'q'){
            if(!assert_formatting(1,1)){
                printf("Unrecognized command. Type h for help.\n");
                printCanvas(canvas);
            }
            else{
            token =0;
            Quit(canvas);
            }
        }
        else if(c == 'h'){
            if(!assert_formatting(1,1)){
                printf("Unrecognized command. Type h for help.\n");
                printCanvas(canvas);
            }
            else{
            Help();
            printCanvas(canvas);
            }
        }
        else if(c == 'w'){
            Write();
            printCanvas(canvas);
        }
        else if(c == 'e'){
            Erase();
            printCanvas(canvas);
        }
        else if(c == 'r'){
            Resize();
            printCanvas(canvas);
        }
        else if(c == 'a'){
            Add();
            //printCanvas(canvas);
        }
        else if(c == 'd'){
            Delete();
            //printCanvas(canvas);
        }
        else if(c == 's'){
            Save();
            printCanvas(canvas);
        }
        else if(c == 'l'){
            Load();
            printCanvas(canvas);
        }
        else{
            if(!assert_formatting(1,1)){
            printf("Unrecognized command. Type h for help.\n");
                printCanvas(canvas);
            }
        }
    }
    else{
        printf("Unrecognized command. Type h for help.\n");
    }
    }
    return;
}

void Quit(char** canvas){
    free(canvas);
    exit (0);
    return;
}

void Help(){
    
    printf("Commands:\n");
    printf("Help: h\n");
    printf("Quit: q\n");
    printf("Draw line: w row_start col_start row_end col_end\n");
    printf("Resize: r num_rows num_cols\n");
    printf("Add row or column: a [r | c] pos\n");
    printf("Delete row or column: d [r | c] pos\n");
    printf("Erase: e row col\n");
    printf("Save: s file_name\n");
    printf("Load: l file_name\n");
    return;
}

void Write(){
    int row1, col1, row2, col2;
    int num_args_read = scanf(" %d %d %d %d", &row1, &col1, &row2, &col2);
    if(!assert_formatting(num_args_read, 4)){
        printf("Improper draw command.\n");
        return;
    }
    else if(row1<0||row1>=numRows||row2<0||row2>=numRows||col1<0||col1>=numCols||col2<0||col2>=numCols){
        printf("Improper draw command.\n");
        return;
    }
    else if(row1-row2 == col1-col2){
        LeftSlash(row1, col1, row2, col2);
    }
    else if(row1-row2 == col2-col1){
        RightSlash(row1, col1, row2, col2);
    }
    else if(row1 == row2){
        HorizontalDash(row1, col1, row2, col2);
    }
    else if(col1 == col2){
        VerticalDash(row1, col1, row2, col2);
    }
    else{
        printf("Cannot draw the line as it is not straight.\n");
        return;
    }
    return;
}

void LeftSlash(int row1, int col1, int row2, int col2){
    int c;
    if(row2 < row1){
        c = row1;
        row1 = row2;
        row2 = c;
        c = col1;
        col1 = col2;
        col2 = c;
    }
    while(row1 <= row2){
        if(canvas[row1][col1] == '*'||canvas[row1][col1] == '/'){
            canvas[row1][col1] = '/';
        }
        else{
            canvas[row1][col1] = '+';
        }
        row1++; col1++;
    }
    return;
}

void RightSlash(int row1, int col1, int row2, int col2){
    int c;
    if(row2 < row1){
        c = row1;
        row1 = row2;
        row2 = c;
        c = col1;
        col1 = col2;
        col2 = c;
    }
    while (row1 <= row2){
        if(canvas[row1][col1] == '*'||canvas[row1][col1] == '\\'){
            canvas[row1][col1] = '\\';
        }
        else{
            canvas[row1][col1] = '+';
        }
        row1++; col1--;
    }
    return;
}

void HorizontalDash(int row1, int col1, int row2, int col2){
    int c;
    if(col2 < col1){
        c = col1;
        col1 = col2;
        col2 = c;
    }
    while (col1 <= col2){
        if(canvas[row1][col1] == '*'||canvas[row1][col1] == '-'){
            canvas[row1][col1] = '-';
        }
        else{
            canvas[row1][col1] = '+';
        }
        col1++;
    }
    return;
}

void VerticalDash(int row1, int col1, int row2, int col2){
    int c;
    if(row2 < row1){
        c = row1;
        row1 = row2;
        row2 = c;
    }
    while (row1 <= row2){
        if(canvas[row1][col1] == '*'||canvas[row1][col1] == '|'){
            canvas[row1][col1] = '|';
        }
        else{
            canvas[row1][col1] = '+';
        }
        row1++;
    }
    return;
}

void Erase (){
    int row, col;
    int num_args_read = scanf(" %d %d", &row, &col);
    if(!assert_formatting(num_args_read,2)){
        printf("Improper erase command.\n");
        return;
    }
    else if(row<0||row>=numRows||col<0||col>=numCols){
        printf("Improper erase command.\n");
        return;
    }
    else{
        canvas[row][col] = '*';
    }
    return;
}

void Resize(){
    int updatedRows;
    int updatedCols;
    int num_args_read = scanf("%d %d", &updatedRows, &updatedCols);
    if(!assert_formatting(num_args_read,2)){
        printf("Improper resize command.\n");
        return;
    }
    else if(updatedRows<=0||updatedCols<=0){
        printf("Improper resize command.\n");
        return;
    }
    else{
        int i,j;
        canvas = realloc(canvas, updatedRows * sizeof(char*));
        //printf(" %d %d", updatedRows, updatedCols);
        if(updatedRows>numRows){
        for(i=numRows; i<updatedRows; i++){
            canvas[i] = malloc(updatedCols * sizeof(char));
        }
        }
        for(i=0; i<updatedRows; i++){
            canvas[i] = realloc(canvas[i], updatedCols * sizeof(char));
        }
        if(updatedRows>numRows){
            for(i=numRows;i<updatedRows;i++){
                for(j=0; j<updatedCols; j++){
                    canvas[i][j] = '*';
                }
            }
        }
        if(updatedCols>numCols){
            for(i=0; i<updatedRows; i++){
                for(j=numCols; j<updatedCols; j++){
                    canvas[i][j] = '*';
                }
            }
        }
        numRows = updatedRows;
        numCols = updatedCols;
        //printf(" %d %d", updatedRows, updatedCols);
        return;
    }
    
}


void Add(){
    char char1;
    int num_args_read = scanf(" %c", &char1);
    if(num_args_read!=1){
        printf("Improper add command.\n");
        printCanvas(canvas);
        return;
    }
    else if (char1 == 'r'){
        rowAdd();
    }
    else if (char1 == 'c'){
        colAdd();
    }
    else{
        printf("Improper add command.\n");
        printCanvas(canvas);
        return;
    }
}

void rowAdd(){
    //reallocate space for one row at the bottom of the rows (numRows)
    //malloc space for each num columns in fos row
    //shift rows below userInput for addrow down and input in starts.
    int newRow;
    int num_args_read = scanf(" %d", &newRow);
    if(!assert_formatting(num_args_read , 1)){
        printf("Improper add command.\n");
        printCanvas(canvas);
        return;
    }
    else if(newRow<0||newRow>numRows){
        printf("Improper add command.\n");
        printCanvas(canvas);
        return;
    }
    else{
        int i;
        canvas = realloc(canvas, (numRows+1) * sizeof(char*));
        canvas[numRows] = malloc(numCols * sizeof(char));
        for(i = numRows; i > newRow; i--){
            strcpy(canvas[i], canvas[i-1]);
        }
        for(i=0; i<numCols; i++){
            canvas[newRow][i] = '*';
        }
        numRows = numRows+1;
    }
    printCanvas(canvas);
    return;
}

void colAdd(){
    int i, j;
    //reallocate for the extra column
    //do for loop to shift the elements to the right
    //start from the end of the columns
    //add in the '*'
    int newCol;
    int num_args_read = scanf(" %d", &newCol);
    if(!assert_formatting(num_args_read , 1)){
        printf("Improper add command.\n");
        printCanvas(canvas);
        return;
    }
    else if(newCol<0||newCol>numCols){
        printf("Improper add command.\n");
        printCanvas(canvas);
        return;
    }
    else{
        for(i=0; i<numRows; i++){
            canvas[i] = realloc(canvas[i], (numCols + 1)* sizeof(char));
            canvas[i][numCols] = '*';
        }
        numCols = numCols +1;
        
        for(i=0; i<numRows; i++){
            for(j=numCols-1; j>newCol; j--){
                canvas[i][j] = canvas[i][j-1];
                canvas[i][j-1] = '*';
            }
        }
    }
    printCanvas(canvas);
    return;
}

void Delete (){
    char char1;
    int num_args_read = scanf(" %c", &char1);
    if(num_args_read!=1){
        printf("Improper delete command.\n");
        printCanvas(canvas);
        return;
    }
    else if (char1 == 'r'){
        rowDel();
    }
    else if (char1 == 'c'){
        colDel();
    }
    else{
        printf("Improper delete command.\n");
        return;
    }
}

void rowDel(){
    int tossRow, i;
    int num_args_read = scanf(" %d", &tossRow);
    if(!assert_formatting(num_args_read , 1)){
        printf("Improper delete command.\n");
        printCanvas(canvas);
        return;
    }
    else if(tossRow<0||tossRow>=numRows){
        printf("Improper delete command.\n");
        printCanvas(canvas);
        return;
    }
    else{
        for(i=tossRow; i<numRows-1; i++){
            strcpy(canvas[i], canvas[i+1]);
        }
        free(canvas[numRows-1]);
        canvas = realloc(canvas, (numRows-1) * sizeof(char*));
        numRows--;
    }
    printCanvas(canvas);
}

void colDel(){
    int tossCol, i, j;
    int num_args_read = scanf(" %d", &tossCol);
    if(!assert_formatting(num_args_read , 1)){
        printf("Improper delete command.\n");
        printCanvas(canvas);
        return;
    }
    else if(tossCol<0||tossCol>=numCols){
        printf("Improper delete command.\n");
        printCanvas(canvas);
        return;
    }
    else{
        //for(i=0; i<numRows; i++){
            //canvas[i][tossCol] = '*';
        //}
        for(i=0; i<numRows; i++){
            for(j=tossCol; j<numCols-1; j++){
                canvas[i][j] = canvas[i][j+1];
                canvas[i][j+1] = '*';
            }
        }
        for(i=0; i<numRows; i++){
            canvas[i] = (char*)realloc(canvas[i], (numCols-1) * sizeof(char));
        }
        numCols--;
    }
    printCanvas(canvas);
}

void Save(){
    char fname [100];
    //int num_args_read = scanf(" %s", filename);
    scanf("%s", fname);
    /*if(!assert_formatting(num_args_read , 1)){
        printf("Improper save command or file could not be created.\n");
        return;
    }*/
    /*else if(filename[strlen(filename)-1]!='t'||filename[strlen(filename)-2]!='x'||filename[strlen(filename)-3]!='t'||filename[strlen(filename)-4]!='.'){
        printf("Improper save command or file could not be created.\n");
        return;
    }*/
        FILE* outFile = NULL; // File pointer
        
        // Open file
        outFile = fopen(fname, "w");
        
        if (outFile == NULL) {
            printf("Improper save command or file could not be created.\n");
            return ;
        }
        
        // Write to file
        int i;
        fprintf(outFile, " %d %d", numRows, numCols);
        for(i=0; i<numRows; i++){
            fprintf(outFile, " %s", canvas[i]);
            fprintf(outFile, "\n");
        }
        fclose(outFile);
}

void Load(){
    char filename[100];
    //int num_args_read = scanf(" %s", filename);
    scanf(" %s", filename);
    //if(filename == NULL || filename[0] == 'm'){
        //printf("Improper load command or file could not be opened.\n");
        //return;
    //}
    /*if(!assert_formatting(num_args_read , 1)){
        printf("Improper load command or file could not be opened.\n");
        return NULL;
    }
    else if(filename[strlen(filename)-1]!='t'||filename[strlen(filename)-2]!='x'||filename[strlen(filename)-3]!='t'||filename[strlen(filename)-4]!='.'){
        printf("Improper load command or file could not be opened.\n");
        return NULL;
    }*/
        FILE * pFile;
        pFile = fopen (filename,"r");
        if(pFile == NULL){
            printf("Failed to open file: %s\n", filename);
        }
        else{
            int i =0;
            int newRows; int newCols;
            fscanf(pFile, "%d %d", &newRows, &newCols);
            canvas = realloc(canvas, newRows * (sizeof(char*)));
            if(newRows>numRows){
                for(i=numRows; i<newRows; i++){
                    canvas[i] = malloc(newCols * (sizeof(char)));
                }
            }
            for(i=0; i<newRows; i++){
                canvas[i] = realloc(canvas[i], newCols*(sizeof(char)));
                fscanf(pFile, " %s", canvas[i]);
            }
            numRows = newRows;
            numCols = newCols;
        }
    
}

bool assert_formatting(int num_args_read, int num_args_needed){
    
    char new_line = '\n';
    bool is_valid = true;
    if(num_args_read != num_args_needed){
        is_valid = false;
    }
    do{
        scanf("%c", &new_line);
        if(!isspace(new_line)){
            is_valid = false;
        }
    }while(new_line != '\n');
    return is_valid;
}

