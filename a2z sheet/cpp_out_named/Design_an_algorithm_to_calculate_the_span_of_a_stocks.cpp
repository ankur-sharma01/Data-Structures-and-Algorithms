/*
 * QUESTION:
 *
 * Design an algorithm to calculate the span of a stock's price for the current day based on the price history.
 *
 * Find it: https://www.google.com/search?q=Design%20an%20algorithm%20to%20calculate%20the%20span%20of%20a%20stock%27s%20price%20for%20the%20current%20day%20based%20on%20the
 */

// ---- write your solution below ----

// brute-force approach:
class StockSpanner {
private:
    std::vector<int> prices; // Simple list to store all incoming prices

public:
    StockSpanner() {}
    
    int next(int price) {
        // 1. Add today's price to our history
        prices.push_back(price);
        
        int span = 0;
        int n = prices.size();
        
        // 2. Walk backward from today (n - 1) to the beginning (0)
        for (int i = n - 1; i >= 0; i--) {
            if (prices[i] <= price) {
                span++; // Count it if it's less than or equal
            } else {
                break; // Stop immediately when we hit a higher price wall
            }
        }
        
        return span;
    }
};

// optimal approach: using stack for storage and popping!
class StockSpanner {
public:
    // stack with pair --> {price, total_span_for_current_price}
    stack<pair<int,int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1; // span = 1 for current element!!!

        while (!st.empty() && price >= st.top().first)
        {
            // engulf wverything unless the condition reverses:
            span = span + st.top().second;
            st.pop();
        }

        st.push({price, span}); // if goes inside while block than updated span is used otherwise span remains 1!!

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
