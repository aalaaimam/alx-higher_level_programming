#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to pointer of first node of listint_t list
 * Return: pointer to the new head of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *next = NULL;

    while (*head != NULL)
    {
        next = (*head)->next;
        (*head)->next = prev;
        prev = *head;
        *head = next;
    }

    return prev;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *second_half = NULL;
    listint_t *prev_slow = *head;
    listint_t *mid_node = NULL;
    int result = 1; // Assume it's a palindrome by default

    if (*head != NULL && (*head)->next != NULL)
    {
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }

        // If the linked list has odd number of elements, ignore the middle element
        if (fast != NULL)
        {
            mid_node = slow;
            slow = slow->next;
        }

        // Reverse the second half and compare with the first half
        second_half = slow;
        prev_slow->next = NULL; // Mark the end of the first half
        second_half = reverse_listint(&second_half); // Reverse the second half

        // Compare the first half and the reversed second half
        result = compare_lists(*head, second_half);

        // Restore the original list by reversing the reversed second half
        second_half = reverse_listint(&second_half);

        // If there was a mid node (odd length list), reconnect it
        if (mid_node != NULL)
        {
            prev_slow->next = mid_node;
            mid_node->next = second_half;
        }
        else
        {
            prev_slow->next = second_half;
        }
    }

    return result;
}

/**
 * compare_lists - compares two linked lists
 * @head1: pointer to pointer of first node of listint_t list
 * @head2: pointer to pointer of first node of listint_t list
 * Return: 1 if the lists are identical, 0 otherwise
 */
int compare_lists(listint_t *head1, listint_t *head2)
{
    listint_t *temp1 = head1;
    listint_t *temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->n == temp2->n)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {
            return 0;
        }
    }

    // Both lists are identical if temp1 and temp2 are NULL
    if (temp1 == NULL && temp2 == NULL)
        return 1;

    return 0;
}
