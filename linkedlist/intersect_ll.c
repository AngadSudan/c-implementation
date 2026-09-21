#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *create_node(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

struct Node *intersection(struct Node *head1, struct Node *head2)
{
    struct Node *intersectionHead = NULL;
    struct Node *intersectionTail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else if (head2->data < head1->data)
        {
            head2 = head2->next;
        }
        else
        {
            struct Node *newNode = create_node(head1->data);

            if (newNode == NULL)
            {
                return intersectionHead;
            }

            if (intersectionHead == NULL)
            {
                intersectionHead = newNode;
            }
            else
            {
                intersectionTail->next = newNode;
            }

            intersectionTail = newNode;
            head1 = head1->next;
            head2 = head2->next;
        }
    }

    return intersectionHead;
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
    struct Node node1 = {1, NULL};
    struct Node node2 = {2, NULL};
    struct Node node3 = {2, NULL};
    struct Node node4 = {4, NULL};
    struct Node node5 = {6, NULL};

    struct Node node6 = {2, NULL};
    struct Node node7 = {2, NULL};
    struct Node node8 = {3, NULL};
    struct Node node9 = {6, NULL};
    struct Node node10 = {7, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    node6.next = &node7;
    node7.next = &node8;
    node8.next = &node9;
    node9.next = &node10;

    struct Node *result = intersection(&node1, &node6);

    print_node(&node1);
    print_node(&node6);
    print_node(result);

    return 0;
}
