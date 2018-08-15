#include <stack.h>

#include "is_balanced.h"

bool is_balanced(const char *sequence) {
    stack *s = stack_init(sizeof(char));

    const char *c = sequence;
    do {
        if (*c == '(' || *c == '[') {
            s->push(s, c);
        } else if (*c == ')' || *c == ']') {
            if (s->size(s) == 0) {
                return false;
            }

            char last_c;
            s->peek(s, &last_c);

            if ((last_c == '(' && *c != ')') || (last_c == '[' && *c != ']')) {
                stack_free(s);
                return false;
            }

            s->pop(s, NULL);
        }
    } while (*(++c) != 0);

    int size = s->size(s);
    stack_free(s);

    return size == 0;
}
