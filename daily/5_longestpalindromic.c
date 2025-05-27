char* longestPalindrome(char* s) {
    int ls, rs, l, r, count, top = 0;
    int size = strlen(s);
    char *ans = (char *)malloc(2 * sizeof(char));

    ans[0] = s[0];
    ans[1] = '\0';

    if (size > 1) {
        for (int i = 0; i < size; i++) { // i holds window size
            for (ls = 0, rs = i; rs < size; rs++, ls++) { // Moves window
                count = 0;
                l = ls, r = rs;

                while (l <= r && l < size && r > 0) {
                    if (s[l] == s[r])
                        count = (l != r) ? count + 2 : count + 1;
                    else {
                        count = 0;
                        break;
                    }
                    l++, r--;
                }

                if (count > top) {
                    top = count;
                    ans = (char *)malloc((top + 1) * sizeof(char));

                    for (int j = ls, k = 0; j <= rs; j++, k++) {
                        ans[k] = s[j];
                    }
                    ans[top] = '\0';
                }
            }
        }
    }

    return ans;
}
