char* decodeString(char* s) {
    int len = strlen(s);
    char *stack = calloc(1,10000);
    int top = -1;
    int countStack[1000];
    int countTop = -1;
    char temp[10000];
    int i=0;
    while(i<len){
        int num = 0;
        if(s[i]>='0' && s[i]<='9'){
            while(s[i]>='0' && s[i]<='9'){
                num = num*10 + s[i]-'0';
                i++;
            }
            countStack[++countTop] = num;
        }
        else if(s[i]=='['){
            stack[++top] = s[i];
            i++;
        }
        else if(s[i]==']'){
            int ind = 0;
            while(stack[top]!='['){
                temp[ind++] = stack[top--];
            }
            temp[ind]='\0';
            top--;
            int count = countStack[countTop--];
            for(int c=0;c<count;c++)
            {
                for(int j=ind-1;j>=0;j--)
                {
                    stack[++top]=temp[j];
                }
            }
            i++;
        }
        else{
            stack[++top] = s[i];
            i++;
        }
    }
    stack[++top]='\0';
    return stack;
}