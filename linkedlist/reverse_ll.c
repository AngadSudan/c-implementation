#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *reverse_ll(struct Node *node1)
{
    if (node1 == NULL || node1->next == NULL)
    {
        return node1;
    }

    struct Node *newHead = reverse_ll(node1->next);
    node1->next->next = node1;
    node1->next = NULL;

    return newHead;
}

void print_node(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main()
{
    struct Node node1;
    struct Node node2;
    struct Node node3;
    struct Node node4;

    node1.data = 10;
    node2.data = 20;
    node3.data = 30;
    node4.data = 40;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = NULL;

    print_node(&node1);

    struct Node *head = reverse_ll(&node1);

    print_node(head);

    return 0;
}