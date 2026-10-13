// we create a z-array: how many elements starting at index i in a string match from the start of the string.

// brute force method to generate a z-array:
vector<int> calculateZBruteForce(string s) {
    int n = s.length();
    vector<int> z(n, 0);
    z[0] = n;

    for (int i = 1; i < n; i++)
    {
        int count = 0;
        while (i + count < n && s[i] == s[i + count])
        {
            count++;
        }
        z[i] = count;
    }
    return z;
}


// optimal approach:
vector<int> calculateZoptimal(string s) {
    
    int n = s.length();
    vector<int> z(n, 0);
    int L = 0, R = 0;

    for (int i = 1; i < n; i++)
    {
        // step 1: if inside the z-box, inherit from the twin safely
        if (i <= R)
        {
            z[i] = min(R - i + 1, z[i - L]);
        }

        // step 2: try to expand the match character-by-character
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }

        // step 3: if our match stretches past R, update the z-box [L, R]
        if (i + z[i] - 1 > R)
        {
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}