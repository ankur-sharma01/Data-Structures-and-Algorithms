/*
 * QUESTION:
 *
 * Construct the linked list from arr and return the head of the linked list.
 *
 * Example 1:
 *
 * Input:
 * n = 5
 * arr = [1,2,3,4,5]
 * Output:
 * 1 2 3 4 5
 * Explanation: Linked list for the given array will be 1->2->3->4->5.
 * Example 2:
 *
 * Input:
 * n = 2
 * arr = [2,4]
 * Output:
 * 2 4
 * Explanation: Linked list for the given array will be 2->4.
 *
 * Find it: https://www.google.com/search?q=Construct%20the%20linked%20list%20from%20arr%20and%20return%20the%20head%20of%20the%20linked%20list.
 */

// ---- write your solution below ----

class Solution{
public:
    struct Node{
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = nullptr;
        }
    };

    Node* constructLL(vector<int>& arr) {
        if (arr.empty())
            return nullptr;

        Node* head = new Node(arr[0]);
        Node* current = head;

        for (int i = 1; i < arr.size(); i++)
        {
            current->next = new Node(arr[i]);
            current = current->next;
        }

        return head;
    }
}
