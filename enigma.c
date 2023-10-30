#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "randomNumbers.c"

#define ARR_SIZE 10000

int main(int argc, char *argv[]){
  //variables
  char method;
  char mode;
  long seed;
  FILE *file = NULL;

  //ask for decryption or encryption
  printf("Encryption or Decryption[E/D]: \n");
  do{
    scanf("%c", &mode);
  }while(toupper(mode) != 'E' && toupper(mode) != 'D');

  //generate a seed depending on mode
  if(toupper(mode) == 'D'){
    printf("Key:\n");
    scanf("%ld", &seed);
  }
  else if(toupper(mode) == 'E') {
    //generate random seed
    srand(time(NULL));
    seed = rand();

    //print seed to file
    file = fopen("cyphers.txt", "a");
    fprintf(file, "%ld\n", seed);
    fclose(file);
  }

  //ask for way of encrypting/decrypting
  printf("Encrypting mode[R/L/S]:\n");
  do{
    scanf("%c", &method);
  }while(toupper(method) != 'R' && toupper(method) != 'L' && toupper(method) != 'S');

  //TO DO: Fix the printf order.
  //ask for text to encode/decode
  printf("Cypher text:\n");
  char *cypher = calloc(ARR_SIZE, sizeof(char));
  scanf("%s", cypher);

  switch(toupper(method)){
    case 'R':
      randomNumsGen(cypher, seed);
      break;
    case 'L':
      lcg(cypher, seed);
      break;
  }

}