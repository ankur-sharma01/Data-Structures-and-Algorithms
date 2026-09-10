#include<iostream>
#include<vector>
using namespace std;

// vector<vector<int>> --- a 2D vector, like a matrix.

void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans, vector<vector<bool>> & vis) {
    int n = mat.size();
    // base case
    if(r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || vis[r][c] == true) {
        return;
    }

    if(r == n-1 && c == n-1) {
        ans.push_back(path);
        return;
    }

    vis[r][c] = true;

    helper(mat, r+1, c, path+"D", ans, vis);
    helper(mat, r-1, c, path+"U", ans, vis);
    helper(mat, r, c-1, path+"L", ans, vis);
    helper(mat, r, c+1, path+"R", ans, vis);

    vis[r][c] = false;
}

vector<string> findpath(vector<vector<int>> &mat) {
    int n = mat.size();

    vector<string> ans;
    string path = "";
    vector<vector<bool>> vis(n, vector<bool> (n, false));

    helper(mat, 0, 0, path, ans, vis);

    return ans;
}


// second approach - optimisation.
void helper1(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans) {
    int n = mat.size();
    // base case
    if(r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1) {
        return;
    }

    if(r == n-1 && c == n-1) {
        ans.push_back(path);
        return;
    }

    mat[r][c] = -1;
    // vis[r][c] = true;

    helper(mat, r+1, c, path+"D", ans);
    helper(mat, r-1, c, path+"U", ans);
    helper(mat, r, c-1, path+"L", ans);
    helper(mat, r, c+1, path+"R", ans);

    // vis[r][c] = false;
    mat[r][c] = 1;
}

vector<string> findpath1(vector<vector<int>> &mat) {
    int n = mat.size();

    vector<string> ans;
    string path = "";
    

    helper1(mat, 0, 0, path, ans);

    return ans;
}