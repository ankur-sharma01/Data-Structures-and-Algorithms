// min heap -- smallest value at top
// max heap -- largest value at top

// time complexity:
//     top element find = O(1)
//     Insert anything = O(log n)
//     Delete anything = O(log n)
//      n --> size of heap


// Max Heap = Priority Queue --> priority_queue<int> pq;
// Min Heap = Priority Queue --> priority_queue<int, vector<int>, greater<int>> pq;


// Priority queue automatically handles the order of element and rearranges itself accordingly if new element is pushed.




// 7 STEPS to apply for a heap question:
// 1: top k, most frequent k, largest k, smallest k, etc.
// 2: kis chiz me? - calculations - hashmap, distance tracking
// 3: heap of pairs (chiz jiski top k nikalna hai, array element or index) - size should be of kitne chiz chahiye
// 4: bada dekhne ke liye - min heap, chota dekhne ke liye - max heap
// 5: push k items in heap
// 6: push all and pop accordingly
// 7: k elements in heap - result