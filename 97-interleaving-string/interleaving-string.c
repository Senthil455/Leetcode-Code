int memo[101][101];

bool checker(char *s1, char *s2, char *s3, int p1, int p2, int p3, int len1, int len2, int len3)
{
    if (p1 == len1 && p2 == len2 && p3 == len3)
        return true;
    if (p3 == len3)
        return false;
    if (memo[p1][p2] != -1)
        return memo[p1][p2];

    bool path1 = false;
    bool path2 = false;

    if (s1[p1] == s3[p3])
    {
        memo[p1][p2] = checker(s1, s2, s3, p1 + 1, p2, p3 + 1, len1, len2, len3);
        path1 = memo[p1][p2];
    }

    if (s2[p2] == s3[p3])
    {
        memo[p1][p2] = checker(s1, s2, s3, p1, p2 + 1, p3 + 1, len1, len2, len3);
        path2 = memo[p1][p2];
    }

    return path1 || path2;
}

bool isInterleave(char * s1, char * s2, char * s3){
    memset(memo, -1, sizeof(memo));
    return checker(s1, s2, s3, 0, 0, 0, strlen(s1), strlen(s2), strlen(s3));
}