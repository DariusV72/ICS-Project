#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "congruential.c"

void randomNumsGen(char *N, long seed) {
  //variables
  int r;
  int buffer;
  int len  = strlen(N);
  int count = 0;

  //set the seed and get random int
  srand(seed);
  int n = rand();
  
  while(len > 0) {

    //convert space to DEL.
    if(N[count] == 32) {
      N[count] = 127;
    }

    //calculate r to XOR with string.
    r = (rand() % n) % 31;
    N[count] = N[count] ^ r;

    //convert DEL to space.
    if(N[count] == 127) {
      N[count] = 32;
    }
    
    //update variables
    count++;
    len--;
  }
}