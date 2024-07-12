// name: <your name here>
// email: <your email here>

#include <stdio.h>
#include <stdlib.h> 		// for qsrot
#define VSIZE 9 
#define INF 99999 

typedef struct Fedge { 		// F: edge set
	int key; 		// weight
	int u;
	int v;
} Fedge;

// Untility function to compare
int compare(const void *a, const void *b) {
	Fedge *m = (Fedge *)a; 
	Fedge *n = (Fedge *)b; 
	if (m->key < n->key) return -1; 	// -1 when a < b
	if (m->key > n->key) return 1; 		//  1 when a > b
	return 0; 				//  0 when a = b
}

int parent[VSIZE]; 
int edge_num = 0; 

// Iniitalizing to create a set
void make_set(int n) { 
	parent[n] = -1;
}

// Returning a set including v
int find_set(int v) { 
	while (parent[v] >= 0) {
		v = parent[v]; 
	}
	return v; 
}

// Merging 2 sets
void union_set(int n1,int n2) {
    int temp; // temporary for root
    int i;
    
    if (parent[n1] < 0 && parent[n2] < 0) {     // both roots
        if (parent[n1] <= parent[n2]) {
            temp = parent[n2];
            parent[n2] = n1;
            for (i = 0; i < VSIZE; ++i)
                if (parent[i] == n2)
                    parent[i] = n1;

            parent[n1] += temp;
        }
        else {
            temp = parent[n1];
            parent[n1] = n2;
            for (i = 0; i < VSIZE; ++i)
                if (parent[i] == n1)
                    parent[i] = n2;

            parent[n2] += temp;
        }
    }
    else if (parent[n1] < 0 && parent[n2] >= 0) {       // n1: root 
        temp = parent[n1];
        parent[n1] = parent[n2];
        for (i = 0; i < VSIZE; ++i)
            if (parent[i] == n1)
                parent[i] = parent[n2];

        parent[parent[n2]] += temp;
    }
    else if (parent[n1] >= 0 && parent[n2] < 0) {       // n2: root
        temp = parent[n2];
        parent[n2] = parent[n1];
        for (i = 0; i < VSIZE; ++i)
            if (parent[i] == n2)
                parent[i] = parent[n1];

        parent[parent[n1]] += temp;
    }
    else {                                              // no root
        temp = parent[n1];
        parent[n1] = parent[n2];
        parent[parent[n2]] += parent[temp];
        parent[temp] = parent[n2];
    }

    printf("Union edge %d and edge %d. parent --> ", n1, n2);

    for (i = 0; i < VSIZE; ++i)
        printf("%3d", parent[i]); 
    printf("\n");
}

// Kruskal Algorithm
int kruskal(Fedge e[],int n) { 
    int i, u, v;
    int mst_e = 0; 				    // min cost
    int mst_e_n = 0; 			    // # of edges for mst

   qsort(e, edge_num, sizeof(Fedge), compare); // sort edges using qsort

   // Add Your code here

   return mst_e; 
}

int main() {
    int mst;  
    int graph[VSIZE][VSIZE] = { // input_graph
	{   0,  4,INF,INF,INF,INF,INF,  8,INF},
	{   4,  0,  8,INF,INF,INF,INF, 11,INF},
	{ INF,  8,  0,  7,INF,  4,INF,INF,  2},
	{ INF,INF,  7,  0,  9, 14,INF,INF,INF},
	{ INF,INF,INF,  9,  0, 10,INF,INF,INF},
	{ INF,INF,  4, 14, 10,  0,  2,INF,INF},
	{ INF,INF,INF,INF,INF,  2,  0,  1,  6},
	{   8, 11,INF,INF,INF,INF,  1,  0,  7},
	{ INF,INF,  2,INF,INF,INF,  6,  7, 0 }};

    Fedge edge_set[INF]; 

    int i,j;

    // Add your code here to create edge_set

    mst=kruskal(edge_set, VSIZE); 
    printf("Min cost is %d.\n", mst);
}
