// LC 209: REVERSE A LINKED LIST
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        // FIXED: Check 'current' directly so every node (including the last one) gets processed safely
        while(current != nullptr) { 
            ListNode *next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        
        return prev;
    }
};


// LC 92: REVERSE LINKED LIST 2 -- BETWEEN INTERVAL

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *left_prev = dummy;
        for(int i = 0; i < left - 1; i++) {
            left_prev = left_prev->next;
        }

        ListNode *current = left_prev->next;

        ListNode *prev = nullptr;
        for(int i = 0; i < (right-left+1); i++) {
            ListNode *next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        left_prev->next->next = current;
        left_prev->next = prev;

        ListNode *new_head = dummy->next;  
        delete dummy;
        return new_head;
    }
};



// 
// FIXED: Added left and right to the function parameters
ListNode* reverseBetween(Node* head, int left, int right) {
    if(head == NULL) return NULL;
    if(left == right) return head;

    Node* t = head;
    Node* before = nullptr;
    int pos = 1;

    while(t != NULL) {
        if(pos < left) {
            before = t;
            t = t->next;
            pos++;
            continue;
        }
        
        Node* current = t;
        Node* prev = NULL;
        int times = right - left + 1;
        
        while(times--) {
            Node *nex = current->next;
            current->next = prev;
            prev = current;
            current = nex;
        }
        
        t->next = current; // Connect tail of reversed segment to the rest of the list
        
        // FIXED: Only update before->next if 'before' actually exists
        if(before) {
            before->next = prev;
            return head; // The original head remains the head
        }
        
        // If 'before' is null, the reversed segment started at head, 
        // making 'prev' the new head of the entire list.
        return prev; 
    }
    return head;
}