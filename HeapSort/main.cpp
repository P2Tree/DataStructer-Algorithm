// 堆排序，主要分两个部分：构建大顶堆和交换堆顶和末尾元素做交换
// 复杂度为O(nlogn)，只有一个暂存单元，基本不占用内存空间。不稳定排序。
// 不适合排序序列个数较少的情况。
#include <iostream>

using namespace std;

void HeapAdjust(int *L, int s, int m);
void swap(int *a, int *b);

void HeapSort(int *L, int length) {
    int i;
    for (i = length/2; i>0; i--) {  // length/2的意图是，将每个非叶子节点都调整为大顶堆
        HeapAdjust(L, i, length);   // 将数组调整为一个大顶堆
    }

    for (i = length-1; i>0; i--) {
        swap(&L[0], &L[i]);   // 将堆顶的记录与当前未排序的子序列的最后一个记录做交换
        HeapAdjust(L, 1, i-1);      // 将数组中除掉最后一个记录（现在为堆顶数字）以外的序列重新调整为大顶堆
    }
}

void HeapAdjust(int *L, int s, int m) {
    int temp, j;
    temp = L[s];
    for (j = 2*s; j<= m; j*=2) {    // 对于完全二叉树，当父节点序号是s时，左孩子的序号是2*s，右孩子的序号是2*s+1
        if (j < m && L[j] < L[j+1])
            ++j;    // 寻找在关键字中较大的记录的下标，判断如果当前孩子j不是最大的孩子，则换右孩子
        if (temp >= L[j])
            break;  // 上一步找到了最大的子节点的位置和数字，但最大孩子节点的数字依然小于父节点的数字，则跳出循环不做处理
        L[s] = L[j];    // 交换最大的子节点和比子节点小的父节点（前半部分）
        s = j;  // 令s指向原来较大子节点的序号
    }
    L[s] = temp;    // 将子节点位置赋予原父节点的数字（后半部分），或，如果for循环是break跳出的话，L[s]未变化
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int list[10] = {50, 28, 95, 38, 55, 19, 84, 73, 62, 82};
    int length = sizeof(list) / sizeof(int);
    cout << length << "**";
    HeapSort(list, length);
    cout << length << "@@"<< endl;
    for (int i = 0; i < length; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    return 0;
}