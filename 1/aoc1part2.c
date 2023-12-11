#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        return 1;
    }

    char words[][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int digits[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int result = 0;

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp)) {
        bool done = false;
        for (int i = 0; i < strlen(buffer); ++i) {
            for (int j = 0; j < 9; ++j) {
                if (strncmp(buffer + i, words[j], strlen(words[j])) == 0) {
                    buffer[i] = digits[j] + '0';
                    done = true;
                    break;
                }
                if (done) {
                    break;
                }
            }
        }

        done = false;
        for (int i = strlen(buffer) - 1; i >= 0; --i) {
            for (int j = 0; j < 9; ++j) {
                if (strncmp(buffer + i, words[j], strlen(words[j])) == 0) {
                    buffer[i] = digits[j] + '0';
                    done = true;
                    break;
                }
                if (done) {
                    break;
                }
            }
        }

        char first, second;
        for (int i = 0; i < strlen(buffer); ++i) {
            if (isdigit(buffer[i])) {
                first = buffer[i];
                break;
            }
        }

        for (int i = strlen(buffer) - 1; i >= 0; --i) {
            if (isdigit(buffer[i])) {
                second = buffer[i];
                break;
            }
        }
        result += (10 * (first - '0')) + (second - '0');
    }
    printf("%d\n", result);

    fclose(fp);
    return 0;
}
