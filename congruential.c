#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define A 1103515245
#define C 12345
#define M 127

void lcg(char *input, int seed){
  //set seed
  unsigned int x = seed;

  //make file pointer
  FILE *file = NULL;

  //measure length
  int len;
  len = strlen(input);

  //create big array
  unsigned int *arr = calloc(len, sizeof(unsigned int));
  //open file for appending
  file = fopen("cyphers.txt", "w");

  //calculate random number and perform encryption.
  int holder;
  for(int i = 0; i < len; i++){
    do{
      x = ((A * x + C) % M);
      holder = input[i] ^ x;
    }while(holder < 32);

    //add to list
    input[i] = holder;

    //add x to arr
    arr[i] = x;
  }

  for(int i = 0; i < len; i++){
    printf("%c", input[i]);
  }
  printf("\n");

  //print end result to file
  fprintf(file, "%s\n", input);

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