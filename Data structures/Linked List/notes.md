types of Linked List:
    1. Singly LL.
    2. Doubly LL.
    3. Circular LL.



Use of pointer of node type and data in the node. This collection is known as Linked List.

        [D | A] -> [D | A] -> [D | A] -> [D | Null] ---- linked list ends.
            ---- D = data, A = address.



while(temp -> next != NULL){
    temp = tail;
    temp++;
}