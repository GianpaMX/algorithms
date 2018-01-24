#include <stdio.h>
#include "seq_list.h"

int main() {
    int n, q_size;
    scanf("%d%d", &n, &q_size);

    seq_list list = seq_list_init(n);
    seq_list_query query;
    int last_answer = 0;
    for (int i = 0; i < q_size; i++) {
        scanf("%d%d%d", &query.type, &query.x, &query.y);
        if (seq_list_execute_query(list, query, &last_answer)) {
            printf("%d\n", last_answer);
        }
    }
    seq_list_free(list);
    return 0;
}
