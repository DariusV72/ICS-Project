#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *dynamicString(){
  char *input, c;
  int i = 0;
  input = (char *)malloc(1*sizeof(char));

  while(c = getc(stdin), c!='\n'){
    input[i] = c;
    i++;
    input = realloc(input, 8*i*sizeof(char));
  }
  input[i] = '\0';
  return input;
}

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
      encoded[count] =r;
      count++;
      whatever --;
    }
  } 
  else {
    while(whatever > 0) {
      r = rand() % n;
      //printf("%d", r);
      encoded[count] =r;
      count++;
      whatever --;
    }
  }
  
  for(int i = 0; i<count; i++) {
    printf("%d ", encoded[i]);
  }
  printf("\n");
  for(int i = 0; i<count; i++) {
    N[i] = encoded[i] ^ N[i];
  }

  for(int i = 0; i<count; i++) {
    printf("%c ", N[i]);
  }
  printf("\n");
  for(int i = 0; i<count; i++) {
    N[i] = encoded[i] ^ N[i];
  }
  for(int i = 0; i<count; i++) {
    printf("%c ", N[i]);
  }
  printf("\n");
  free(encoded);
  free(N);
}

// int main(int argc, char*argv[]) {
//   randomNumsGen();
// }

//eventual TODO: implement int to bits function, if needed