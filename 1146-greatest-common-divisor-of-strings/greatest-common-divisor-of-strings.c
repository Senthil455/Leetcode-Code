int gcd(int a,int b){
    while(b!=0){
        int t=b;          //to find the gcd of two string lengths
        b=a%b;
        a=t;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int a,b,c;
     a=strlen(str1);
    b=strlen(str2);
    char *s = (char*)malloc(a+b + 1);
    char *t = (char*)malloc(a+b+ 1);

    strcpy(s,str1); //copy string1 to s and string2 is add to s
    strcat(s,str2);
    strcpy(t,str2); //copy string2 to t and string1 is add to t
    strcat(t,str1);
    if(strcmp(s,t)!=0) return ""; //compare two strings s and t
   
    c=gcd(a,b);
    char *r=(char *)malloc(c+1); //creating memory for result
    strncpy(r,str1,c);
    r[c]='\0';
    return r;
}