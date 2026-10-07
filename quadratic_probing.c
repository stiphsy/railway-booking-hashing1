#include <stdio.h>
#define SIZE 10

int hash(int k){ return k % SIZE; }

int insert(int t[], int key){
    int h = hash(key);
    for(int i=0;i<SIZE;i++){
        int p = (h+i*i) % SIZE;
        if(t[p]==-1){ t[p]=key; return 1; }
    }
    return 0;
}

int search(int t[], int key, int *probes){
    int h = hash(key);
    *probes = 0;
    for(int i=0;i<SIZE;i++){
        int p = (h+i*i) % SIZE;
        (*probes)++;
        if(t[p]==-1) return -1;
        if(t[p]==key) return p;
    }
    return -1;
}

int main(){
    int ids[] = {23,43,13,33,53,63,73};
    int t[SIZE];

    for(int i=0;i<SIZE;i++) t[i] = -1;

    printf("QUADRATIC PROBING\n");
    for(int i=0;i<7;i++)
        printf("%d: %s\n",ids[i],insert(t,ids[i]) ? "inserted" : "could not be inserted");

    printf("\nIndex\tValue\n");
    for(int i=0;i<SIZE;i++)
        if(t[i]==-1) printf("%d\tEMPTY\n",i);
        else printf("%d\t%d\n",i,t[i]);

    int keys[] = {53,73,83};
    printf("\nSearch Results\nKey\tResult\tProbes\n");
    for(int i=0;i<3;i++){
        int probes, pos = search(t,keys[i],&probes);
        if(pos!=-1) printf("%d\tFound at %d\t%d\n",keys[i],pos,probes);
        else printf("%d\tNot Found\t%d\n",keys[i],probes);
    }

    printf("\nRequested-key Load Factor = 0.70 (70%%)\n");
    printf("Actual occupancy after quadratic insertion = 0.60 (60%%)\n");
    return 0;
}
