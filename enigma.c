#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "randomNumbers.c"
#include "substractive.c"

#define ARR_SIZE 10000

int main(int argc, char *argv[]){
  //variables
  char method;
  char mode;
  long seed;

  //set file pointer
  FILE *file = NULL;

  //ask for decryption or encryption
  printf("Encryption or Decryption[E/D]: \n");
  do{
    scanf("%c", &mode);
  }while(toupper(mode) != 'E' && toupper(mode) != 'D');
  file = fopen("cyphers.txt", "a");
  //generate a seed depending on mode
  if(toupper(mode) == 'D'){
    printf("Key:\n");
    scanf("%ld", &seed);
  }
  else if(toupper(mode) == 'E') {
    //generate random seed
    srand(time(NULL));
    seed = rand();
    fclose(file);
    file = fopen("cyphers.txt", "w");
    //print seed to file
    fprintf(file, "%ld\n", seed);
  }

  //ask for way of encrypting/decrypting
  printf("Encrypting mode[R/L/S]:\n");
  do{
    scanf("%c", &method);
  }while(toupper(method) != 'R' && toupper(method) != 'L' && toupper(method) != 'S');

  //put newline in buffer
  printf("Cypher text:\n");
  char buffer;
  scanf("%c", &buffer);

  //read string
  char *cypher = NULL;
  cypher = dynamicString();

  if(toupper(mode) == 'D') {
    cypher[strlen(cypher) - 1] = '\0';
  }
  fclose(file);
  //decide which encoding/decoding to use
  switch(toupper(method)){
    case 'R':
      randomNumsGen(cypher, seed);
      break;
    case 'L':
      lcg(cypher, seed);
      break;
    case 'S':
      substractive(cypher, seed);
      break;
  }
  file = fopen("cyphers.txt", "a");
  if(toupper(mode) == 'E') {
    fprintf(file, "&\n");
    fprintf(file, "Encryption of type %c\n", toupper(method));
  }
  fclose(file);
  
  free(cypher);
}