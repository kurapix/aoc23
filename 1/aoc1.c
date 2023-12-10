#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = fopen("test.txt", "r");

    int result = 0;

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp)) {
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
    return 0;
}