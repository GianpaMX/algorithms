#include <stdio.h>
#include "first_not_repeating_char.h"

int main() {
    char s[] = "abacabad";

    char c = first_not_repeating_char(s);

    printf("%c", c);

    return 0;
}
