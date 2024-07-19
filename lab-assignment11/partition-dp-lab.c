// Yinxia Shi
// shi.yinx@northeastern.edu

#include<stdio.h>
#define MAXN 45              /* largest number of books */
#define MAXK 10              /* largest number of dividers */
#define MAXINT 100000        /* infinity */

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

int sum(int arr[], int from, int to) {
    int total = 0;
    for (int i = from; i <= to; i++)
        total += arr[i];
    return total;
}

void print_books(int s[], int start, int end)
{
    int i;            /* counter */
    
    printf("{");
    for (i=start; i<=end; i++)
        printf(" %d ",s[i]);
    printf("}\n");
}

void print_matrix(int m[MAXN][MAXK], int n, int k)
{
    int i,j;        /* counters */

    printf("DP Table\n");
    printf("\n");
    for (i=1; i<=n; i++) {
        for (j=1; j<=k; j++)
            printf(" %d ",m[i][j]);
        printf("\n");
    }
}

void reconstruct_partition(int s[],int d[MAXN][MAXK], int n, int k)
{
    if (k==1)  //base case
        print_books(s,1,n);
    else {
        reconstruct_partition(s,d,d[n][k],k-1);
        print_books(s,d[n][k]+1,n);
    }
}

void partition(int s[], int n, int k) {
    int p[MAXN];                /* prefix sums array */
    int m[MAXN][MAXK];          /* DP table for values */
    int d[MAXN][MAXK];          /* DP table for dividers */
    int cost;                   /* test split cost */
    int i,j,x;                  /* counters */

    p[0] = 0;                   /* prefix sums initialised to zero*/
    for (i=1; i<=n; i++)
        p[i]=p[i-1]+s[i];

    for (i=1; i<=n; i++)
        m[i][1] = p[i];    /* initialize boundaries (fill the first column of each rows) */
    
    for (j=1; j<=k; j++)
        m[1][j] = s[1];     /* fill the remaining values in the first row*/
    
    /* 2 to k partitions*/
    /* Add your code here */
    for (j = 2; j <= k; j++) {
        for (i = 2; i <= n; i++) {
            m[i][j] = m[i][j - 1];
            d[i][j] = i;
            for (x = i - 1; x >= 1; x--) {
                cost = max(m[x][j - 1], p[i] - p[x]);
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    d[i][j] = x;
                }
            }
        }
    }



    print_matrix(m,n,k);
    printf("Partition of the books are:\n");
    reconstruct_partition(s,d,n,k);        /* print book partition */
}


int main()
{
    int s[MAXN];       /* book thicknesses to partition */
    int n,i;           /* how many books? */
    int k;             /* how many partitions? */
    n=9;               /* total 9 books*/
    k=3;               /* 3 partitions*/
    
    printf("Enter the thickness of each books\n");
    for (i=1; i<=n; i++)
    {
        scanf("%d",&s[i]);
    }
    printf("\n");
    partition(s,n,k);
    return 0;
}