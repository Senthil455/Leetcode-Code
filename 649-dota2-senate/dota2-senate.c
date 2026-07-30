char * predictPartyVictory(char * senate){
    int dCount=0, rCount=0, dBan = 0, rBan = 0;
    int l , head = 0, tail, i;
    char c;
    for (i = 0; senate[i] != '\0'; ++i) {
        if (senate[i] == 'D') {
            ++dCount;
        } else {
            ++rCount;
        }
    }
    tail = i;
    l = i+1;
    while (dCount > 0 && rCount > 0) {
        c = senate[head];
        head = (head + 1) % l;
        if (c == 'D') {
            if (dBan > 0) {
                --dBan;
                --dCount;
            } else {
                ++rBan;
                senate[tail] = 'D';
                tail = (tail + 1) % l;
            }
        } else { /* c == 'R' */
            if (rBan > 0) {
                --rBan;
                --rCount;
            } else {
                ++dBan;
                senate[tail] = 'R';
                tail = (tail + 1) % l;
            }
        }
    }
    return dCount > 0 ? "Dire" : "Radiant";
}