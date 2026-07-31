bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int *todo;              // stack
    unsigned char *done;    // bytemap
    int i, room, key, count = 0, top=0;
    todo = calloc(4096, sizeof(int)); // dynamic mem allocation...
    done = calloc(1024, sizeof(unsigned char)); // faster than static!
	
    todo[top++] = 0;
    done[todo[top-1]] = 1;
	count++;
    while(top>0) { // when the 'stack' is empty, the array still has a bunch of values
        room = todo[--top]; // top is always one greater than the 'top' value
        for(i=0;i<roomsColSize[room];i++) {
            key = rooms[room][i];
            if(!done[key]) {
                todo[top++] = key;
                done[key] = 1;
                count++;
            }
        }
    }
    if(count != roomsSize) { return false; }
    return true;
}