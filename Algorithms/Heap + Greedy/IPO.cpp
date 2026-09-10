// LC 502: IPO
// Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

// You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

// Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

// Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

// The answer is guaranteed to fit in a 32-bit signed integer.

// Example 1:

// Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
// Output: 4
// Explanation: Since your initial capital is 0, you can only start the project indexed 0.
// After finishing it you will obtain profit 1 and your capital becomes 1.
// With capital 1, you can either start the project indexed 1 or the project indexed 2.
// Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
// Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.


class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> proj;
        int i;
        for(i = 0; i < n; i++)
        {
            proj.push_back({capital[i], profits[i]});
        }
        sort(proj.begin(), proj.end());
        
        priority_queue<int> pq;
        int idx = 0;
        while(k--)
        {
            while(idx < n)
            {
                if(proj[idx].first > w) break;
                // else
                pq.push(proj[idx].second);
                idx++;
            }
            if(pq.empty()) return w;

            w = w + pq.top();
            pq.pop();
        }
        return w;
    }
};

// dry run:
// Let's trace a small example step-by-step to see how `k`, `w`, `idx`, and the heap `pq` interact.

// ### Tracing Setup

// * **Capital needed:** `[0, 1, 1, 3]`
// * **Profits:** `[10, 20, 30, 100]`
// * **Initial Capital ($w$):** `1`
// * **Max projects allowed ($k$):** `3`

// After pairing and sorting by capital:

// * `proj[0] = {0, 10}`
// * `proj[1] = {1, 20}`
// * `proj[2] = {1, 30}`
// * `proj[3] = {3, 100}`

// ---

// ### Step-by-Step Execution

// #### **BEFORE LOOPS START:**

// * `w = 1`
// * `k = 3`
// * `idx = 0`
// * `pq = []`

// ---

// #### **ROUND 1 ($k = 3 \to 2$):**

// 1. **Inner `while` loop starts checking at `idx = 0`:**
// * **Check `proj[0]`:** Capital required is `0`. Is `0 <= w (1)`? **YES.**
// * Push profit `10` into `pq`.
// * `idx` becomes `1`.


// * **Check `proj[1]`:** Capital required is `1`. Is `1 <= w (1)`? **YES.**
// * Push profit `20` into `pq`.
// * `idx` becomes `2`.


// * **Check `proj[2]`:** Capital required is `1`. Is `1 <= w (1)`? **YES.**
// * Push profit `30` into `pq`.
// * `idx` becomes `3`.


// * **Check `proj[3]`:** Capital required is `3`. Is `3 <= w (1)`? **NO!**
// * **Inner loop stops here.**




// 2. **State right now:**
// * `idx = 3`
// * `pq = [30, 20, 10]` *(30 is at top)*


// 3. **Pick the best project:**
// * Add top profit (`30`) to capital: $w = 1 + 30 = \mathbf{31}$.
// * Remove `30` from `pq`.
// * `pq` is now `[20, 10]`.



// ---

// #### **ROUND 2 ($k = 2 \to 1$):**

// 1. **Inner `while` loop starts checking from `idx = 3` (where it paused):**
// * **Check `proj[3]`:** Capital required is `3`. Is `3 <= w (31)`? **YES.**
// * Push profit `100` into `pq`.
// * `idx` becomes `4`.


// * `idx == 4` (reached the end of array `n=4`).
// * **Inner loop stops.**




// 2. **State right now:**
// * `idx = 4`
// * `pq = [100, 20, 10]` *(100 is at top)*


// 3. **Pick the best project:**
// * Add top profit (`100`) to capital: $w = 31 + 100 = \mathbf{131}$.
// * Remove `100` from `pq`.
// * `pq` is now `[20, 10]`.



// ---

// #### **ROUND 3 ($k = 1 \to 0$):**

// 1. **Inner `while` loop starts checking from `idx = 4`:**
// * `idx < n` (`4 < 4`) is **FALSE**.
// * **Inner loop does 0 iterations and immediately exits!**


// 2. **State right now:**
// * `idx = 4`
// * `pq = [20, 10]` *(20 is at top)*


// 3. **Pick the best project:**
// * Add top profit (`20`) to capital: $w = 131 + 20 = \mathbf{151}$.
// * Remove `20` from `pq`.
// * `pq` is now `[10]`.



// ---

// #### **END OF PROGRAM:**

// * Loop ends because `k = 0`.
// * Final Output $w = \mathbf{151}$.

// ---

// ### What to Notice Here

// 1. In **Round 1**, the inner loop ran **3 times** (`idx` moved $0 \to 1 \to 2 \to 3$).
// 2. In **Round 2**, the inner loop ran **1 time** (`idx` moved $3 \to 4$).
// 3. In **Round 3**, the inner loop ran **0 times** (it was skipped because `idx` was already at the end).

// The inner loop executes on every round, but `idx` only travels forward through the array **once in total**.