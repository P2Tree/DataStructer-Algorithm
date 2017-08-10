#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
T RandomInRange(T start, T end) {
    srand((unsigned)time(NULL));
    return (rand() % static_cast<int>(end-start)) + start;
}
template <typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int Partition(int* data, int length, int start, int end) {
    if (data == NULL || length <= 0 || start < 0 || end >= length)
        throw("Invalid Parameters");

    // 这种划分每次选择一个随机值作为中轴，随机快速排序randomized quicksort
    int index = RandomInRange(start, end);
    Swap(data[index], data[end]); // 随机选中一个中轴并移动到边缘

    int small = start;
    for (index = start; index < end; ++index) {
        if (data[index] < data[end]) {
            if (small != index)
                Swap(data[index], data[small]);
            ++small;
        }
    }
    Swap(data[small], data[end]);

    // 这种划分每次选择的都是序列第一个值作为中轴
//    int small = start;
//    for (int index = start+1; index <= end; ++index) {
//        if (data[index] < data[start]) {
//            ++small;
//            if (small != index)
//                Swap(data[index], data[small]);
//        }
//    }
//    if (small != start)
//        Swap(data[small], data[start]);

    return small;
}

void QuickSort(int data[], int length, int start, int end) {
    if (start == end)
        return;

    int middle = Partition(data, length, start, end);
    if (middle > start)
        QuickSort(data, length, start, middle-1);
    if (middle < end)
        QuickSort(data, length, middle+1, end);
}
int main() {
    int unsorted_list[] = {48, 56, 34, 76, 45, 77, 91, 36};
//    int unsorted_list[] = {}; // 测试异常
//    int unsorted_list[] = {99, 88, 77, 66, 55, 44, 33, 22}; // 测试最差时间效率
    int length_list = sizeof(unsorted_list) / sizeof(int);
    QuickSort(unsorted_list, length_list, 0, length_list-1);

    for (int i = 0; i < length_list; ++i) {
        cout << unsorted_list[i] << " ";
    }
    cout << endl;
    return 0;
}