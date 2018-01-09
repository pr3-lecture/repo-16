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
  key.chars = "TPERULES";
  char output[strlen(input)+1];
  decrypt(key, input, output);

  mu_assert("Decrypting succesful", strcmp(expectedOutput, output) == 0);
  return 0;
}

static char* testKeyTooShort() {
  char* input = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  KEY key;
  key.chars = "T";
  char output[strlen(input)+1];
  int error = encrypt(key, input, output);

  mu_assert("Key too short!", error = E_KEY_TOO_SHORT);
  return 0;
}

static char* testKeyIllegalChar() {
  char* input = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  KEY key;
  key.chars = "$%&/()";
  char output[strlen(input)+1];
  int error = encrypt(key, input, output);

  mu_assert("Illegal Key!", error = E_KEY_ILLEGAL_CHAR);
  return 0;
}

static char* testMessageIllegalChar() {
  char* input = "ABCDEFGHIJ______QRSTUVWXYZ";
  KEY key;
  key.chars = "TPERULES";
  char output[strlen(input)+1];
  int error = encrypt(key, input, output);

  mu_assert("Illegal Message!", error = E_MESSAGE_ILLEGAL_CHAR);
  return 0;
}

static char* testCypherIllegalChar() {
  char* input = "ABCDEFGH§%&/()OPQRSTUVWXYZ";
  KEY key;
  key.chars = "TPERULES";
  char output[strlen(input)+1];
  int error = encrypt(key, input, output);

  mu_assert("Illegal Cypher!", error = E_CYPHER_ILLEGAL_CHAR);
  return 0;
}

static char* allTests() {
  mu_run_test(testEncrypt);
  mu_run_test(testDecrypt);
  mu_run_test(testKeyTooShort);
  mu_run_test(testKeyIllegalChar);
  mu_run_test(testMessageIllegalChar);
  mu_run_test(testCypherIllegalChar);
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
