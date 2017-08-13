// 选择排序，或者叫简单选择排序
// 选择排序的优点在于它的交换次数比较少，大多数是比较
// 对于任何输入来说，选择排序的效率都是O(n2)
#include <iostream>
using namespace std;

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectSort(int *L, int length) {
    if (length <= 1)
        return;

    int min;
    for (int i = 0; i < length; i++) {
        min = i;
        for (int j = i+1; j < length; j++) {
            if (L[min] > L[j])
                min = j;
        }
        if ( i != min)
            swap(&L[i], &L[min]);
    }
}

int main() {
    int L[10] = {27, 56, 83, 48, 52, 99, 17, 65, 93, 84};
    int length = sizeof(L) / sizeof(int);
    SelectSort(L, length);
    for (int i = 0; i < length; i++) {
        cout << L[i] << " ";
    }
    cout << endl;
    return 0;
}