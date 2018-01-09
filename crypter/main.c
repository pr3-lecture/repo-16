#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include "crypto.h"
#include "crypto.c"

int main(int argc, char const *argv[]) {


  KEY key;
  key.chars = argv[1];

  if (argv[1] == NULL) {
    fprintf(stderr, "Schluessel fehlt\n");
    return -1;
  }

  char input[100];
  if (argv[2] != NULL) {
    FILE* f = fopen(argv[2], "r");

    if (f != NULL) {
      fgets(input, 100, f);
      fclose(f);
    }
  } else {
    printf("Bitte Nachricht eingeben: ");
    scanf("%s", input);
  }

  char output[strlen(input) + 1];

  if(strstr(argv[0], "encrypt") != NULL) {
    if(encrypt(key, input, output) == 0) {
      printf("Encrypted: %s\n", output);
    }
  }

  if(strstr(argv[0], "decrypt") != NULL) {
    if(decrypt(key, input, output) == 0) {
      printf("Decrypted: %s\n", output);
    }
  }


  return 0;
}
