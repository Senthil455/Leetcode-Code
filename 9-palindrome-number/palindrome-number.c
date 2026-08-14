bool isPalindrome(int x) {
    int temp = x;
    long int d,r=0;
    bool test;
    while(x>0)
    {
        d = x%10;
        r = r * 10 + d;
        x/=10;
    }
    test = temp == r ? true : false ;
    return test;
}