typedef struct queue
{
    int* list;
    int head;
    int sz;
    int capacity;
} queue;

queue* initialize(void)
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->list=(int*)malloc(sizeof(int)*100);
    q->head=0;
    q->sz=0;
    q->capacity=100;
    return q;
}

queue* reallocation(queue* q)
{
    q->capacity*=2;
    int* new=(int*)malloc(sizeof(int)*q->capacity);
    memcpy(new,q->list+q->head,sizeof(int)*(q->sz-q->head));
    q->sz-=q->head;
    q->head=0;
    free(q->list);
    q->list=new;
    return q;
}

void push(queue* q,int a)
{
    if(q->sz>=q->capacity)
    {
        reallocation(q);
    }
    q->list[q->sz]=a;
    q->sz++;
}

int front(queue* q)
{
    return q->list[q->head];
}

void pop(queue* q)
{
    q->head++;
}

void clear(queue* q)
{
    free(q->list);
    free(q);
}

int snakesAndLadders(int** board, int n, int* boardColSize)
{
    int i;
    int row,col,next,x,temp;
    int minrolls[n*n+1];
    queue* q=initialize();
    memset(minrolls,-1,sizeof(minrolls));
    minrolls[1]=0;
    push(q,1);
    while(q->sz-q->head)
    {
        x=front(q);
        pop(q);
        for(i=1;i<=6&&i+x<=n*n;i++)
        {
            next=i+x;
            row=(next-1)/n;
            col=(next-1)%n;
            temp=board[n-1-row][row%2?n-1-col:col];
            if(temp!=-1)
            {
                next=temp;
            }
            if(next==n*n)
            {
                clear(q);
                return minrolls[x]+1;
            }
            if(minrolls[next]==-1)
            {
                minrolls[next]=minrolls[x]+1;
                push(q,next);
            }
        }
    }
    clear(q);
    return -1;
}