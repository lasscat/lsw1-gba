struct Node {
    struct Node *next;
    struct Node *prev;
};

void sub_08012CC4(struct Node **head, struct Node *node)
{
    if (*head == node) {
        *head = node->next;
    }
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev != 0) {
        node->prev->next = node->next;
    }
    node->next = 0;
    node->prev = 0;
}
