// Flow chart: array, linked list, single variable -- anything
// finding pattern for cycle, loop, repeatetive behaviour.
// 


class Solution{
public:
    bool template(){
        slow = val;
        fast = val;
        while(slow != NULL && fast != NULL && fast->next != NULL) {
             TODO: // ORDER IN WHILE CONDITION BLOCK NEEDS TO MAINTAINED AS IF WE TRY TO FIND null->next IT WILL CRASH THE PROGRAM.

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }
};

//


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *val) {
        // Edge case: An empty list or a list with only one node cannot have a cycle
        if (val == nullptr || val->next == nullptr) {
            return false;
        }

        ListNode *slow = val;
        ListNode *fast = val;

        // Traverse the list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Moves 1 step
            fast = fast->next->next;    // Moves 2 steps

            // If they meet, there is a cycle!
            if (slow == fast) {
                return true;
            }
        }

        // If the fast pointer hits the end of the list, there is no cycle
        return false;
    }
};