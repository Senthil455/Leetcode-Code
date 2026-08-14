int hammingWeight(int n) {
    int c=0;
        while(n>0)
        {
            int r=n%2;
            if(r==1)
            {
                c++;
            }
            n=n/2;
        }
        return c;
}