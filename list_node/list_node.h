#ifndef ALGORITHMS_LIST_NODE_H
#define ALGORITHMS_LIST_NODE_H

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode list_node;

list_node *list_node_new(int val);

void list_node_print(list_node *list);


#endif //ALGORITHMS_LIST_NODE_H
