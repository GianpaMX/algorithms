#include "climb_stairs.h"

/*
 * n == 2 means that your are standing in the floor and you have to climb
 * two steps to be at the top, so you have two ways to go.
 *
 * So if n == 1, you are standing in the floor and you to climb one step,
 * there is only one way to go.
 *
 * But what does it mean n == 0? you are standing in the floor and you to
 * climb zero steps. That is a way to go too
 */
int climb_stairs(int n) {
    if (n == 0) return 1;
    if (n <= 2) return n;

    return climb_stairs(n - 1) + climb_stairs(n - 2);
}
