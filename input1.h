//
//  input1.h
//  
//
//  Created by Zhouxuanchen on 12/6/16.
//
//

#ifndef input1_h
#define input1_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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


#endif /* input1_h */
