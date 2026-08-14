char* addBinary(char* a, char* b) {
        int n = strlen(a) - 1, m = strlen(b) - 1;
        char* ans = (char*)malloc(fmax(n, m) + 10);
        int carry = 0, ind = 0;

        while (n >= 0 || m >= 0 || carry == 1) {
            
            int digit1 = 0, digit2 = 0;
            if (n >= 0)
                digit1 = a[n--] - '0';
            if (m >= 0)
                digit2 = b[m--] - '0';

            int sum = digit1 + digit2 + carry;
            ans[ind++] = (sum % 2) + '0';
            carry = sum / 2;
        }

        ans[ind] = '\0';

        int start = 0, end = strlen(ans) - 1;
        while (start < end) {

            char temp = ans[start];
            ans[start] = ans[end];
            ans[end] = temp;

            start++;
            end--;
        }

        return ans;
}