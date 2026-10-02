/*
 * QUESTION:
 *
 * A number N is represented in a linked list such that each digit corresponds to a node in the linked list.
 * You need to add 1 to the number represented by the linked list.
 *
 * Find it: https://www.google.com/search?q=A%20number%20N%20is%20represented%20in%20a%20linked%20list%20such%20that%20each%20digit%20corresponds%20to%20a%20node%20in
 */

// ---- write your solution below ----

/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
public:
    int addWithCarry(Node* head) {
        // if LL is empty:
        if (head == nullptr)
            return 1;

        // add carry:
        int res = head->data + addWithCarry(head->next);

        // update data and return new carry:
        head->data = res % 10;
        return res/10;
    }

    Node* addOne(Node* head) {
        // code here
        // traverse to the last node and add, store the carry.
        int carry = addWithCarry(head);

        if (carry)
        {
            Node* newNode = new Node(carry);
            newNode->next = head;

            return newNode;
        }
        return head;
    }
};

/*
Dry Run 1:
digit = 459 --> 4->5->9
addOne(head) calls addWithCarry(Node(4)).

addWithCarry(Node(4)) calls addWithCarry(Node(5)).

addWithCarry(Node(5)) calls addWithCarry(Node(9)).

addWithCarry(Node(9)) calls addWithCarry(NULL).

Base Case Reached: addWithCarry(NULL) hits if (head == nullptr) and returns 1 (this represents the initial 1 we want to add).
Processing Node(9)
Received Carry from below: 1res = head->data + 1 --> 9 + 1 = 10
head->data = res % 10 --> 10 % 10 = 0
res / 10 $\implies 10 / 10 = \mathbf{1}$ (Carry for previous node)List state: 4 -> 5 -> 0 -> NULL


Dry Run 2:
Recursive Traversal (Stack Push)

addOne(head) -> addWithCarry(9_1) -> addWithCarry(9_2) -> addWithCarry(9_3) -> addWithCarry(null)

Base Case: head == nullptr returns carry = 1 (the +1 to add).

Unwinding Stack (Post-Order Backtracking)

Node 9_3: res = 9 + 1 = 10 => data = 0, returns carry = 1. (List: 9 -> 9 -> 0)

Node 9_2: res = 9 + 1 = 10 => data = 0, returns carry = 1. (List: 9 -> 0 -> 0)

Node 9_1: res = 9 + 1 = 10 => data = 0, returns carry = 1. (List: 0 -> 0 -> 0)

Overflow Handling in addOne()

Final carry = 1 returns to addOne().

Creates newNode(1) and points newNode->next = head.

Final List: 1 -> 0 -> 0 -> 0 -> NULL
*/