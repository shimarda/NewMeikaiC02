#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    int omikuji_val = rand();

    if (omikuji_val % 2) {
        printf("大吉\n");
    } else if (omikuji_val % 3) {
        printf("中吉\n");
    } else if (omikuji_val % 5) {
        printf("小吉\n");
    } else if (omikuji_val % 7) {
        printf("吉\n");
    } else if (omikuji_val % 11) {
        printf("末吉\n");
    } else if (omikuji_val % 13) {
        printf("凶\n");
    } else if (omikuji_val % 17) {
        printf("大凶\n");
    }
    return 0;
}