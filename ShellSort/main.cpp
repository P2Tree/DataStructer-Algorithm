// 希尔排序是插入排序的一种改进算法，可以对比插入排序学习
// 由于插入排序对于几乎已排序的数组排序效率高，所以希尔排序基于这点，通过对序列按一定步长分段，对每一段中的等步长数据做排序，
// 然后依次减小步长，重复该过程。当步长为1时，该次操作与插入排序相同（之前的操作也和插入排序类似）。
// 希尔排序的效率可以达到O(nlogn)。它是不稳定排序。
#include <iostream>
using namespace std;

void ShellSort(int list[], int length) {
    if (length <= 1 || list == nullptr)
        return;

    int temp;
    int gap;
    int i, j;
    for (gap = length >> 1; gap > 0; gap >>= 1) {
        for (i = gap; i < length; i += gap) {
            temp = list[i];
            for (j = i; j > 0 && list[j-gap] > temp; j -= gap ) {
                list[j] = list[j - gap];
            }
            list[j] = temp;
        }
    }
}
int main() {
    int list[8] = {21, 85, 39, 94, 50, 29, 57, 12};
    int length = sizeof(list) / sizeof(int);
    ShellSort(list, length);
    for (int i = 0; i < length; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    return 0;
}