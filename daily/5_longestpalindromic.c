char* longestPalindrome(char* s) {
    int p1, p2, count = 0, ans = 0;
    int size = sizeof(s) / sizeof(s[0]);

    for (int i = 0; i <= size; i++) {
        for (int j = i; j <= size; j++) {
            p1 = i, p2 = j;
            while (p1 < j && p2 > i) { // While within the sliding window
                if (s[p1] != s[p2]) {
                    count = 0;
                    break;
                }

                count += 2;
            }
        }
    }

    return ans;
}
