#pragma once
#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<string.h>
FILE* fin, * fout;
int size;
char filename[204] = "message.txt";
char passwd[204];
char buf[1024];
Fl_Window* window;
Fl_Input* filePassWd, *filePath, *newPath;
void encode(char* filename, char* passwd);
void decode(char* filename, char* passwd);


#endif // !HEADER_H

