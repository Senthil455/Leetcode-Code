#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Trie {
    struct Trie* children[26];
    bool is_end;
} Trie;

Trie* trieCreate() {
    Trie* node = (Trie*)malloc(sizeof(Trie));
    node->is_end = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void trieInsert(Trie* obj, char* word) {
    Trie* node = obj;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (node->children[idx] == NULL) {
            node->children[idx] = trieCreate();
        }
        node = node->children[idx];
    }
    node->is_end = true;
}

bool trieSearch(Trie* obj, char* word) {
    Trie* node = obj;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (node->children[idx] == NULL) {
            return false;
        }
        node = node->children[idx];
    }
    return node->is_end;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* node = obj;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int idx = prefix[i] - 'a';
        if (node->children[idx] == NULL) {
            return false;
        }
        node = node->children[idx];
    }
    return true;
}

void trieFree(Trie* obj) {
    if (obj == NULL) return;
    for (int i = 0; i < 26; i++) {
        if (obj->children[i] != NULL) {
            trieFree(obj->children[i]);
        }
    }
    free(obj);
}