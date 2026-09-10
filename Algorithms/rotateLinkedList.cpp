// 61. Rotate List

// Given the head of a linked list, rotate the list to the right by k places.
// https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        // base case:
        if(!head || !head || k == 0) return head;
        // finding length:
        int n = 1;
        ListNode* end = head;

        while(end->next)
        {
            end = end->next;
            n++;
        }

        // using k modulo:
        k = k % n;
        if(k == 0) return head;

        ListNode* prevEnd = head;

        for(int i = 0; i < n-k-1; i++)
        {
            prevEnd = prevEnd->next;
        }

        ListNode* st = head;
        end->next = st;
        ListNode* newHead = prevEnd->next;
        prevEnd->next = NULL;

        return newHead;
    }
};