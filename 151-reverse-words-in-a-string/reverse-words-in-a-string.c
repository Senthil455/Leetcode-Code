void reverse(char *ch,int begin,int end)
{
    while(begin<end)
    {
        char temp=ch[begin];
           ch[begin]=ch[end];
           ch[end]=temp;
           end--;
           begin++;
    }
}
char* reverseWords(char* s) {
     char *fin=malloc(strlen(s)+1);
       int i=0,j=0,space=0;
    //SKIPPING LEADING SPACES
    while(s[i]==' ')
        i++;
    //REMOVING EXTRA SPACES
    while(s[i] != 0)
    {
        if(s[i] != ' ')
        {
           fin[j++]=s[i];
            space=0;
        }
        //ONE SPACE AFTER EACH WORD
        else if(!space)
        {
            fin[j++]=' ';
            space=1;
        } 
        i++;
    }
   //REMOVING TRAILING SPACES (If-any)
    if(j>0 && fin[j-1]==' ')
        j--;
    fin[j]='\0';
    int start=0;
    //LOCAL REVERSE
    int len=strlen(fin);
     for(i=0; i<=len;i++)
     {
         if(fin[i]==' ' || fin[i]=='\0')
         {
              reverse(fin,start,i-1);
             start=i+1;
         }
     }
    //GLOBAL REVERSE
    i=0;
    j=strlen(fin)-1;
    reverse(fin,i,j);
    return fin;
}