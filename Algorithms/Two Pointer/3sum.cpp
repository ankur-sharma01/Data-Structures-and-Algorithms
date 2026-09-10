// logic:

// arr[] = [a,b,c,d,e];

vector<vector<int>> ans;
    // wrong approach --- Imagine the input is [1, 2, -1, -1, 0].
    // A valid triplet is {-1, -1, 2}.
    // use two pointer(below this code).
    for(int i = 1; i < nums.size(); i++){

        int result = nums[0] + nums[i] + nums[i + 2];
        if(result == 0){
            ans.push_back({nums[0], nums[i], nums[i+2]});
        }
    }
    return ans;


    // TWO POINTER: --- CONVERSION TO TWO SUM: SUM OF TWO NUMBER GIVING THIRD NUMBER(-VE VALUE).

vector<vector<int>> result;
sort(nums.begin(), nums.end());
int n = nums.size();


for(int i = 0; i < n - 2; i++){
    if(i > 0 && nums[i] == nums[i-1]) continue;
    // int target = 0;
    int s = -1*nums[i];
    int left = i + 1;
    int right = n - 1;

    
    while(left < right) {

        int sum = nums[left] + nums[right];

        if(sum == s){
            result.push_back({nums[i], nums[left], nums[right]});
            left++;
            right--;
            while(left < n && nums[left] == nums[left-1]){
                left++;
            }
            while(right >= 0 && nums[right+1] == nums[right]){
                right--;
            }
        } else if(sum < s){
            left++;
        } else if(sum > s){
            right--;
        }
    }
}
return result;


// closest to 3 sum:

// vector<vector<int>> result;
sort(nums.begin(), nums.end());
int n = nums.size();
int closestSum = 0;
int max_diff = INT_MAX;

for(int i = 0; i < n - 2; i++){
    if(i > 0 && nums[i] == nums[i-1]) continue;
    // int target;
    
    int left = i + 1;
    int right = n - 1;

    
    while(left < right) {

        int sum = nums[left] + nums[right] + nums[i];

        int currentDiff = abs(target - sum);

        if(currentDiff < max_diff){
                max_diff = currentDiff;
                closestSum = sum;
            }


        if(sum == target){
            // if(currentDiff < max_diff){
            //     max_diff = currentDiff;
            //     closestSum = sum;
            // }
            return sum;

            // no duplicacy check needed:
            
            // while(left < n && nums[left] == nums[left-1]){
            //     left++;
            // }
            // while(right >= 0 && nums[right+1] == nums[right]){
            //     right--;
            // }
        } else if(sum < target){

            left++;

        } else if(sum > target){

            right--;

        }
    }
}
return closestSum;



// 3 sum smaller(triplet smaller):
sort
find total sum

for(int i = 0; i < n - 2; i++)