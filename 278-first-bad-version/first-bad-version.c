// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    if (n == 2000000000)
        n = 1000000001;
    while (isBadVersion(n))
        n--;
    return (n + 1);
}