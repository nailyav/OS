/*
 * outputs:
 * for size = 10:
 *      hit: 9
        miss: 991
        ratio: 0.009082
 * for size = 50:
 *      hit: 51
        miss: 949
        ratio: 0.053741
 * for size = 100:
 *      hit: 93
        miss: 907
        ratio: 0.102536
 */

#include <stdlib.h>
#include <stdio.h>

const int size = 10;

typedef struct frame {
    int ref;
    int num;
    int priority;
} frame;

int main() {

    FILE *file = fopen("Lab 09 input.txt", "r");

    frame *frames = calloc(size, sizeof(frame));
    
    int hit = 0;
    int miss = 0;

    for (int i = 0; i < size; i++) {
        frames[i].priority = 0;
        frames[i].num = 0;
        frames[i].ref = 0;
    }

    int number = 0;

    while (fscanf (file, "%d", &number) != EOF) {

        int t = hit;

        for (int i = 0; i < size; i++) {
            frames[i].priority = frames[i].priority >> 1;

            if (frames[i].ref == 1 && frames[i].num == number) {
                hit++;
                frames[i].priority += 128;
            }
        }

        if (t == hit) {
            int min_index = 0;
            int j = 0;
            miss++;

            for (j = 0; j < size; j++) {
                if (frames[j].ref == 0) {
                    min_index = j;
                    j = size + 1;
                }
            }

            if (j == size) {
                int min = 256;
                for (int j = 0; j < size; j++) {
                    if (frames[j].priority < min) {
                        min = frames[j].priority;
                        min_index = j;
                    }
                }
            }

            frames[min_index].num = number;
            frames[min_index].priority = 128;
            frames[min_index].ref = 1;
        }
    }

    float ratio = (float)hit/(float)miss;
    printf("hit: %d\nmiss: %d\nratio: %f", hit, miss, ratio);

    fclose(file);
}