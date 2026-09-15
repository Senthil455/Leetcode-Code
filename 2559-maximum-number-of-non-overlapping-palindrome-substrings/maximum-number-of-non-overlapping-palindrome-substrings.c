bool isPalindrome(char* s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int maxPalindromes(char* s, int k) {
    int n = strlen(s);
    int count = 0;
    int lastEnd = 0;

    for (int right = k - 1; right < n; right++) {
        int left = right - k + 1;

        bool add =
            (left >= lastEnd && isPalindrome(s, left, right)) ||
            (left > lastEnd && isPalindrome(s, left - 1, right));

        if (add) {
            count++;
            lastEnd = right + 1;
        }
    }

    return count;
}