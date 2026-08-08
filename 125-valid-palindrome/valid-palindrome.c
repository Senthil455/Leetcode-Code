bool isPalindrome(char* s)
{
    int len=strlen(s);
    int i=0;
    int j=len-1;
    while(i<j)
    {
        if(s[i]=='\0' || s[i]=='\n' || s[i]<48 || (s[i]>57 && s[i]<'A') || (s[i]>'Z' && s[i]<'a') || s[i]>'z') i++;
        else if(s[j]=='\0' || s[j]=='\n' || s[j]<48 || (s[j]>57 && s[j]<'A') || (s[j]>'Z' && s[j]<'a') || s[j]>'z') j--;
        else if(s[i]>='A' && s[i]<='Z' && s[j]>='a' && s[j]<='z')
        {
            if((s[i]+32)==s[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        else if(s[j]>='A' && s[j]<='Z' && s[i]>='a' && s[i]<='z')
        {
            if((s[j]+32)==s[i])
            {
                i++;
                j--;
            }
            else return false;
        }
        else if(s[j]>='A' && s[j]<='Z' && s[i]>='A' && s[i]<='Z')
        {
            if(s[j]==s[i])
            {   
                i++;
                j--;
            }
            else return false;
        }
        else
        {
            if(s[j]==s[i])
            {   
                i++;
                j--;
            }
            else return false;
        }
    }
    return true;
}