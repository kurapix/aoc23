#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        return 1;
    }
    int rgb[] = {12, 13, 14};

    int result = 0;

    char buffer[200];
    while (fgets(buffer, sizeof(buffer), fp)) {
        int game_number;
        if (sscanf(buffer, "Game %d", &game_number) != 1) {
            return 1;
        }

        char *substring = strtok(buffer, ":");
        bool valid = true;

        while (substring != NULL) {
            int number;
            char color[6];
            substring = strtok(NULL, ";,");
            if (substring) {
                if (sscanf(substring, "%d %s", &number, color) != 2) {
                    return 1;
                }
                if (strcmp(color, "red") == 0) {
                    if (number > rgb[0]) {
                        valid = false;
                        break;
                    }
                } else if (strcmp(color, "green") == 0) {
                    if (number > rgb[1]) {
                        valid = false;
                        break;
                    }
                } else {
                    if (number > rgb[2]) {
                        valid = false;
                        break;
                    }
                }
            }
        }
        if (valid) {
            result += game_number;
        }
    }
    printf("%d\n", result);

    fclose(fp);
    return 0;
}