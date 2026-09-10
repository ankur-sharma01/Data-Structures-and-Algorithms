// LC 253: MEETING ROOMS 2


vector<int> start;
vector<int> end;
int result;
int rooms;

int n = start.size();
int m = end.size();

sort(start.begin(), start.end());
sort(end.begin(), end.end());

int i = 0, j = 0;

while(i < n && j < m) {
    if(start[i] < end[j]) {
        rooms++;
        result = max(result, rooms);
        i++;
    } else {
        rooms--;
        j++;
    }
}
return result;