#include <stdlib.h>
#include <stdio.h>
#include "congruential.c"
#include "randomNumbers.c"

int main(int argc, char *argv[]){
  //variables
  int input;

  //read user input
  printf("Encryption mode: \n");
  scanf("%d\n", &input);

  //ask for text to encode/decode
  printf("Cypher text: \n");
  char *cypher = NULL;
  cypher = dynamicString();

  switch(input){
    case 1:
      randomNumsGen(cypher);
      break;
    case 2:
      lcg(cypher, 56);
      break;
  }

}