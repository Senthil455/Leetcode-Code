char* intToRoman(int num) {
    // Allocate enough memory for the result string
    // Max length of Roman numeral for numbers up to 3999 is 15 (e.g., "MMMCMXCIX")
    char* s = (char*)malloc(20 * sizeof(char)); 
    int i = 0;
    
    // Handle the largest values first (greedy approach)
    while (num >= 1000) {
        s[i++] = 'M';
        num -= 1000;
    }
    
    // Check for 900 (CM)
    if (num >= 900) {
        s[i++] = 'C';
        s[i++] = 'M';
        num -= 900;
    }
    
    // Handle 500 (D)
    while (num >= 500) {
        s[i++] = 'D';
        num -= 500;
    }
    
    // Check for 400 (CD)
    if (num >= 400) {
        s[i++] = 'C';
        s[i++] = 'D';
        num -= 400;
    }
    
    // Handle 100 (C)
    while (num >= 100) {
        s[i++] = 'C';
        num -= 100;
    }
    
    // Check for 90 (XC)
    if (num >= 90) {
        s[i++] = 'X';
        s[i++] = 'C';
        num -= 90;
    }
    
    // Handle 50 (L)
    while (num >= 50) {
        s[i++] = 'L';
        num -= 50;
    }
    
    // Check for 40 (XL)
    if (num >= 40) {
        s[i++] = 'X';
        s[i++] = 'L';
        num -= 40;
    }
    
    // Handle 10 (X)
    while (num >= 10) {
        s[i++] = 'X';
        num -= 10;
    }
    
    // Check for 9 (IX)
    if (num >= 9) {
        s[i++] = 'I';
        s[i++] = 'X';
        num -= 9;
    }
    
    // Handle 5 (V)
    while (num >= 5) {
        s[i++] = 'V';
        num -= 5;
    }
    
    // Check for 4 (IV)
    if (num >= 4) {
        s[i++] = 'I';
        s[i++] = 'V';
        num -= 4;
    }
    
    // Handle 1 (I)
    while (num >= 1) {
        s[i++] = 'I';
        num -= 1;
    }
    
    // Null-terminate the string
    s[i] = '\0';
    
    // Return the constructed Roman numeral string
    return s;
}