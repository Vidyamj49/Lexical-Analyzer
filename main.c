/*
   main function
   reading characters from .c file and passing as parameter to the parsing function
   */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "main.h"

    
extern int open;
extern int close;
//main function///////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
   FILE *fp;
   if(argc==2)
   {
      fp = fopen(argv[1],"r");
      if(fp == NULL)
      {
        printf("error while opening the file\n");
        exit(0);
      }

   }
   parsing(fp);
}


// reading dat from file//////////////////////////////////////////////
void parsing(FILE *fp)
{
   char ch, buffer[15];
   int i,j=0;
   while((ch = fgetc(fp)) != EOF)
   {
       //char semi,bracket;;
       /*char prev, bracket;
        if(ch == ';' || ch == ')')
	{
             error_semi(ch,&prev, &bracket);	     
	}
	if(ch == '\n' && prev != ';' && bracket != '(' )
	    printf("ERROR: Missing semicolon.\n");*/

       if(ch == ';')
       {
	   printf("; is End of statement\n");
	   continue;
       }


       if(symbol(ch) == 1)
       {
	   printf("%c is symbol\n",ch);
	   if(ch == '{')
	       open++;
	   else if( ch == '}')
	       close++;

	   continue;
       }

        if(operators(ch) == 1)
	{
        printf("%c is operator\n", ch);
	continue;
	}
       

      if(isalnum(ch) || ch == '#'|| ch == ';')
      {
         buffer[j++] = ch;
      }
      else if((ch == ' ' || ch == '\n') && (j != 0))
      {
        buffer[j] = '\0';
        //j = 0;
	if(buffer[0] == '#')
	printf("%s is preprocessor\n",buffer);
	else if(isKeyword(buffer ) == 1)
	{
           printf("%s keyword\n", buffer);
	}
        else
	{
        printf("%s is indentifier\n", buffer);

	}
	j=0;
      }

   }
   fclose(fp);

   if(open != close)
     printf("ERROR: Bracket mismatch.\n");
}
