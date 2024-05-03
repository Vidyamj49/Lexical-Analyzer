/*
   here operators function - called from main.c file
   isKeyword function - called from main.c file from parsing function
   symbol function called from main.c file

 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

 int open=0,close=0;


// operator checking function
int operators(char ch)
{
    static char operator[] = { '/', '+', '-', '%', '<', '>', '_', '&', ',', '!', '^', '|'};
    int i=0;
    while(operator[i])
    {
        if(ch == operator[i])
        {
            return 1;
        }
        i++;
    }
     return 0;
}

// keywords
int isKeyword(char buffer[])
{
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                              "do","double","else","enum","extern","float","for","goto",
                              "if","int","long","register","return","short","signed",
                              "sizeof","static","struct","switch","typedef","union",
                              "unsigned","void","volatile","while"};

    int i=0,flag=0;
    for(i = 0; i < 32; ++i)
    {
         if(strcmp(keywords[i], buffer) == 0)
         {
         flag = 1;
         break;
         }


    }
    return flag;
}


// symbols
int symbol(char ch)
{

   static char symbols[] = { '{', '}', ')', '(', '[', ']', ':'};
   int i=0;
   /*while(symbols[i])
   {
   if((ch == symbols[i]) )
       return 1;
   i++;
   }*/
   //printf("hii");
   //while(1);
   int num_symbols = sizeof(symbols) / sizeof(symbols[0]);
   for (i = 0; i < num_symbols; i++) {
        if (ch == symbols[i]) {
            return 1; // Found a match; ch is a symbol
        }
    }
   return 0;

}


/*int error_semi( char ch, char *prev, char *bracket)
{
    if(ch == ';')
    *prev = ch;
    else
        *bracket = ch;
}*/

