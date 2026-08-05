
int* partitionLabels(char* s, int* returnSize) 
{
   int k=0,n;
   int *res=malloc(strlen(s)*sizeof(int));
   n=strlen(s);
   int freq[26];
for(int i=0;i<26;i++)
    freq[i] = -1;
//stores last occurence of each variable 
for(int i=0;i<n;i++)
{
   freq[s[i]-'a']=i;
}
   int start=0,end=0;
   
   for(int i=0;i<n;i++)
   {
    if(freq[s[i]-'a']>end)
    {
        end=freq[s[i]-'a'];
    }
    if(i==end)
    {
        res[k++]=end-start+1;
        start=i+1;
    }
   }
   *returnSize=k;
   return res;
}