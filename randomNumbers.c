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

char bitification() {

}


void randomNumsGen(char *N) {
  int len  = strlen(N);
  int whatever = len;
  int count = 0;
  int seed;
  srand(seed);
  int n = rand();
  int r;

  int* encoded = NULL;
  encoded = safeMalloc(len*sizeof(int));

  if(n<10) {
    while(whatever > 0) {
      r = (rand() > (RAND_MAX / n));
      N[count] = N[count] ^ r;
      encoded[count] =r;
      count++;
      whatever --;
    }
  } 
  else {
    while(whatever > 0) {
      int holder;
      do{
        r = (rand() % n)%127;
        holder = N[count] ^ r;
      } while(holder <=32);
      N[count] = holder;
      encoded[count] =r;
      count++;
      whatever --;
    }
  }
  
  for(int i = 0; i<count; i++) {
    printf("%c", N[i]);
  }
  printf("\n");
  printf("\n");
  free(encoded);
  free(N);
}

// int main(int argc, char*argv[]) {
//   randomNumsGen();
// }

//eventual TODO: implement int to bits function, if needed