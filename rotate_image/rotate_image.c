#include <stdlib.h>
#include <print_array.h>
#include <stdio.h>

#include "rotate_image.h"

int prev_row(int i, int j, int n, int o);

int prev_col(int i, int j, int n, int o);

int next_row(int i, int j, int n, int o);

int next_col(int i, int j, int n, int o);

void rotate_ring(int n, arr_arr_integer *a, int o);

arr_arr_integer alloc_image(int n) {
    arr_arr_integer a = {
            n,
            malloc(sizeof(arr_integer) * n)
    };

    for (int i = 0; i < n; i++) {
        a.arr[i].arr = malloc(sizeof(int) * n);
    }

    return a;
}

arr_arr_integer free_image(arr_arr_integer a) {
    for (int i = 0; i < a.size; i++) {
        free(a.arr[i].arr);
    }
    free(a.arr);
}


/**
 * An square image can be like concentric rings of pixels. If the
 * image has odd size there will be a single pixel in the center if
 * it's even size there will be a square of 4 pixels in the center.
 *
 * In any case rotate an image 90 degrees should be rotate all the
 * rings 90 degrees.
 *
 * Rotate a ring means that a pixel in [0,0] should move to [0,n]
 * along with all the pixels in the same circle. n is the size of
 * the image.
 *
 * Rotate a ring from [0,0] to [0,n] is rotate a the same ring
 * from [0,0] to [0,1] n times
 *
 * To rotate all the rings, start with the outer one and then to
 * the most inner one.
 *
 * @param a
 * @return
 */
arr_arr_integer rotate_image(arr_arr_integer a) {
    int n = a.size;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n - 1; j++) {
            rotate_ring(n, &a, i);
        }
        n--;
    }

    return a;
}

/**
 * Rotates a ring 1 pixel to the right
 *
 * (0,0) moves to (0,1)
 *
 * Pixel at the origin is replace by the previous one in the ring
 * then the previous is replaced by its previous and so on until
 * we are back at the origin.
 *
 * That means we moved each pixel 1 position forward, then we just
 * replace second pixel of the ring with the original origin pixel
 *
 * @param n size of the ring
 * @param image
 * @param o top-left corner of the ring (origin)
 */
void rotate_ring(int n, arr_arr_integer *image, int o) {
    int i = o;
    int j = o;

    int tmp = image->arr[i].arr[j];
    do {
        int h = prev_row(i, j, n, o);
        int k = prev_col(i, j, n, o);

        image->arr[i].arr[j] = image->arr[h].arr[k];

        i = h;
        j = k;
    } while (!(i == o && j == o));
    int tmp_i = next_row(i, j, n, o);
    int tmp_j = next_col(i, j, n, o);
    image->arr[tmp_i].arr[tmp_j] = tmp;
}

/**
 * Given a pixel i,j in a ring with origin o returns the previous
 * pixel column
 * @param i row
 * @param j column
 * @param n size of the image
 * @param o origin
 * @return previous pixel column
 */
int prev_col(int i, int j, int n, int o) {
    int r = j;
    if (i + 1 == n && j + 1 < n) {
        r = j + 1;
    }
    if (i == o && j - 1 >= o) {
        r = j - 1;
    }
    return r;
}

/**
 * Given a pixel i,j in a ring with origin o returns the previous
 * pixel row
 * @param i row
 * @param j column
 * @param n size of the image
 * @param o origin
 * @return previous pixel row
 */
int prev_row(int i, int j, int n, int o) {
    int r = i;
    if (j == o && i + 1 < n) {
        r = i + 1;
    }
    if (j + 1 == n && i - 1 >= o) {
        r = i - 1;
    }
    return r;
}

/**
 * Given a pixel i,j in a ring with origin o returns the next
 * pixel column
 * @param i row
 * @param j column
 * @param n size of the image
 * @param o origin
 * @return next pixel column
 */
int next_col(int i, int j, int n, int o) {
    int r = j;
    if (i + 1 == n && j - 1 >= o) {
        r = j - 1;
    }
    if (i == o && j + 1 < n) {
        r = j + 1;
    }
    return r;
}

/**
 * Given a pixel i,j in a ring with origin o returns the next
 * pixel row
 * @param i row
 * @param j column
 * @param n size of the image
 * @param o origin
 * @return next pixel row
 */
int next_row(int i, int j, int n, int o) {
    int r = i;
    if (j == o && i - 1 >= o) {
        r = i - 1;
    }
    if (j + 1 == n && i + 1 < n) {
        r = i + 1;
    }
    return r;
}

void print_image(arr_arr_integer a) {
    for (int i = 0; i < a.size; i++) {
        print_array(a.arr[i].arr, a.size);
    }
    printf("\n");
}
