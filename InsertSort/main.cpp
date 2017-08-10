// 插入排序
// 插入排序是在位的，它的平均时间效率是O(n2)
// 由于它的最优效率发生在数组已排序时，为O(n)，所以它对于基本有序的数组有良好效果
// 优于选择排序和冒泡排序
#include <iostream>
using namespace std;

void InsertSort(int list[], int n) {
    int i, j;

    int temp;
    for (i = 1; i < n; i++) {   // 默认第一个元素是排序过的
        temp = list[i]; // 取出一个元素
        for (j = i; j > 0 && temp < list[j - 1]; j--) {
            // 如果找到比当前元素大的元素，则向后移动一位
            list[j] = list[j - 1];
        }
        list[j] = temp; // 将当前元素填充到最后的空位
    }
}
int main() {
    int list[8] = { 14, 85, 34, 67, 47, 93, 45, 88};
    InsertSort(list, 8);
    for (int i = 0; i < 8; i++)
        cout << list[i] << " ";
    cout << endl;
    return 0;
}