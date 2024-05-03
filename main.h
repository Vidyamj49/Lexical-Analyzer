#include <stdio.h>

char filename[20]; // to store filename 
long int f_size; // to store size of file

void parsing(FILE *fp);
int symbol(char ch);
int isKeyword(char buffer[]);
int operators(char ch);
