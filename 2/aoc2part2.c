#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        return 1;
    }

    int result = 0;

    char buffer[200];
    while (fgets(buffer, sizeof(buffer), fp)) {
        int max[] = {0, 0, 0};

        char *substring = strtok(buffer, ":");

        while (substring != NULL) {

            int number;
            char color[6];
            substring = strtok(NULL, ";,");
            if (substring) {
                if (sscanf(substring, "%d %s", &number, color) != 2) {
                    return 1;
                }
                if (strcmp(color, "red") == 0) {
                    if (number > max[0]) {
                        max[0] = number;
                    }
                } else if (strcmp(color, "green") == 0) {
                    if (number > max[1]) {
                        max[1] = number;
                    }
                } else {
                    if (number > max[2]) {
                        max[2] = number;
                    }
                }
            }
        }
        result += (max[0] * max[1] * max[2]);
    }
    printf("%d\n", result);

    fclose(fp);
    return 0;
}