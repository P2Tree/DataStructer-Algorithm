// 合并排序，该代码现在是没有完成的工作，运行有问题
// 合并排序的复杂度是O(nlogn)，它与快速排序和堆排序相比，最大优点是它是稳定的。
#include <iostream>
#define MAX_SIZE    10
using namespace std;

void MSort(int* SR, int* TR1, int s, int t);
void Merge(int* SR, int* TR, int i, int m, int t);
void MergeSort(int *L, int length);

void MergeSort(int *L, int length) {
    MSort(L, L, 1, length);
}
void MSort(int* SR, int* TR1, int s, int t) {
    int m;
    int TR2[MAX_SIZE+1];
    if ( s == t )
        TR1[s] = SR[s];
    else {
        m = (s+t)/2;    // divide string into 2 pairs
        MSort(SR, TR2, s, m);
        MSort(SR, TR2, m+1, t);
        Merge(TR2, TR1, s, m, t);
    }
}

void Merge(int* SR, int* TR, int i, int m, int n) {
    int j, k, l;
    for (j = m+1, k=i; i <= m && j < n; k++) {
        if (SR[i] < SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    if (i <= m) {
        for (l = 0; l <= m-i; l++)
            TR[k+l] = SR[i+l];
    }
    if (j <= n) {
        for (l = 0; l <= n-j; l++)
            TR[k+l] = SR[j+l];
    }
}
int main() {
    int L[MAX_SIZE] = {19, 34, 85, 29, 55, 75, 39, 73, 60, 18};
    int length = sizeof(L) / sizeof(int);
    MergeSort(L, length);
    for (int i = 0; i < length; i++) {
        cout << L[i] << " ";
    }
    cout << endl;
    return 0;
}