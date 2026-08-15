
typedef struct Node {
    struct Node *node[26];
    int wordEnd;
}Node;

typedef struct {
    Node *root;
} WordDictionary;

WordDictionary *dict;

WordDictionary* wordDictionaryCreate() {
    int i;
    dict = calloc(1, sizeof(WordDictionary));
    if (!dict) return NULL;
    dict->root = calloc(1, sizeof(Node));
    return dict;
}

void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    int i = 0;
    Node *curr = NULL;
    if (obj == NULL || word == NULL) {
        return;
    }
    int size = strlen(word);
    if (size > 25) {
        return;
    }
    curr = obj->root;
    while (curr && i < size) {

        if (!curr->node[word[i] - 'a']) {
            curr->node[word[i] - 'a'] = calloc(1, sizeof(Node));
        }
        curr = curr->node[word[i] - 'a'];
        ++i;
    }
    curr->wordEnd++;
}
bool search(WordDictionary* obj, Node *root, char* word, int len, int count) {
    int i = 0;
    bool match = false;
    if (len == count) {
        if (root->wordEnd) {
            return true;
        } else {
            return false;
        }
    }
    if (word[count] == '.') {
        count++;
        for (i = 0; i < 26; ++i) {
            if (root->node[i]) {
        
                match = search(obj, root->node[i], word, len, count);
            }
            if (match) {
                return match;
            }
        }
        return match;
    } else {
        int idx = word[count] - 'a';
        count++;
        if (root->node[idx]) {
            return search(obj, root->node[idx], word, len, count);
        } else {
            return false;
        }
    }

}
bool wordDictionarySearch(WordDictionary* obj, char* word) {
    int i = 0;
    Node *curr = NULL;
    if (obj == NULL || word == NULL) {
        return false;
    }
    int size = strlen(word);
    if (size > 25) {
        return false;
    }
    curr = obj->root;
    
    return search(obj, obj->root, word, size, 0);
}
void freeAll(Node *root) {
    int i = 0;
    if (!root) return;
    for (i = 0; i < 26; ++i) {
        if (root->node[i]) {
            freeAll(root->node[i]);
        }
    }
    free(root);
}
void wordDictionaryFree(WordDictionary* obj) {
    int i = 0, j = 0;
    Node *curr = obj->root;
    freeAll(obj->root);
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/