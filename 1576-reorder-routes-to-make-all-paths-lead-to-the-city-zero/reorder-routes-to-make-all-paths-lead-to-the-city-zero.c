/*
 * 1466. Reorder Routes to Make All Paths Lead to the City Zero
 *
 * There are n cities numbered from 0 to n - 1 and n - 1 roads 
 * such that there is only one way to travel between two different 
 * cities (this network form a tree). Last year, The ministry of 
 * transport decided to orient the roads in one direction because 
 * they are too narrow.
 * 
 * Roads are represented by connections where connections[i] = [ai, bi] 
 * represents a road from city ai to city bi.
 * 
 * This year, there will be a big event in the capital (city 0), and many 
 * people want to travel to this city.
 * 
 * Your task consists of reorienting some roads such that each city can 
 * visit the city 0. Return the minimum number of edges changed.
 * 
 * It's guaranteed that each city can reach city 0 after reorder.
 *
 * 2 <= n <= 5 * 10^4
 * connections.length == n - 1
 * connections[i].length == 2
 * 0 <= ai, bi <= n - 1
 * ai != bi
 *
 *
 */
 
typedef struct dst {
    struct dst *next;
    int id;
} dst_t;
 
int dfs(dst_t **orig_adj, dst_t **bidir_adj, int n, int curr, bool *visited)
{
    int cnt = 0;
    bool same_dir = false;
    
    visited[curr] = true;
    
    /* Check if we can move to next node (away from node 0) */
    for (dst_t *tmp1 = bidir_adj[curr]; tmp1; tmp1 = tmp1->next) {

        if (visited[tmp1->id] == false) {
        
            same_dir = false;
        
            /* 
             * 
             * Check the original neighbor list, check if it is possible to 
             * move from the next city back to the current city.
             * If not, we need to reverse the original road direction
             */
            for (dst_t *tmp2 = orig_adj[tmp1->id]; tmp2; tmp2 = tmp2->next) {
                if (tmp2->id == curr) {
                    same_dir = true;
                    break;
                }
            }
            
            if (same_dir == false) {
                cnt++;
            }
            
            /* Move to next city, and contiune to check the roads between different cities */
            cnt += dfs(orig_adj, bidir_adj, n, tmp1->id, visited);
        }
    
    }

    return cnt;
}

/*
 * Algorithm:
 *  We know that all the cities are connected together
 *  but some of roads have incorrect direct so this 
 *  cause some cities can visit city 0
 *
 *  E.g:
 *      0  <-  1  ->  2  <- 3 -> 4
 *
 *  We can create a bidirectional map
 *      0  <-  1  ->  2  <- 3 -> 4
 *         ->     ->     ->   ->
 *
 *  Start to city 0, traverse to other cities and also compare the
 *  original road direction between these cities, its the direction is different
 *  we need to reverse the road direction
 *
 *      0  <-  1  ->  2  <- 3 -> 4
 *         ->     ->     ->   ->
 *          1             2             => Ans = 2;
 */
 
int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize){

    /*
     * Input:
     *  n, n cities
     *  connections, roads between cities
     *  connectionsSize, number of roads
     *  connectionsColSize
     */

    int ans = 0;
    bool *visited = (bool *)calloc(1, sizeof(bool) * n);
    dst_t **orig_adj = (dst_t **)calloc(1, sizeof(dst_t *) * n);
    dst_t **bidir_adj = (dst_t **)calloc(1, sizeof(dst_t *) * n);
    dst_t *tmp, *del;
    
    /* Build origianl adjacent list and a bidirectional adjacent list */
    for (int i = 0; i < connectionsSize; i++) {
        /* orig_adj[from][to] */
        tmp = (dst_t *)malloc(sizeof(dst_t));
        tmp->id = connections[i][1];
        tmp->next = orig_adj[connections[i][0]];
        orig_adj[connections[i][0]] = tmp;
        
        /* Bidirection */
        tmp = (dst_t *)malloc(sizeof(dst_t));
        tmp->id = connections[i][1];
        tmp->next = bidir_adj[connections[i][0]];
        bidir_adj[connections[i][0]] = tmp;
        
        tmp = (dst_t *)malloc(sizeof(dst_t));
        tmp->id = connections[i][0];
        tmp->next = bidir_adj[connections[i][1]];
        bidir_adj[connections[i][1]] = tmp;
    }
     
    ans = dfs(orig_adj, bidir_adj, n, 0, visited);
     
    for (int i = 0; i < n; i++) {
    
        for (tmp = orig_adj[i]; tmp; ) {
            del = tmp;
            tmp = tmp->next;
            free(del);
        }
        
        for (tmp = bidir_adj[i]; tmp; ) {
            del = tmp;
            tmp = tmp->next;
            free(del);
        }

    }

    free(orig_adj);
    free(bidir_adj);
    free(visited);
    
    /*
     * Output:
     *  Return the minimum number of edges changed.
     */
     
    return ans;
}