#include <stdio.h>
#define SIZE 10

int h1(int k){ return k % SIZE; }
int h2(int k){ return 7 - (k % 7); }

int insert(int t[], int key){
    int a=h1(key), b=h2(key);
    for(int i=0;i<SIZE;i++){
        int p=(a+i*b)%SIZE;
        if(t[p]==-1){ t[p]=key; return 1; }
    }
    return 0;
}

int search(int t[], int key, int *probes){
    int a=h1(key), b=h2(key);
    *probes=0;
    for(int i=0;i<SIZE;i++){
        int p=(a+i*b)%SIZE;
        (*probes)++;
        if(t[p]==-1) return -1;
        if(t[p]==key) return p;
    }
    return -1;
}

int main(){
    int ids[]={23,43,13,33,53,63,73};
    int t[SIZE];

    for(int i=0;i<SIZE;i++) t[i]=-1;
    for(int i=0;i<7;i++) insert(t,ids[i]);

    printf("DOUBLE HASHING\n");
    printf("h1(k)=k%%10, h2(k)=7-(k%%7)\n\n");
    printf("Index\tValue\n");
    for(int i=0;i<SIZE;i++)
        if(t[i]==-1) printf("%d\tEMPTY\n",i);
        else printf("%d\t%d\n",i,t[i]);

    int keys[]={53,73,83};
    printf("\nSearch Results\nKey\tResult\tProbes\n");
    for(int i=0;i<3;i++){
        int probes, pos=search(t,keys[i],&probes);
        if(pos!=-1) printf("%d\tFound at %d\t%d\n",keys[i],pos,probes);
        else printf("%d\tNot Found\t%d\n",keys[i],probes);
    }

    printf("\nLoad Factor = 0.70 (70%%)\n");
    return 0;
}
