// LC 986: Interval List Intersections

vector<vector<int>> firstList;
vector<vector<int>> secondList;
vector<vector<int>> result;

int i = 0, j = 0;
int n = firstList.size(), m = secondList.size();

while(i < n && j < m) {

    int start1 = firstList[i][0];
    int end1 = firstList[i][1];
    int start2 = secondList[j][0];
    int end2 = secondList[j][1];

    if(start1 <= start2) {

        if(end1 >= start2) {
            int s = max(start1, start2);
            int e = min(end1, end2);
            result.push_back({s, e});
        }

    } else {
        
        if(end2 >= start1) {
            int s = max(start1, start2);
            int e = min(end1, end2);
            result.push_back({s, e});
        }
    }

    // Clean, universal intersection formula
    //         int s = max(start1, start2);
    //         int e = min(end1, end2);

    //         if (s <= e) {
    //             result.push_back({s, e});
    //         }

    if(end1 <= end2) {
        i++;
    } else {
        j++;
    }
}
return result;