#include <stdlib.h>
#include <string.h>

// Node maintains remainder frequencies and subarray product.
typedef struct {
    int cntPerRem[5];
    int prod;
} SegTreeNode;

// Combine left and right subtrees into a single aggregated node.
void mergeNodes(SegTreeNode* res, const SegTreeNode* l, const SegTreeNode* r, int modVal) {
    memset(res->cntPerRem, 0, sizeof(int) * 5);
    res->prod = (l->prod * r->prod) % modVal;
    
    for (int i = 0; i < modVal; ++i) {
        res->cntPerRem[i] = l->cntPerRem[i];
    }
    for (int i = 0; i < modVal; ++i) {
        int shifted = (l->prod * i) % modVal;
        res->cntPerRem[shifted] += r->cntPerRem[i];
    }
}

// Initialize leaf node with a specific value modulo constraint.
void addNode(SegTreeNode* tree, int idx, int val, int modVal) {
    val %= modVal;
    memset(tree[idx].cntPerRem, 0, sizeof(int) * 5);
    tree[idx].cntPerRem[val] = 1;
    tree[idx].prod = val;
}

// Recursively build segment tree by dividing array range.
void buildTree(SegTreeNode* tree, const int* nums, int node, int l, int r, int modVal) {
    if (l == r) {
        addNode(tree, node, nums[l], modVal);
        return;
    }
    int mid = l + (r - l) / 2;
    buildTree(tree, nums, node * 2, l, mid, modVal);
    buildTree(tree, nums, node * 2 + 1, mid + 1, r, modVal);
    // Propagate updated states up through the tree structure.
    mergeNodes(&tree[node], &tree[node * 2], &tree[node * 2 + 1], modVal);
}

// Traverse tree to update target leaf and recalculate ancestors.
void updateTree(SegTreeNode* tree, int node, int l, int r, int idx, int val, int modVal) {
    if (l == r) {
        addNode(tree, node, val, modVal);
        return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid) {
        updateTree(tree, node * 2, l, mid, idx, val, modVal);
    } else {
        updateTree(tree, node * 2 + 1, mid + 1, r, idx, val, modVal);
    }
    mergeNodes(&tree[node], &tree[node * 2], &tree[node * 2 + 1], modVal);
}

// Retrieve merged node representing the queried subarray range.
SegTreeNode queryTree(SegTreeNode* tree, int node, int l, int r, int ql, int qr, int mod) {
    if (ql <= l && r <= qr) return tree[node];
    
    int mid = l + (r - l) / 2;
    if (qr <= mid) return queryTree(tree, node * 2, l, mid, ql, qr, mod);
    if (ql > mid) return queryTree(tree, node * 2 + 1, mid + 1, r, ql, qr, mod);
    
    SegTreeNode leftRes = queryTree(tree, node * 2, l, mid, ql, qr, mod);
    SegTreeNode rightRes = queryTree(tree, node * 2 + 1, mid + 1, r, ql, qr, mod);
    SegTreeNode merged;
    mergeNodes(&merged, &leftRes, &rightRes, mod);
    return merged;
}

int* resultArray(int* nums, int numsSize, int modVal, int** queries, int queriesSize, 
                 int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    if (numsSize <= 0) return ans;
    SegTreeNode* tree = (SegTreeNode*)malloc(4 * numsSize * sizeof(SegTreeNode));
    buildTree(tree, nums, 1, 0, numsSize - 1, modVal);
    for (int i = 0; i < queriesSize; ++i) {
        int updateIdx = queries[i][0];
        int newVal = queries[i][1];
        int startIdx = queries[i][2];
        int rem = queries[i][3];
        updateTree(tree, 1, 0, numsSize - 1, updateIdx, newVal, modVal);
        SegTreeNode res = queryTree(tree, 1, 0, numsSize - 1, startIdx, numsSize - 1, modVal);
        ans[i] = res.cntPerRem[rem];
    }
    
    free(tree);
    return ans;
}