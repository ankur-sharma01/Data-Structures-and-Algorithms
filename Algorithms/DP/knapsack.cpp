// 

class solution{
    public:
        int fun(vector<int> &nums, vector<int> &weight, int NoOfItems, int current, int capacityLeft, vector<vector<int>> &dp){
            // NoOfItems = nums.size();

            // base case:
            if(current >= NoOfItems) return 0;

            // find for the value of fun in the dp stored:
            if(dp[current][capacityLeft] != -1){
                return dp[current][capacityLeft];
            }

            // skip to (current + 1) if the current is more than the capacityLeft:
            if(weight[current] > capacityLeft) {
                return dp[current][capacityLeft] = fun(nums, weight, NoOfItems, current + 1, capacityLeft, dp);
            }

            // calculates if we take the current into our resultant sum:
            int taken = nums[current] + fun(nums, weight, NoOfItems, current + 1, capacityLeft - weight[current], dp);

            // calculation for the path if did not take current into our resultant sum:
            int notTaken = 0 + fun(nums, weight, NoOfItems, current + 1, capacityLeft, dp);

            return dp[current][capacityLeft] = max(taken, notTaken);
        }

        int main1(vector<int> &nums, vector<int> &weight, int capacityLeft) {
            int NoOfItems = nums.size();

            vector<vector<int>> dp(NoOfItems, vector<int>(capacityLeft+1, -1));

            return fun(nums, weight, NoOfItems, 0, capacityLeft, dp);
        }
};