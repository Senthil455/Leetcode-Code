int convert(const int bits[32]) {
    uint32_t out = (uint32_t)bits[31];
    for (int i = 0; i < 31; i++) {
        out += ((uint32_t)bits[i] << (31 - i));
    }
    return out;
}
int reverseBits(int n) {
    int bits[32] = {0};
    int i = 0;
    uint32_t num = n;

    while (num != 0 && i < 32) {
        int rem = (int)(num & 1u);  
        bits[i] = rem;
        num >>= 1;                  
        i++;
    }

    return convert(bits);
}