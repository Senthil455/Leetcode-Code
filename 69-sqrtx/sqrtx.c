int mySqrt(int x){
    if(x==0) return 0;
    long l=1,r=x,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(mid*mid==x) return mid;
        else if(mid*mid<x) l=mid+1;
        else r=mid-1;
    }
    return r;
}
