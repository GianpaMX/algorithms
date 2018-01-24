#include <stdlib.h>
#include "seq_list.h"

seq_list seq_list_init(size_t n) {
    seq_list list;
    list.seqs = malloc(n * sizeof(int *));
    list.n = n;
    list.seq_size = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        list.seqs[i] = NULL;
        list.seq_size[i] = 0;
    }
    return list;
}

bool seq_list_execute_query(seq_list list, seq_list_query query, int *last_answer) {
    int i = (query.x ^ *last_answer) % list.n;

    if (query.type == 2) {
        *last_answer = list.seqs[i][query.y % list.seq_size[i]];
        return true;
    }

    list.seq_size[i]++;
    list.seqs[i] = realloc(list.seqs[i], list.seq_size[i] * sizeof(int));
    list.seqs[i][list.seq_size[i] - 1] = query.y;
    return false;
}

void seq_list_free(seq_list list) {
    for (int i = 0; i < list.n; i++) {
        if (list.seq_size > 0) {
            free(list.seqs[i]);
        }
    }
    free(list.seq_size);
}
