#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "congruential.c"

void *safeMalloc(int n) {
  void *p = malloc(n);
  if (p == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return p;
}

void randomNumsGen(char *N, long seed) {
  int len  = strlen(N);
  int whatever = len;
  int count = 0;
  srand(seed);
  int n = rand();
  int r;

  int* encoded = NULL;
  encoded = safeMalloc(len*sizeof(int));

  if(n<10) {
    while(whatever > 0) {
      r = (rand() > (RAND_MAX / n));
      printf("Under 10: %d\n", r);
      N[count] = N[count] ^ r;
      encoded[count] =r;
      count++;
      whatever --;
    }
  }
  else {
    while(whatever > 0) {
      // int holder;
      // do{
      //   r = (rand() % n)%127;
      //   holder = N[count] ^ r;
      //   printf("Above 10: %d r: %d N[%d]: %d\n", holder, r,count, N[count]);
      // } while(holder <=32);
      // printf("Accepted\n");
      // N[count] = holder;
      // encoded[count] =r;
      // count++;
      // whatever--;
      r = (rand() % n) % 32;
      N[count] = N[count] ^ r;
      count++;
      whatever--;
    }
  }

  //print text to file
  FILE *file = NULL;
  file = fopen("cyphers.txt", "a");
  fprintf(file, "%s\n", N);
  fclose(file);

  free(encoded);
  free(N);
}