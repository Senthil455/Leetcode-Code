int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

bool closeStrings(char* word1, char* word2)
{
    int i,m1=0,m2=0;
    int list1[26]={0};
    int list2[26]={0};
    int n=(int)strlen(word1);
    if(n!=strlen(word2))
    {
        return false;
    }
    for(i=0;i<n;i++)
    {
        list1[word1[i]-'a']++;
        list2[word2[i]-'a']++;
        m1|=1<<(word1[i]-'a');
        m2|=1<<(word2[i]-'a');
    }
    if(m1!=m2)
    {
        return false;
    }
    qsort(list1,26,sizeof(int),cmp);
    qsort(list2,26,sizeof(int),cmp);
    return !memcmp(list1,list2,sizeof(list1));
}