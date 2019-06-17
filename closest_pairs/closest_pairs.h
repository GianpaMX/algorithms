#ifndef ALGORITHMS_CLOSEST_PAIRS_H
#define ALGORITHMS_CLOSEST_PAIRS_H

typedef struct {
    int first;
    int second;
} Pair;

int closest_pairs(const int *a_array,
                  int a_size,
                  const int *b_array,
                  int b_size,
                  int k,
                  Pair *pairs);


#endif //ALGORITHMS_CLOSEST_PAIRS_H
