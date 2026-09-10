// You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

// nums is considered continuous if both of the following conditions are fulfilled:

// All elements in nums are unique.
// The difference between the maximum element and the minimum element in nums equals nums.length - 1.
// For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

// Return the minimum number of operations to make nums continuous.

// we will track the highest number which our array should contain to be continuous, anything more than that makes uncontinuous.

// int n = nums.size(); --- no need of this as we are deduplicating things which will reduce the size so size can't be fixed from start.

int high = 0, low = 0;
int max_kept = INT_MIN;
int n = nums.size(); // don't use it in for loop to avoid previous size stored issue, new size is different after deduplication.

sort(nums.begin(), nums.end());

// de duplicating: using unique, it gathers the unique data together at front and then intialises it at the first duplicate element, nums.erase() erases it.
auto it = unique(nums.begin(), nums.end());
nums.erase(it, nums.end());

for(high = 0; high < nums.size(); high++) {

    // this is the only math needed for this.
    int MaxNoAllowed = nums[low] + n - 1;
    // (or) --- auto maxNoAllowed = [&]() { return nums[low] + n - 1; };

    while(MaxNoAllowed < nums[high]) {
        low++;
        MaxNoAllowed = nums[low] + n - 1;
    }

    int size = high - low + 1;
    max_kept = max(max_kept, size);
    // calculating total no. of operations = n - max_kept.
    totalOps = n - max_kept;
}
return totalOps;
