#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "randomNumbers.c"

int main(int argc, char *argv[]){
  //variables
  char method;
  char mode;
  int seed;

  //ask for decryption or encryption
  printf("Encryption or Decryption[E/D]: \n");
  do{
    scanf("%c", &mode);
  }while(toupper(mode) != 'E' && toupper(mode) != 'D');

  //generate a seed depending on mode
  seed = rand();
  if(mode == 'D'){
    printf("Key: \n");
    scanf("%d\n", &seed);
  }

  //ask for way of encrypting/decrypting
  printf("Encrypting mode[R/L/S]: \n");
  do{
    scanf("%c\n", &method);
  }while(toupper(method) != 'R' && toupper(method) != 'L' && toupper(method) != 'S');

  //TO DO: Fix the printf order.
  //ask for text to encode/decode
  printf("Cypher text: \n");
  char *cypher = NULL;
  cypher = dynamicString();

  switch(method){
    case 'R':
      randomNumsGen(cypher);
      break;
    case 'L':
      lcg(cypher, seed);
      break;
  }

}