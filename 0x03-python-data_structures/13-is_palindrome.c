#include "lists.h"
#include <stdbool.h>

/**
 * reverse_list - Reverse a linked list
 * @head: pointer to head of list
 * Return: pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return *head;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 1 if the linked list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return (1);

    listint_t *slow = *head;
    listint_t *fast = *head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverse_list(&slow->next);
    slow = slow->next;
    fast = *head;

    while (slow != NULL)
    {
        if (fast->n != slow->n)
            return (0);
        fast = fast->next;
        slow = slow->next;
    }

    return (1);
}
