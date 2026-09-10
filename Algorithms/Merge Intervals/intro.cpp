// range/intervals/start-end given
// keywords: overlap, conflict, merge, freetime, simultaneous usage, load, rooms, cpu, meetings
// needs to sort first and then apply logic.

// LC 56

vector<vector<int>> intervals;
vector<vector<int>> result;

int n = intervals.size();

if(intervals.empty()) return {};
sort(intervals.begin(), intervals.end());

int start1 = intervals[0][0];
int end1 = intervals[0][1];

for(int i = 1; i < n; i++) {
    int start2 = intervals[i][0];
    int end2 = intervals[i][1];

    if(end1 >= start2) {
        end1 = max(end1, end2);
    } else {result.push_back({start1, end1});
    start1 = start2;
    end1 = end2;
    }
}
result.push_back({start1, end1});
return result;