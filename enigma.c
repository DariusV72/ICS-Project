#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "randomNumbers.c"
#include "substractive.c"



int main(int argc, char *argv[]){
  //variables
  char method;
  char mode;
  long seed;

  //set file pointer
  FILE *file = NULL;
  FILE *decodedFile = NULL;

  //ask for decryption or encryption
  printf("Encryption or Decryption[E/D]: \n");
  do{
    scanf("%c", &mode);
  }while(toupper(mode) != 'E' && toupper(mode) != 'D');
  
  //generate a seed depending on mode
  if(toupper(mode) == 'D'){
    printf("Key:\n");
    scanf("%ld", &seed);
    decodedFile = fopen("decoded.txt", "w");
  }
  else if(toupper(mode) == 'E') {
    //generate random seed
    srand(time(NULL));
    seed = rand();
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

  // if(toupper(mode) == 'D') {
  //   cypher[strlen(cypher) - 1] = '\0';
  // }
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
  if(toupper(mode) == 'E') {
    
    fprintf(file, "%s", cypher);
    fprintf(file, "&\n");
    fprintf(file, "Encryption of type %c\n", toupper(method));
    fclose(file);
  } else {
    
    for(int i = 0; i<strlen(cypher)-1;i++){
      fprintf(decodedFile, "%c", cypher[i]);
    }
    fclose(decodedFile);
  }
  free(cypher);
}