// LC 287 -- find the duplicate number

class Solution{
public:
    int duplicate(vector<int> &nums){
        int slow = 0, fast = 0;

        while(true) {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if(slow == fast) {
                slow = 0;
                while(slow != fast) {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
    }
};

// LC 202 -- happy number

// we are using slow-fast pointer because we have to match the condition of becoming 1.

// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

class Solution {
public:

    int add(int n) {
        int sum = 0;
        while(n > 0) {
            int d = n%10;
            n = n/10;
            sum += d*d;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;

        while(fast != 1) {
            slow = add(slow);
            fast = add(fast);
            fast = add(fast);

            if(slow == fast && slow != 1) return false; 
        }
        return true;
    }
};