#include <stdlib.h>
#include "btree.h"

struct btree_node {
    int hash;

    struct btree_node *left;
    struct btree_node *right;
};

btree *btree_init(int (*hash)(const void *)) {
    btree *t = malloc(sizeof(btree));
    t->node = NULL;
    t->hash = hash;
    t->put = &btree_put;
    t->contains = &btree_contains;
    return t;
}

void btree_free(btree *t) {
    if (t->node != NULL) {
        btree_node_free(t->node);
    }
    t->node = NULL;
    free(t);
}

void btree_put(btree *t, const void *value) {
    if (t->node == NULL) {
        t->node = btree_node_init(t->hash(value));
        return;
    }

    btree_insert(t->node, t->hash(value));
}

bool btree_contains(const btree *t, void *value) {
    if (t->node == NULL) return false;

    return NULL != btree_find(t->node, value, t->hash);
}

const struct btree_node *btree_find(const struct btree_node *node, void *value, int (*hash)(const void *)) {
    if (node->hash == hash(value)) return node;

    if (node->left != NULL) {
        const struct btree_node *result = btree_find((const struct btree_node *) node->left, value, hash);
        if (result != NULL) return result;
    }

    if (node->right != NULL) return btree_find((const struct btree_node *) node->right, value, hash);

    return NULL;
}

void btree_insert(struct btree_node *node, int hash) {
    if (hash > node->hash) {
        if (node->right != NULL) {
            btree_insert(node->right, hash);
        } else {
            node->right = btree_node_init(hash);
        }
    } else if (hash < node->hash) {
        if (node->left != NULL) {
            btree_insert(node->left, hash);
        } else {
            node->left = btree_node_init(hash);
        }
    }
}

struct btree_node *btree_node_init(int hash) {
    struct btree_node *node = malloc(sizeof(struct btree_node));
    node->hash = hash;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void btree_node_free(struct btree_node *node) {
    if (node == NULL) return;

    btree_node_free(node->left);
    btree_node_free(node->right);
    free(node);
}
