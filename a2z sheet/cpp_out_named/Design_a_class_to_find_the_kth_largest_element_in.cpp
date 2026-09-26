/*
 * QUESTION:
 *
 * Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 * Implement KthLargest class:
 * - KthLargest(int k, int[] nums): Initializes the object with the integer k and the stream of integers nums.
 * - int add(int val): Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 *
 * Example:
 * Input:
 * ["KthLargest", "add", "add", "add", "add", "add"]
 * [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
 * Output:
 * [null, 4, 5, 5, 8, 8]
 *
 * Explanation:
 * KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
 * kthLargest.add(3);   // return 4
 * kthLargest.add(5);   // return 5
 * kthLargest.add(10);  // return 5
 * kthLargest.add(9);   // return 8
 * kthLargest.add(4);   // return 8
 *
 * Find it: https://www.google.com/search?q=Design%20a%20class%20to%20find%20the%20kth%20largest%20element%20in%20a%20stream.%20Note%20that%20it%20is%20the%20kth
 */

// ---- write your solution below ----


