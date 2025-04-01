// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



enum {
    NUM_OF_DIGITS = 10
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int hist[NUM_OF_DIGITS] = { 0 };
    char s;

    while (scanf("%c", &s) != EOF) {

        // If s is a digit
        if ('1' <= s && s <= '9') {
            hist[s - '1']++;
        }
    }

    for (int i = 0; i < NUM_OF_DIGITS - 1; i++) {
        printf("%d ", hist[i]);
    }

    // Print last index without space at the end
    printf("%d", hist[NUM_OF_DIGITS - 1]);

    return 0;
}
