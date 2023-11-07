#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define A 5
#define C 12345
#define M 32

void lcg(char *input, long seed){
  //set seed
  unsigned int x = seed;

  //make file pointer
  FILE *file = NULL;

  //measure length
  int len;
  len = strlen(input);

  //open file for appending
  file = fopen("cyphers.txt", "a");

  //calculate random number and perform encryption.
  for(int i = 0; i < len; i++){

    //convert space to DEL.
    if(input[i] == 32) {
      input[i] = 127;
    }

    //calculate number to XOR
    x = ((A * x + C) % M);
    input[i] = input[i] ^ x;

    //convert DEL to space.
    if(input[i] == 127) {
      input[i] = 32;
    }
  }
  
  //print end result to file
  fprintf(file, "%s", input);

  //close the file
  fclose(file);
}


char *dynamicString(){

  //create starting array
  char *input, c;
  int i = 0;
  input = (char *)malloc(1*sizeof(char));

  //reallocate array and add characters
  while(c = getc(stdin), c!='\n'){
    input[i] = c;
    i++;
    input = realloc(input, 2*i*sizeof(char));
  }
  input[i] = '\0';
  return input;
}