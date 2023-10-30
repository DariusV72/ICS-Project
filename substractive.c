#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define m 32

void substractive(unsigned char *input, int seed){
  //setup array for keys of 55
  int *arr = malloc((55+strlen(input))*sizeof(int));

  //set the first rand number
  srand(seed);
  for(int i=0; i<55; i++){
    arr[i] = rand();
  }

  
  int x;
  for(int i=0;input[i]!='\0' ; i++) {
    arr[55 + i] = abs((arr[55 + i - 24] - arr[55 + i - 55]) % m);
    input[i] = input[i]^(arr[55 + i]);
  }
  printf("%s\n", input);
  FILE *file = NULL;
  file = fopen("cyphers.txt", "a");
  fprintf(file, "%s\n", input);
  
  fclose(file);
}