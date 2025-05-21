int lengthOfLongestSubstring(char* s) {
    int ans = 0, obs = 0, dup = 0, p1 = 0, p2 = 0;
        
    while (s[p2] != '\0') {
        obs++; 

        for (int i = p1, mov = 1; i < p2; i++, mov++) {
            if (s[i] == s[p2]) { // Duplicate was found
                obs -= mov;
                p1 += mov;
            }
        }

        if (obs > ans)
            ans = obs;

        p2++;
    }

    return ans;
}
