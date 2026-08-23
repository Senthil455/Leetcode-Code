#include <string.h>

char* countAndSay(int n)
{
    if(n==1)
    {
        char* base = (char*)malloc(2);
        base[0] = '1';
        base[1] = '\0';
        return base;
    }
    char *retStr=countAndSay(n-1);
    int len=strlen(retStr);
    char *curStr=(char*)malloc(2*(len+1));
    int a=0;
    int count=1;
    for(int i=1;i<=len;i++)
    {
        if(i<len&&retStr[i]==retStr[i-1])
        {
            count++;
            continue;
        }
        else
        {
            curStr[a++]=count+'0';
            curStr[a++]=retStr[i-1];
            count=1;
        }
    }
    curStr[a] = '\0';
    free(retStr);
    return curStr;
}