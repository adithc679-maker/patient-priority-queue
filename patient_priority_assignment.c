#include <stdio.h>
#include <stdlib.h>

#define N 7

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d%s", a[i], i == n-1 ? "" : " ");
    printf("\n");
}

void swap(int *a, int *b) { int t=*a; *a=*b; *b=t; }

void maxHeapInsert(int heap[], int *size, int value) {
    int i = (*size)++;
    heap[i] = value;
    while (i > 0) {
        int p = (i-1)/2;
        if (heap[p] >= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

void maxHeapify(int a[], int n, int i, long *comparisons, long *swaps) {
    while (1) {
        int largest = i;
        int l = 2*i+1, r = 2*i+2;
        if (l < n) { (*comparisons)++; if (a[l] > a[largest]) largest = l; }
        if (r < n) { (*comparisons)++; if (a[r] > a[largest]) largest = r; }
        if (largest == i) break;
        swap(&a[i], &a[largest]); (*swaps)++;
        i = largest;
    }
}

void heapSort(int a[], int n, long *comparisons, long *swaps) {
    *comparisons = *swaps = 0;
    for (int i=n/2-1; i>=0; i--) maxHeapify(a,n,i,comparisons,swaps);
    printf("Initial max heap: "); printArray(a,n);
    for (int end=n-1; end>0; end--) {
        swap(&a[0],&a[end]); (*swaps)++;
        maxHeapify(a,end,0,comparisons,swaps);
        printf("After placing %d: ", a[end]); printArray(a,n);
    }
}

int partition(int a[], int low, int high, long *comparisons, long *swaps) {
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++) {
        (*comparisons)++;
        if(a[j] <= pivot) {
            i++;
            if(i != j) { swap(&a[i],&a[j]); (*swaps)++; }
        }
    }
    if(i+1 != high) { swap(&a[i+1],&a[high]); (*swaps)++; }
    return i+1;
}

void quickSort(int a[], int low, int high, long *comparisons, long *swaps, int depth) {
    if(low<high) {
        int p=partition(a,low,high,comparisons,swaps);
        printf("Partition [%d..%d], pivot=%d -> ",low,high,a[p]); printArray(a,N);
        quickSort(a,low,p-1,comparisons,swaps,depth+1);
        quickSort(a,p+1,high,comparisons,swaps,depth+1);
    }
}

int main(void) {
    int input[N]={45,72,30,90,65,50,85};
    int heap[N], size=0;
    printf("PATIENT SEVERITY SCORES\n"); printArray(input,N);
    printf("\nA) MAX HEAP INSERTION\n");
    for(int i=0;i<N;i++) {
        maxHeapInsert(heap,&size,input[i]);
        printf("Insert %d: ",input[i]); printArray(heap,size);
    }

    int h[N]; for(int i=0;i<N;i++) h[i]=input[i];
    long hc,hs;
    printf("\nB1) HEAP SORT (max heap, in-place)\n");
    heapSort(h,N,&hc,&hs);
    printf("Final Heap Sort: "); printArray(h,N);
    printf("Heap Sort comparisons=%ld, swaps=%ld\n",hc,hs);

    int q[N]; for(int i=0;i<N;i++) q[i]=input[i];
    long qc=0,qs=0;
    printf("\nB2) QUICK SORT (Lomuto, last-element pivot)\n");
    quickSort(q,0,N-1,&qc,&qs,0);
    printf("Final Quick Sort: "); printArray(q,N);
    printf("Quick Sort comparisons=%ld, swaps=%ld\n",qc,qs);
    return 0;
}
