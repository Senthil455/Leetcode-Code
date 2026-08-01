/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<math.h>

void merge(int *a,int *b,int s,int m,int n){
    int a1=s,a2=m+1,bi=s;

    while(a1<=m && a2<=n){
        if(a[a1]<a[a2])
            b[bi++]=a[a1++];
        else
            b[bi++]=a[a2++];
    }
    while(a1<=m)    
        b[bi++]=a[a1++];
    while(a2<=n)    
        b[bi++]=a[a2++];
    for(int i=s;i<=n;i++)
        a[i]=b[i];
}       

void mergeSort(int *a,int *b,int s,int n){
    if(s<n){
        int m=(s+n)/2;
        mergeSort(a,b,s,m);
        mergeSort(a,b,m+1,n);
        merge(a,b,s,m,n);
    }
}

int search(int *a,int n,int spell,long long success){
    int seg_size=sqrt(n);
    int i,j;
    int segs= (n)/seg_size;
    if(n%seg_size) segs++;
    for(i=0;i<segs;i++){
        if(success<=(long long)a[seg_size*i]*spell){
            if(i==0) return 0;
            for(j=seg_size*(i-1);j<seg_size*i-1;j++){
                if(success<=(long long)a[j+1]*spell)
                    return j+1;
            }
            return seg_size*i;
        }
    }
    for(j=seg_size*(i-1);j<n-1;j++){
        if(success<=(long long)a[j+1]*spell)
            return j+1;

    }
    return -1;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {

    int i,j;
    int n = spellsSize;
    int m = potionsSize;

    int *pair = (int*)malloc(sizeof(int)*n);
    *returnSize = n;

    int *b=(int*)malloc(sizeof(int)*m);
    mergeSort(potions,b,0,m-1);
    free(b);

    for(i=0;i<n;i++){
        j=search(potions,m,spells[i],success);
        if(j!=-1)
        pair[i]=m-j;
        else
        pair[i]=0;
    }
    return pair;
}