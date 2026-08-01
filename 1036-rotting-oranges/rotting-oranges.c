typedef struct {
    int x,y;
} Point;

Point queue[100];
int rear=0, front=0;

void enqueue(int x,int y){
    queue[rear].x=x;
    queue[rear].y=y;
    rear++;
}

Point dequeue(){
    return queue[front++];
}

bool isEmpty(){
    return front==rear;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int fresh=0;
    front=rear=0;

    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if(grid[i][j]==2){
                enqueue(i,j);
            }
            else if(grid[i][j]==1){
                fresh++;
            }
        }
    }

    if(fresh==0) return 0;

    int minutes=-1;
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    while(!isEmpty()){
        int size=rear-front;
        minutes++;
        for(int i=0;i<size;i++){
            Point P = dequeue();
            for(int d=0;d<4;d++){
                int nx= P.x + dirs[d][0];
                int ny= P.y + dirs[d][1];
                if(nx>=0 && nx<gridSize && ny>=0 && ny<gridColSize[nx] && grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    fresh--;
                    enqueue(nx,ny);
                }
            }
        }
    }
    return fresh==0?minutes:-1;
}