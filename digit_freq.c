// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

enum {
    MAX_LENGTH = 1000,
    NUM_OF_DIGITS = 10
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int hist[NUM_OF_DIGITS] = { 0 };
    char s[MAX_LENGTH];

    scanf("%s", s);

    for (int i = 0; i < MAX_LENGTH; i++) {

        /* If s is a digit */
        if ('0' <= s[i] && s[i] <= '9') {
            hist[s[i] - '0']++;
        }
    }

    for (int i = 0; i < NUM_OF_DIGITS - 1; i++) {
        printf("%d ", hist[i]);
    }

    /* Print last index without space at the end */
    printf("%d", hist[NUM_OF_DIGITS - 1]);

    return 0;
}
