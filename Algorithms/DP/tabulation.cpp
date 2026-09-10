// less space usage and less time realistically.

// converting recursive path into for loops.

// simple fibonacci using recursion:
int fibonacci(vector<int> &nums, int i){

    if(i == 0 || i == 1) return i;
    
    int ans = fibonacci(nums, i-1) + fibonacci(nums, i-2);

    return ans;
}

// converting it to for loop:
int fibonacci(int n){
    if(n == 0 || n == 1) return n;
    vector<int> ans(n+1);
    ans[0] = 0;
    ans[1] = 0

    for(int i = 2; i < n ; i++) {
        ans[i] = nums[i-1] + nums[i-2];
    }

    return ans[n];
}

// now the space saving method: we are using past 2 values only then why we store full vector array for this? we can just use variables and update them after each iteration. ---- tabulation with space saving.

int fibonacci(int destiny) {

    if(destiny == 0 || destiny == 1) return destiny;

    int prev = 1;
    int prev_prev = 0;
    int ans = 0;
    for(int i = 2; i <= 5; i++) {
        ans = prev + prev_prev;
        prev_prev = prev;
        prev = ans;
    }

    return ans;
}

// :: --- scope resolution operator can only be used for global variables and not for any item present in any function including main().