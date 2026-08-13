bool wordBreak(char* s, char** wordDict, int wordDictSize) {
	bool * check = (bool *)calloc(strlen(s) + 1, sizeof(bool));
	check[0] = true;
	for(int i=0; i<=strlen(s); i++)
		for(int j=0; j<wordDictSize; j++)         
            if(check[i] && strstr(s+i, wordDict[j]) == (s+i)) //check position can generate by wordDict
                    check[i + strlen(wordDict[j])] = true;
	return check[strlen(s)];
}