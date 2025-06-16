/* Given the head of a singly linked list. Group all the nodes with odd indices followed
by all the nodes with even indices and return the reordered list.
Consider the 1st node to have index 1 and so on. The relative order of the elements inside
the odd and even group must remain the same as the given input */

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *odd = head;
        ListNode *evenHead = head->next;
        ListNode *even = head->next;
        while (even != nullptr && even->next != nullptr)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

// Function to print the linked list
void printLL(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 3, 4, 2, 5, 6};
    ListNode *head = new ListNode(arr[1]);
    head->next = new ListNode(arr[3]);
    head->next->next = new ListNode(arr[4]);
    head->next->next->next = new ListNode(arr[2]);
    head->next->next->next->next = new ListNode(arr[5]);
    head->next->next->next->next->next = new ListNode(arr[1]);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLL(head);
    cout << '\n';

    // Rearrange the list and print it
    Solution solution;
    head = solution.oddEvenList(head);
    cout << "New Linked List: ";
    printLL(head);
}