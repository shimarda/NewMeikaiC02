#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    int omikuji_val = rand() % 7;

    if (omikuji_val == 0) {
        printf("大吉\n");
    } else if (omikuji_val == 1) {
        printf("中吉\n");
    } else if (omikuji_val == 2) {
        printf("小吉\n");
    } else if (omikuji_val == 3) {
        printf("吉\n");
    } else if (omikuji_val == 4) {
        printf("末吉\n");
    } else if (omikuji_val == 5) {
        printf("凶\n");
    } else {
        printf("大凶\n");
    }
    return 0;
}
