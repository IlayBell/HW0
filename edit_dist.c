#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 100

int edit_dist(char word1[], char word2[]);
int min3(int a, int b, int c);

int main() {
	char word1[MAX_WORD_LEN], word2[MAX_WORD_LEN];
	
	fgets(word1, MAX_WORD_LEN, stdin);
	word1[strlen(word1) - 1] = '\0';
	fgets(word2, MAX_WORD_LEN, stdin);
	word2[strlen(word2) - 1] = '\0';

	printf("%d\n", edit_dist(word1, word2));

	return (0);
}

/**
 * @brief Finds Levinstein dist of 2 strings
 * @param word1 - 1st string
 * @param word2 - 2nd string
 * @return The distance
 */
int edit_dist(char word1[], char word2[]) {
	/* YOUR CODE HERE */

    /* We incorporate dynamic programing using a table */
    int table[MAX_WORD_LEN][MAX_WORD_LEN] = { {0} };
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    for (int i = 0; i < len1; i++) {
        table[i][0] = i;
    }

    for (int j = 0; j < len2; j++) {
        table[0][j] = j;
    }

    /* table[i-1][j] -> resembles the deletion operation
     * table[i][j-1] -> resembles the insertion operation
     * table[i-1][j-1] -> resembles the replacement operation
     * */
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            table[i][j] = min3(table[i - 1][j],
                              table[i][j - 1],
                              table[i - 1][j - 1]) + 1;
        }
    }

    return table[len1 - 1][len2 - 1];
}

/**
 * @brief Returns the min value between 3 elements
 * @param a - 1st element
 * @param b  - 2nd element
 * @param c - 3rd element
 * @return The value of the min element
 */
int min3(int a, int b, int c) {
    if (a < b) {
        return a < c ? a : c;
    }

    return b < c ? b : c;
}