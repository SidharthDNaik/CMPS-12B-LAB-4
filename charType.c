/*
* Name: Sidharth Naik
* ID: 1647945
* Class: 12B/M
* Date: February 10,2018
* Description: This is the code that contains all the methods for the charType.c
* File Name: charType.c
* Instructions: After compiling by using the make command in the command line
* type: charType (source file name) (file to copy to) in the command line to run the code
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>

#define MAX_STRING_LENGTH 100

void extract_chars(char* s, char* a, char* d, char* p, char* w){
  int i =0, j=0, k=0, l=0, m=0, o=0;
  while(s[i]!='\0' && i<MAX_STRING_LENGTH){
    if(isalpha((int) s[i]) ){
      a[j++] = s[i];
    }
    else if(isdigit((int) s[i]) ){
      d[k++] = s[i];
    }
    else if(ispunct((int) s[i]) ){
      p[l++] = s[i];
    }
    else if(isspace((int) s[i]) ){
      w[m++] = s[i];
    }
    else{
      o++;
    }
    i++;
  }
  a[j] = '\0';
  d[k] = '\0';
  p[l] = '\0';
  w[m] = '\0';
}

// function main which takes command line arguments
int main(int argc, char* argv[]){
   FILE* in;        // handle for input file
   FILE* out;       // handle for output file
   char* line;      // string holding input line
   char* alphaChar; // string holding all alphabet
   char* digitChar; // string holding all digits
   char* punctChar; // string holding all punctuation
   char* spaceChar; // string holding all white space
   int counter = 1;

   // check command line for correct number of arguments
   if( argc != 3 ){
      printf("Usage: %s input-file output-file\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   // open input file for reading
   if( (in=fopen(argv[1], "r"))==NULL ){
      printf("Unable to read from file %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   // open output file for writing
   if( (out=fopen(argv[2], "w"))==NULL ){
      printf("Unable to write to file %s\n", argv[2]);
      exit(EXIT_FAILURE);
   }

   // allocate strings line and alpha_num on the heap
   line = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   alphaChar = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   digitChar = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   punctChar = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   spaceChar = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   assert( line!=NULL && alphaChar!=NULL );
   assert( line!=NULL && digitChar!=NULL );
   assert( line!=NULL && punctChar!=NULL );
   assert( line!=NULL && spaceChar!=NULL );

   // read each line in input file, extract alpha-numeric characters
   while( fgets(line, MAX_STRING_LENGTH, in) != NULL ){
      fprintf(out, "line %d contains:\n", counter);
      extract_chars(line, alphaChar, digitChar, punctChar, spaceChar);
      fprintf(out, "%d alphabetic characters: %s\n", (int)strlen(alphaChar), alphaChar);
      fprintf(out, "%d numeric characters: %s\n", (int)strlen(digitChar), digitChar);
      fprintf(out, "%d punctuation characters: %s\n", (int)strlen(punctChar), punctChar);
      fprintf(out, "%d whitespace characters: %s\n", (int)strlen(spaceChar), spaceChar);
      counter++;
   }

   // free heap memory
   free(line);
   free(alphaChar);
   free(digitChar);
   free(punctChar);
   free(spaceChar);

   // close input and output files
   fclose(in);
   fclose(out);

   return EXIT_SUCCESS;
}
