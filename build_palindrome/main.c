#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "build_palindrome.h"

int main() {
    const char *st = "abcdc";
    char *palindrome = malloc(strlen(st) * sizeof(char) + 1);

    build_palindrome(st, palindrome);

    printf("%s\n", st);
    printf("%s\n", palindrome);

    return 0;
}
