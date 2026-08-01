int guess(int num);

int guessNumber(int n){
    int start = 1, last = n, mid;
    while (1){
    mid = start + (last - start) / 2;
        switch(guess(mid)){
            case 0:
                return mid;
            case 1:
                start = mid + 1;
                break;
            case -1:
                last = mid -1;
                break;
        }

    }
	
}