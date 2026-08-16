/*
 * 207. Course Schedule
 *
 * There are a total of numCourses courses you have to take, labeled 
 * from 0 to numCourses - 1. You are given an array prerequisites 
 * where prerequisites[i] = [ai, bi] indicates that you must take 
 * course bi first if you want to take course ai.
 * 
 * For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
 * Return true if you can finish all courses. Otherwise, return false.
 * 
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 */
 
typedef struct node {
    int dst;
    struct node *next;    
} NODE;

NODE *path[2000];
int inbound[2000];

int order[2000];
int order_idx;

#define FIFO_SIZE   2000
int fifo[FIFO_SIZE];
int fifo_hdr;
int fifo_tail;

int fifo_init()
{
    fifo_hdr = 0;
    fifo_tail = 0;
    
    return 0;
}

int fifo_push(int val)
{
    int next = (fifo_tail + 1) % FIFO_SIZE;
    
    if (next == fifo_hdr) {
        return -1;
    }
    
    fifo[fifo_tail] = val;
    fifo_tail = next;
    
    return 0;
}

int fifo_pop(int *p_val)
{
    if (fifo_hdr == fifo_tail) {
        return -1;
    }
    
    *p_val = fifo[fifo_hdr];
    fifo_hdr = (fifo_hdr + 1) % FIFO_SIZE;
    
    return 0;
}

bool fifo_empty()
{
    return (fifo_hdr == fifo_tail);
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){

    /*
     *  Input:
     *      numCourses, number of curses you have to take (0 ~ N - 1)
     *      prerequisites, prerequisite list before take specific curse,
     *      prerequisitesSize, size of prerequisites
     *      prerequisitesColSize, column number of specific prerequisite
     *
     *      1 <= numCourses <= 2000
     *      0 <= prerequisites.length <= 5000
     *      prerequisites[i].length == 2
     *      0 <= ai, bi < numCourses
     *      All the pairs prerequisites[i] are unique.
     *
     */
    
    /*
     *  Algorithm:
     *      numCourses = 4, 
     *      prerequisites = [[0, 1], [1, 2] [2, 3], [3, 4]]
     *
     *      Create graph table
     *      src         dst
     *      [0]
     *      [1]         0
     *      [2]         1
     *      [3]         2
     *      [4]         3
     *
     *      start from [0] ~ [N], traverse all the nodes, 
     *      check if we can visit all the nodes from one of the source node.
     *
     *      numCourses = 2, 
     *      prerequisites = [[0, 1], [1, 0]]    (a cycle existed)
     *      src         dst
     *      [0]         1       <---- conflict
     *      [1]         0
     *      
     */
    int src, dst;
    NODE *p_tmp, *p_del;

    /* Reset adjacency list */ 
    memset((void *)path, 0, sizeof(NODE *) * numCourses);
    
    /* Reset inbound counters */
    memset((void *)inbound, 0, sizeof(int) * numCourses);
    
    /* Reset order list */
    order_idx = 0;
    memset((void *)order, 0, sizeof(int) * numCourses);
    
    /* Reset fifo (process list) */
    fifo_init();

    /* Build the graph */
    for (int i = 0; i < prerequisitesSize; i++) {
        src = prerequisites[i][1];
        dst = prerequisites[i][0];

        /* Add destination to source */
        p_tmp = (NODE *)malloc(sizeof(NODE));
        p_tmp->dst = dst;
        p_tmp->next = path[src];
        path[src] = p_tmp;
        
        /* Increase inbound to specific destination */
        inbound[dst]++;
    }

    /* Find first available sources (inbound = 0) and put to order queue */
    for (int i = 0; i < numCourses; i++) {
        if (inbound[i] == 0) {
            fifo_push(i);
            order[order_idx] = i;
            order_idx++;
        }
    }
    
    /* topological sorting (BFS) */
    while (fifo_empty() == false) {

        /* Get source node */
        fifo_pop(&src);

        /* Visit it's neighbooring nodes */
        p_tmp = path[src];
        
        while (p_tmp) {
            
            dst = p_tmp->dst;
            
            /* Decrease inbound of neighbooring node */
            inbound[dst]--;
            
            /* Put to process queue and order queue if the inbound of node is zero */
            if (inbound[dst] == 0) {
                fifo_push(dst);
                order[order_idx] = dst;
                order_idx++;
            }
            
            p_tmp = p_tmp->next;
        }
    }
    
    /*
     *  Release graph
     */
    
    for (int i = 0; i < numCourses; i++) {
        p_tmp = path[i];
        
        while(p_tmp) {
            p_del = p_tmp;
            p_tmp = p_tmp->next;
            free(p_del);
        }
    }
    
    /*
     *  Output:
     *      Return true if you can finish all courses. Otherwise, return false.
     */

    return (order_idx == numCourses);
}