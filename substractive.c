#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "congruential.c"

#define m 32

void substractive(unsigned char *input, int seed);

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

int main (int argc, char *argv[]){
  char *input = dynamicString();
  int seed;
  srand(time(NULL));
  seed = rand();
  substractive(input, seed);
  free(input);
  return 0;
}

void substractive(unsigned char *input, int seed){
  int *arr = malloc((55+strlen(input))*sizeof(int));
  srand(seed);
  for(int i=0; i<55; i++){
    arr[i] = rand();
  }

  int x;
  for(int i=0;input[i]!='\0' ; i++) {
    arr[55 + i] = (arr[55 + i - 24] - arr[55 + i - 55]) % m;
    input[i] = input[i]^(arr[55 + i]);
  }
  printf("%s\n", input);
  FILE *file = NULL;
  file = fopen("cyphers.txt", "a");
  fprintf(file, "%s\n", input);

  for(int i = 0; input[i]!='\0'; i++) {
    input[i] = input[i]^(arr[55 + i]);
  }
  //printf("%s\n", input);
  fprintf(file, "%s\n", input);
  fclose(file);

}