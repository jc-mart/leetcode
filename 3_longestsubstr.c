int lengthOfLongestSubstring(char* s) {
    int ans = 0, obs = 0, dup = 0, p1 = 0, p2 = 0, size = 0;

    while (s[p1] != '\0')
        p1++;

    size = p1; // Does not count null operator
    p1 = 0;
    p2++;
    printf("Size: %d\n", size);

    if (size != 0) {
        obs++, ans++;
        for (; size - p2 >= ans; p2++, obs++) {
            for (int i = p1 + 1; i <= p2; i++) {
                if (s[i] == s[p1]) {
                    printf("Found dupe\n");
                    dup++;
                    // break;
                }
            }

            if (dup) {
                printf("Elimniating dupe\n");
                p1++;
                obs--;
                dup--;
            }


            if (obs > ans)
                ans = obs;

            printf("ans: %d, obs: %d, dup: %d, p1: %d, p2: %d\n",
                    ans, obs, dup, p1, p2);
        }
    }

    return ans;
}
