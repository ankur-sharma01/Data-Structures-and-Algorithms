/*
 * QUESTION:
 *
 * Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
 * - Only numbers 1 through 9 are used.
 * - Each number is used at most once.
 * Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
 *
 * Example:
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * Explanation: 1 + 2 + 4 = 7. There are no other valid combinations.
 *
 * Find it: https://www.google.com/search?q=Find%20all%20valid%20combinations%20of%20k%20numbers%20that%20sum%20up%20to%20n%20such%20that%20the%20following%20conditions%20are
 */

// ---- write your solution below ----

class Solution {
public:
    void fun(vector<int> candidates, int n, int i, vector<int>& diary, int sum, vector<vector<int>>& res, int target) {

        if (sum == target)
        {
            res.push_back(diary);
            return;
        }

        // 2nd base case:
        if (i == n || sum > target)
            return;
        
        // nahi lenge: also skipping duplicates
        int next_i = i+1;
        while (next_i < n && candidates[next_i] == candidates[i])
        {
            next_i++;
        }
        fun(candidates, n, next_i, diary, sum, res, target);

        // lenge:
        if (candidates[i] + sum <= target)
        {
            diary.push_back(candidates[i]);
            sum = sum + candidates[i];

            fun(candidates, n, i+1, diary, sum, res, target);

            diary.pop_back();
            sum = sum - candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int i = 0;
        int n = candidates.size();
        vector<int> diary;
        vector<vector<int>> res;

        sort(candidates.begin(), candidates.end());
        fun(candidates, n, 0, diary, 0, res, target);

        return res;
    }
};

// another type of code:
class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int i, vector<int>& currentPath, vector<vector<int>>& res) {
        // base case:
        if (target == 0)
        {
            res.push_back(currentPath);
            return;
        }

        for (int j = i; j < candidates.size(); j++)
        {
            if (candidates[j] > target)
                break; // as candidates is sorted --- every element after this will be greater --- optimization

            if (j > i && candidates[j] == candidates[j+1])
                continue;

            currentPath.push_back(candidates[i]);

            backtrack(candidates, target-candidates[j], j+1, currentPath, res);

            currentPath.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> currentPath;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, currentPath, res);

        return res;
    }
}



// lc 39 solution: combination sum!
class Solution {
public:
    void fun(vector<int>& candidates, int target, int i, vector<vector<int>>res, vector<int>& diary, int n, int sum) {
        if (i == n)
        {
            if (sum == target)
            {
                res.push_back(diary);
            }
            return;
        }

        // nahi lenge:
        fun(candidates, target, i+1, res, diary, n, sum);

        // lenge:
        if (candidates[i] + sum <= target)
        {
            diary.push_back(candidates[i]);
            sum = candidates[i] + sum;
            // check again for including!!
            fun(candidates, target, i, res, diary, n, sum);
            // resetting back!
            diary.pop_back();
            sum = sum - candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i = 0;
        int sum = 0;
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> diary;

        fun(candidates, target, i, res, diary, n, sum);

        return res;
    }
};

// alternate solution for the same: lc 39
#include <vector>

class Solution {
private:
    void backtrack(std::vector<int>& candidates, int target, int startIdx, std::vector<int>& currentPath, std::vector<std::vector<int>>& result) {
        
        // 1. Base Case: If target hits 0, we found a valid combination
        if (target == 0) {
            result.push_back(currentPath);
            return;
        }
        
        // 2. Loop of Choices: Iterate through available candidates starting from startIdx
        for (int i = startIdx; i < candidates.size(); ++i) {
            
            // Pruning: Skip if the current candidate exceeds the remaining target
            if (candidates[i] > target) {
                continue; 
            }
            
            // 3. Do: Make the choice
            currentPath.push_back(candidates[i]);
            
            // 4. Recurse: Pass 'i' (not i + 1) to allow reusing the exact same element
            backtrack(candidates, target - candidates[i], i, currentPath, result);
            
            // 5. Undo / Backtrack: Clean up the choice
            currentPath.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentPath;
        
        backtrack(candidates, target, 0, currentPath, result);
        
        return result;
    }
};
