#include <stdio.h>
#include <stdbool.h>

#include "is_balanced.h"

int main() {
    char *sequence = "([]()[(]))";

    bool result = is_balanced(sequence);

    printf("%s is %s", sequence, result ? "balanced" : "not balanced");
}
