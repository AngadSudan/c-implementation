#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

int is_sublist(struct Node *list1, struct Node *list2)
{
    while (list2 != NULL)
    {
        struct Node *current1 = list1;
        struct Node *current2 = list2;

        while (current1 != NULL && current2 != NULL &&
               current1->data == current2->data)
        {
            current1 = current1->next;
            current2 = current2->next;
        }

        if (current1 == NULL)
        {
            return 1;
        }

        list2 = list2->next;
    }

    return list1 == NULL;
}

int main()
{
    struct Node list1Node1 = {10, NULL};
    struct Node list1Node2 = {20, NULL};

    struct Node list2Node1 = {5, NULL};
    struct Node list2Node2 = {10, NULL};
    struct Node list2Node3 = {20, NULL};

    list1Node1.next = &list1Node2;

    list2Node1.next = &list2Node2;
    list2Node2.next = &list2Node3;

    if (is_sublist(&list1Node1, &list2Node1))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}
