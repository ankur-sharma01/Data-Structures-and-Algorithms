// choose the best option first.

// LC 860: Lemonade Change
// At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
// Note that you do not have any change in hand at first.
// Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.
// EXAMPLE:
// Input: bills = [5,5,5,10,20]
// Output: true
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change, we output true.


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        for (int i = 0; i < n; i++)
        {
            int money = bills[i];
            if (money == 5)
            {
                five++;
            } else if (money == 10)
            {
                if (five == 0)
                    return false;

                five--;
                ten++;
            } else
            {
                if (ten > 0)
                {
                    ten--;
                    if (five == 0)
                        return false;

                    five--;
                } else 
                {
                    if (five < 3)
                        return false;

                    five -= 3;
                }
            }
        }
        return true;
    }
};


// LC 455: Assign Cookies
// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
// EXAMPLE:
// Input: g = [1,2,3], s = [1,1]
// Output: 1
// Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
// And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
// You need to output 1.


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size())
        {
            if (s[j] >= g[i])
            {
                res++;
                i++;
                j++;
            } else
            {
                j++;
            }
        }
        return res;
    }
};


// LC 55: Jump Game
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.
// EXAMPLE:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (reach < i)
                return false;

            reach = max(reach, i + nums[i])

            if (reach >= nums.size() - 1)
                return true;
        }
    }
};


// GFG Fractional Knapsack
// Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
// Return the maximum value as a double, rounded to 6 decimal places.

// Examples :

// Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
// Output: 240.000000
// Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240


struct item {
    double value;
    double weight;
    double ratio;
};

double fractionalKnapsack(int* val, int* wt, int n, int capacity) {
    int n = val.size();
    vector<item> items(n);

    for (int i = 0; i < n; i++)
    {
        items[i] = {(double)val[i], (double)wt[i], (double)val[i]/wt[i]};
    }

    sort(items.begin(), items.end(), [](const item& a, const item& b) {
        return a.ratio > b.ratio;
    });

    double totalValue = 0.0;
    double currentCapacity = capacity;

    for (int i = 0; i < n; i++)
    {
        if (currentCapacity == 0) break;

        if (items[i].weight <= currentCapacity) {
            totalValue = totalValue + items[i].value;
            currentCapacity = currentCapacity - items[i].weight;
        } else
        {
            totalValue = totalValue + items[i].ratio * currentCapacity;
            currentCapacity = 0;
        }
    }
    return totalValue;
}