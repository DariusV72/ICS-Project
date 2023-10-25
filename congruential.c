#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A 1103515245
#define C 12345
#define M 2147483648

//prototype
char *dynamicString();
void lcg(char *input, int seed);

int main(int argc, char *argv[]){
  //read the seed
  int seed;
  seed = rand();

  //read the string
  char *input = NULL;
  input = dynamicString();
  lcg(input, seed);
}

void lcg(char *input, int seed){
  //set seed
  unsigned int x = seed;
  FILE *file = NULL;

  //measure length
  int len;
  len = strlen(input);

  //create big array
  unsigned int *arr = calloc(len, sizeof(unsigned int));

  file = fopen("cyphers.txt", "a");

  for(int i = 0; i < len; i++){
    x = (A * x + C) % M;
    input[i] = input[i] ^ x;

    //add x to arr
    arr[i] = x;
    fprintf(file, "%u ", arr[i]);
    
  }

  fprintf(file, "\n");

  for(int i = 0; i < len; i++){
    printf("%c", input[i]);
  }
  printf("\n");

  fprintf(file, "%s\n", input);

  for(int i = 0; i < len; i++){
    input[i] = input[i] ^ arr[i];
    //open file

    printf("%c", input[i]);
  }
  printf("\n");
  fclose(file);
}


char *dynamicString(){
  char *input, c;
  int i = 0;
  input = (char *)malloc(1*sizeof(char));

  while(c = getc(stdin), c!='\n'){
    input[i] = c;
    i++;
    input = realloc(input, 2*i*sizeof(char));
  }
  input[i] = '\0';
  return input;
}