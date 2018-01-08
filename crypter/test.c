#include <stdio.h>
#include <string.h>
#include "crypto.h"
#include "crypto.c"

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                      if (message) return message; } while (0)

int tests_run = 0;

static char* testEncrypt() {
  char* input = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char* expectedOutput = "URFVPJB[]ZN^XBJCEBVF@ZRKMJ";
  KEY key;
  key.chars = "TPERULESTPERULESTPERULESTP";
  char output[strlen(input)+1];
  encrypt(key, input, output);

  mu_assert("Encrypting succesful", strcmp(expectedOutput, output) == 0);
  return 0;
}

static char* testDecrypt() {
  char* input = "URFVPJB[]ZN^XBJCEBVF@ZRKMJ";
  char* expectedOutput = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  KEY key;
  key.chars = "TPERULESTPERULESTPERULESTP";
  char output[strlen(input)+1];
  decrypt(key, input, output);

  mu_assert("Decrypting succesful", strcmp(expectedOutput, output) == 0);
  return 0;
}

static char* allTests() {
  mu_run_test(testEncrypt);
  mu_run_test(testDecrypt);
  return 0;
}

int main(int argc, char const *argv[]) {
  char* result = allTests();

  if(result != 0) {
    printf("%s\n", result);
  } else {
    printf("ALL TESTS PASSED\n");
  }

  printf("Tests run: %d\n", tests_run);
  return result != 0;
}
