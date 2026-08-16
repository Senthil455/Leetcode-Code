bool isHappy(int n) {
    int temp=n, sum=0;
    while(temp!=1 && temp!=4){
        sum=0;
        while(temp!=0){
            sum+=(temp%10)*(temp%10);
            temp/=10;
        }
        temp=sum;
    }
    return temp==1;
}