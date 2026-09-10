// LC 739

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        stack<int> st;
        int n = temperatures.size();

        for(int i = n-1; i >= 0; i--) {
            int count = 0;
            while(!st.empty()) {
                st.top() = temperatures[i];
            }

            while(!st.empty() && st.top() <= temperatures[i]) {
                count++;
                st.pop();
            }
            res.push_back(count+1);
            st.push(temperatures[i]);
        }
        return res;
    }
};



// brute force method:

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (temperatures[j] > temperatures[i]) {
                    res[i] = j - i;
                    break; // Found the closest warmer day, move to next day
                }
            }
        }
        return res;
    }
};

// optimal solution:
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n, 0);
        res[n-1] = 0;
        st.push(n-1);
        
        for(int i = n-2; i >= 0; i--) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if(st.empty()) {
                res[i] = 0;
            } else {
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
};