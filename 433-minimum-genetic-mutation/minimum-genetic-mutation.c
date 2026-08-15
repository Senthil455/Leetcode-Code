#define MAX_BANK_SIZE 10
#define GENE_LEN 8

typedef struct {
    char gene[GENE_LEN + 1];
    int steps;
} Node;

int isAdjacent(const char* a, const char* b) {
    int diffCount = 0;
    for (int i = 0; i < GENE_LEN; i++) {
        if (a[i] != b[i]) {
            diffCount++;
            if (diffCount > 1) return 0;
        }
    }
    return diffCount == 1;
}

int minMutation(char* startGene, char* endGene, char** bank, int bankSize) {
    if (bankSize == 0) return -1;
    int visited[MAX_BANK_SIZE] = {0};
    int queueStart = 0, queueEnd = 0;

    Node queue[100];
    strcpy(queue[queueEnd].gene, startGene);
    queue[queueEnd].steps = 0;
    queueEnd++;

    while(queueStart < queueEnd) {
        Node curr = queue[queueStart++];
        if(strcmp(curr.gene, endGene) == 0) {
            return curr.steps;
        }
        for(int i = 0; i < bankSize; i++) {
            if(!visited[i] && isAdjacent(curr.gene, bank[i])) {
                visited[i] = 1;
                strcpy(queue[queueEnd].gene, bank[i]);
                queue[queueEnd].steps = curr.steps + 1;
                queueEnd++;
            }
        }
    }
    return -1;
}