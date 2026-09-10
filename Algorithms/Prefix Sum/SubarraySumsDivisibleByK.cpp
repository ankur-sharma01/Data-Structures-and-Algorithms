// LC 974: Subarray Sums Divisible by K

// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int currentSum = 0;
        int count = 0;
        unordered_map<int,int> history;

        history[0] = 1;

        for(int i = 0; i < n; i++) {
            currentSum += nums[i];
            int remainder = currentSum % k;
            if(remainder < 0) {
                remainder += k;
            }
            if(history.find(remainder) != history.end()) {
                count += history[remainder];
            }
            history[remainder]++;
        }
        return count;
    }
};

// Let’s lay it out clearly. The confusion comes down to how "Exact Value" math works versus how "Divisibility" math works.The First Problem (Exact Value: Subarray Sum = 7)In the first problem, you are looking for an exact chunk of size 7.If you are standing at 12, you can only pair up with a past position of 5 ($12 - 7 = 5$).If you were at a past position of 2, that doesn't help you because the jump from 2 to 12 is a distance of 10, not 7. Because you need a very specific, exact past landing pad (5), you must store the exact sums in your map so you can look for that exact number.The Second Problem (Divisibility: Subarray Sum Divisible by 5)In this problem, you don't care about an exact chunk size. You are happy with a chunk of size 5, a chunk of size 10, a chunk of size 15, a chunk of size 20, etc. Anything in the 5-times table is a winner.Let's use our example:Turn 1: Your total steps = 2.Turn 2: You walk 10 more steps. Your total steps = 12.The gap between Turn 1 and Turn 2 is 10 ($12 - 2 = 10$). Since 10 is a multiple of 5, the subarray between Turn 1 and Turn 2 is a winner!But how does a computer recognize that a jump from 2 to 12 is a multiple of 5 without doing a nested loop?It uses a mathematical trick: Look at the remainders when divided by 5.For 2: $2 \div 5 = 0$ with a remainder of 2.For 12: $12 \div 5 = 2$ with a remainder of 2.Notice how both numbers leave behind a remainder of 2? That is not a coincidence! Whenever two running totals have the exact same remainder, it means the distance between them has to be a perfect multiple of 5. The "extra change" (the remainder of 2) cancels itself out.Why storing currentSum breaks this logicIf you stored currentSum in your map for the divisibility problem, your map at Turn 2 would look like this: {2: 1 cone}.When you land on 12, how would your code know that it should look for a 2?If it tried to do the old exact math (currentSum - k), it would calculate $12 - 5 = 7$, and search the map for a 7. But you never stood on 7! Your map doesn't have a 7. It has a 2. Your code would say, "No path found!" and completely miss the perfect chunk of 10.To fix this, you stop tracking the exact sums (2 and 12). Instead, you strip away the multiples of 5 and only save the remainder.On Turn 1 (Total 2), you save it under the label Remainder 2.On Turn 2 (Total 12), you calculate your current remainder, which is 2.Now you look at your map and ask a simple question: "Have I ever seen a Remainder 2 before?" The map says: "YES!" By matching the remainder 2 with the past remainder 2, the code instantly knows—with 100% mathematical certainty—that the space between those two points is perfectly divisible by 5, even though it has absolutely no idea what the exact sums actually were!