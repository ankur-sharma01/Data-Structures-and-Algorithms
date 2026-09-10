// count elements and re-write the array. -- two pass

// best approach - two pointer --- one pass.
int low = 0;
int mid = 0;
int high = nums.size() - 1;

while(mid <= high) {
    if(nums[mid] == 2){
        swap(nums[mid], nums[high]);
        high--;
    } else if(nums[mid] == 0) {
        swap(nums[mid], nums[low]);
        mid++;
        low++;
    } else if(nums[mid] == 1){
        mid++;
    }
}

// time exceeded:   (another approach) --- partially wrong
int high = 2;
int low = 0;

int start = 0;
int end = nums.size() - 1;

for(int i = 0; i < nums.size(); i++) {

    if(nums[i] == low){
        swap(nums[i], nums[start]);
        start++;
    }
    if(nums[i] == high && nums[end] != 2) {
        swap(nums[i], nums[end]);
        end--;
    } else {
        end--;
        i--;
    }
}
// return nums;
