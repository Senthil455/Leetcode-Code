short stack[1001];
void swap(char *a, char *b){
    char t = *a;
    *a = *b;
    *b = t;
}
void reverse(char *s, int end) {
    int start = 0;
    end--;
    while(start < end) {
        swap(&s[start++], &s[end--]);
    }
}
char* reverseParentheses(char* s) {
    int idx = 0, top = 0;
    for(int i = 0; s[i]; i++) {
        switch(s[i]) {
            case '(': 
                    stack[top++] = idx; 
                    break;
            case ')': 
                    top--;
                    reverse(s + stack[top], idx - stack[top]);
                    break;
            default:
                    s[idx++] = s[i];
        }
    }
    s[idx] = '\0';
    return s;
}