#include "crypto.h"
#include "stdio.h"
#include "memory.h"

typedef enum { false, true } bool;

int main(){

	KEY key;
	key.type = 1;
	key.chars = "TPERULESTPERULESTPERULESTP";

	char* input = "URFVPJB[]ZN^XBJCEBVF@ZRKMJ";
	char output[strlen(input)+1];

	printf("Before Crypt\n");
	printf("%s\n", key.chars);
	printf("%s\n", input);
	printf("Going to Encrypt\n");
	encrypt(key, input, output);
	printf("%s\n", key.chars);
	printf("%s\n", input);
	printf("%s\n", output);

}
int checkKeyException(KEY key){
	
	char* allowedCharactersForKey = KEY_CHARACTERS;
	int checkKey;

	for (int i = 0; i < strlen(key.chars); i++) {
		checkKey = 0;

		for (int j = 0; j < strlen(allowedCharactersForKey); j++) {
			if(key.chars[i] == allowedCharactersForKey[j]){
				checkKey = 1;
			}
		}

		if(checkKey = 0){
			return 0;
		}
	}

	return 1;

}

int doCrypt(KEY key, const char* input, char* output){

	int keyLength = strlen(key.chars);

	for (int i = 0; i < strlen(input); i++) {
		char newInput = input[i] - 'A' + 1;
		char newKey = key.chars[i % keyLength] - 'A' + 1;
		char newOutput = newInput ^ newKey;
		output[i] = newOutput + 'A' - 1;
	}

	return 0;
}

int encrypt(KEY key, const char* input, char* output){

	if(strlen(key.chars) < 1){
		return E_KEY_TOO_SHORT;
	}

	if(checkKeyException(key) == 1){
		return E_KEY_ILLEGAL_CHAR;
	}


	doCrypt(key, input, output);

	return 0;
}

int decrypt(KEY key, const char* cypherText, char* output){

	if(strlen(key.chars) < 1){
		return E_KEY_TOO_SHORT;
	}

	if(checkKeyException(key) == 1){
		return E_KEY_ILLEGAL_CHAR;
	}


	doCrypt(key, cypherText, output);

	return 0;
}



// char c = 'k';
// int x = c - 'A' + 1;
// char k = x + 'A' - 1;
