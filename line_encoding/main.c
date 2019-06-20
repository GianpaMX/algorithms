

#include <stdio.h>
#include "line_encoding.h"

int main() {
    char result[100] = "";

    line_encoding("aabbbc", result);
    printf("%s\n", result);

    line_encoding("abbcabb", result);
    printf("%s\n", result);

    line_encoding("abcd", result);
    printf("%s\n", result);

    line_encoding("zzzz", result);
    printf("%s\n", result);

    line_encoding("wwwwwwwawwwwwww", result);
    printf("%s\n", result);

    line_encoding("ccccccccccccccc", result);
    printf("%s\n", result);

    line_encoding("qwertyuioplkjhg", result);
    printf("%s\n", result);

    line_encoding("ssiiggkooo", result);
    printf("%s\n", result);

    line_encoding("adfaaa", result);
    printf("%s\n", result);

    line_encoding("bbjaadlkjdl", result);
    printf("%s\n", result);

    return 0;
}
