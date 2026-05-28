#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }
int sum = 0;
    int num;
    char buffer[256];

    while (fscanf(fp, "%255s", buffer) == 1) {
        if (sscanf(buffer, "%d", &num) == 1) {
            sum += num;
        } else {
            fprintf(stderr, "%s\n", buffer);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
