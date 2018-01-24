#ifndef ALGORITHMS_SEQ_LIST_H
#define ALGORITHMS_SEQ_LIST_H

#include <stdbool.h>

typedef struct {
    int **seqs;
    int *seq_size;
    int n;
} seq_list;

typedef struct {
    int type;
    int x;
    int y;
} seq_list_query;

seq_list seq_list_init(size_t n);

bool seq_list_execute_query(seq_list list, seq_list_query query, int *last_answer);

void seq_list_free(seq_list list);

#endif //ALGORITHMS_SEQ_LIST_H
