// LC 24. Swap Nodes in Pairs

// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)


// Example 1:

// Input: head = [1,2,3,4]

// Output: [2,1,4,3]

class Solution {
public:

    void reverse(ListNode*head, int times) {
        ListNode* current = head;
        ListNode* prev = NULL;
        while(times--)
        {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return;
    }

    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL) return NULL;
        ListNode* left = head;
        ListNode* right;
        ListNode* res = NULL;
        ListNode* prevLeft = NULL;
        int k = 2;

        while(true)
        {
            right = left;
            for(int i = 0; i < (k-1); i++)
            {
                if(right == NULL) break;
                right = right->next;
            }

            if(right) // left right mil chuka hai
            {
                ListNode* nextleft = right->next;
                reverse(left, k);
                
                if(prevLeft) prevLeft->next = right;

                prevLeft = left;

                if(res == NULL)
                res = right;

                left = nextleft;
            }
            else
            {
                // khatam hai sb
                if(prevLeft) prevLeft->next = left;
                if(res == NULL) res = left;

                break;
            }
        }
        return res;
    }
};

// another sol.:
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node acts as a fake head before the actual list
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Ensure there are at least two nodes left to swap
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Step 1: Connect previous section to the second node
            prev->next = second;
            
            // Step 2: Bridge first node to the remainder of the list
            first->next = second->next;
            
            // Step 3: Flip second node to point back to first node
            second->next = first;

            // Move prev 2 steps forward for the next pair
            prev = first;
        }

        return dummy.next;
    }
};

//
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: If 0 or 1 node remains, no swap is needed
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Nodes to be swapped
        ListNode* first = head;
        ListNode* second = head->next;

        // Recursive call for the remaining list
        first->next = swapPairs(second->next);
        
        // Reverse current pair
        second->next = first;

        // 'second' is the new head of this swapped pair
        return second;
    }
};