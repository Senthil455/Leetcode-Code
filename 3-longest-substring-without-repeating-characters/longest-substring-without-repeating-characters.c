int lengthOfLongestSubstring(char* s) {
    if (!s || !*s) // Check if the string is empty
        return 0;
    
    int charIndexMap[256]; // Assuming ASCII characters
    memset(charIndexMap, -1, sizeof(charIndexMap)); // Initialize array with -1
    
    int maxLength = 0;
    int startIndex = 0;
    int i;
    
    for (i = 0; s[i] != '\0'; i++) {
        // If the character is already in the map and its index is after the start index of the current substring,
        // update the start index to the index after the last occurrence of the character
        if (charIndexMap[s[i]] != -1 && charIndexMap[s[i]] >= startIndex) {
            startIndex = charIndexMap[s[i]] + 1;
        }
        
        // Update the index of the current character
        charIndexMap[s[i]] = i;
        
        // Update the maximum length if the current substring is longer
        if (i - startIndex + 1 > maxLength) {
            maxLength = i - startIndex + 1;
        }
    }
    
    return maxLength;
}