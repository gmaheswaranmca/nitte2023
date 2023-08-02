/*
Find number of palindrome words in the given sentence 

Example:
Input:
madam is from malayalam state.
Output:
2

*/
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include<cstdio>
#include<cstring>
char* reverse_word(char* word)
{
	int size = strlen(word);
	for (int L = 0, R = size - 1; L < R; L++, R--) {
		char t = word[L];
		word[L] = word[R];
		word[R] = t;
	}
	return word;
}
int main() {
	char sentence[50] = "madam is from malayalam state."; //space, comma, .
	char* word;

	word = strtok(sentence, " .");
	int palWordsCount = 0;
	while (word != NULL)
	{
		//printf("%s\n", word);
		char rword[50];
		strcpy(rword, word);
		reverse_word(rword);
		if (strcmp(word, rword) == 0) {
			palWordsCount++;
		}
		//printf("[%s]\n", rword);
		word = strtok(NULL, " .");
	}
	printf("%d", palWordsCount);

	return 0;
}
