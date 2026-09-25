#include <stdlib.h>
#include <string.h>

typedef struct {
    char** words;
    int count;
} Set;

static char* myStrdup(const char* str) {
    char* r = malloc(strlen(str) + 1);
    strcpy(r, str);
    return r;
}

static int cmpstr(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

static void freeSet(Set s) {
    for (int i = 0; i < s.count; i++) free(s.words[i]);
    free(s.words);
}

/* Sort + remove duplicates in place. Compare against the last KEPT
   element (s.words[newCount-1]), not the raw previous slot (s.words[i-1]),
   which may already have been freed/overwritten by compaction. */
static Set dedupe(Set s) {
    if (s.count == 0) return s;
    qsort(s.words, s.count, sizeof(char*), cmpstr);
    int newCount = 1;
    for (int i = 1; i < s.count; i++) {
        if (strcmp(s.words[i], s.words[newCount - 1]) != 0) {
            s.words[newCount++] = s.words[i];
        } else {
            free(s.words[i]);
        }
    }
    s.count = newCount;
    return s;
}

static Set makeSingleton(const char* word) {
    Set r;
    r.words = malloc(sizeof(char*));
    r.words[0] = myStrdup(word);
    r.count = 1;
    return r;
}

static Set cartesianConcat(Set a, Set b) {
    Set r;
    r.count = a.count * b.count;
    r.words = malloc(sizeof(char*) * r.count);
    int idx = 0;
    for (int i = 0; i < a.count; i++) {
        for (int j = 0; j < b.count; j++) {
            int len = (int)strlen(a.words[i]) + (int)strlen(b.words[j]);
            char* w = malloc(len + 1);
            strcpy(w, a.words[i]);
            strcat(w, b.words[j]);
            r.words[idx++] = w;
        }
    }
    freeSet(a);
    freeSet(b);
    return dedupe(r);
}

static Set unionSets(Set a, Set b) {
    Set r;
    r.count = a.count + b.count;
    r.words = malloc(sizeof(char*) * r.count);
    int idx = 0;
    for (int i = 0; i < a.count; i++) r.words[idx++] = a.words[i];
    for (int i = 0; i < b.count; i++) r.words[idx++] = b.words[i];
    free(a.words);
    free(b.words);
    return dedupe(r);
}

static Set parseUnion(char** s);

static Set parseFactor(char** s) {
    if (**s == '{') {
        (*s)++;
        Set r = parseUnion(s);
        (*s)++;
        return r;
    } else {
        char buf[64];
        int i = 0;
        while (**s >= 'a' && **s <= 'z') {
            buf[i++] = **s;
            (*s)++;
        }
        buf[i] = '\0';
        return makeSingleton(buf);
    }
}

static Set parseConcat(char** s) {
    Set r = parseFactor(s);
    while (**s && **s != ',' && **s != '}') {
        Set next = parseFactor(s);
        r = cartesianConcat(r, next);
    }
    return r;
}

static Set parseUnion(char** s) {
    Set r = parseConcat(s);
    while (**s == ',') {
        (*s)++;
        Set next = parseConcat(s);
        r = unionSets(r, next);
    }
    return r;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** braceExpansionII(char* expression, int* returnSize) {
    char* s = expression;
    Set result = parseConcat(&s);
    result = dedupe(result);

    *returnSize = result.count;
    return result.words;
}