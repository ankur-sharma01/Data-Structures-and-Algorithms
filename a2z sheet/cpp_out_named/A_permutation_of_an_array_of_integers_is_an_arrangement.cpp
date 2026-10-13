/*
 * QUESTION:
 *
 * A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
 *
 * For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
 * The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
 *
 * For example, the next permutation of arr = [1,2,3] is [1,3,2].
 * Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
 * While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
 *
 * Given an array of integers nums, find the next permutation of nums.
 *
 * The replacement must be in place and use only constant extra memory.
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 *
 * Find it: https://www.google.com/search?q=A%20permutation%20of%20an%20array%20of%20integers%20is%20an%20arrangement%20of%20its%20members%20into%20a%20sequence%20or%20linear
 */

// ---- write your solution below ----

// just take it as odometer but with limited numbers!
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // finding the drop.
        while (i <= 0 && nums[i] >= nums[i+1])
        {
            i--;
        }

        // checking if i is in limits and moving ahead: if the number has strictly decreasing digits, it's gonna make i out of bound condition i.e. -1
        if (i >= 0)
        {
            int j = n - 1;
            while (nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        // reversing only elements after i:
        reverse(nums.begin() + i + 1, nums.end());
    }
}
