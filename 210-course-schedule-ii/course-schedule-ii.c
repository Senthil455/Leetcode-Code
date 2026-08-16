/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool dfs(int** graph, int* map, int idx, int* res, int* visited, int *returnSize) {
    if(visited[idx] == 1) {
        return true;
    }

    if(visited[idx] == -1) {
        return false;
    }

    visited[idx] = -1;
    for(int i = 0; i < *(map + idx); i++) {
        if(!dfs(graph, map, *(*(graph + idx) + i), res, visited, returnSize)) {
            return false;
        }
    }

    visited[idx] = 1;
    *(res + *returnSize) = idx;
    (*returnSize)++;

    return true;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    *returnSize = 0;
    int* res = calloc(numCourses, sizeof(int));
    if(numCourses <= 1) {
        *returnSize = 1;
        return res;
    }
    int** graph = (int **)malloc(sizeof(int *) * numCourses);
    for(int i = 0; i < numCourses; i++) {
        *(graph + i) = (int *)malloc(sizeof(int) * 15);
    }

    int *map = calloc(numCourses, sizeof(int));
    for(int i = 0; i < prerequisitesSize; i++) {
        int x = *(*(prerequisites + i));
        int y = *(*(prerequisites + i) + 1);

        *(*(graph + x) + *(map + x)) = y;
        (*(map + x))++;
    }

    int *visited = calloc(numCourses, sizeof(int));
    for(int i = 0; i < numCourses; i++) {
        if(!dfs(graph, map, i, res, visited, returnSize)) {
            *returnSize = 0;
            return res;
        }
    }

  return res;
}