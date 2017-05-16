
#include "merge_buffer.h"
#include "print_array.h"


int main() {
    int P[] = {1, 5, 10, 20, 30, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int S[] = {3, 8, 25, 35, 45, 55, 65, 75};

    print_array(P, 18);
    print_array(S, 8);

    merge_buffer(P, 6, S, 8);

    print_array(P, 18);
    print_array(S, 8);

    return 0;
}
