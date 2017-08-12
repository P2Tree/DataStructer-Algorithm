// 冒泡排序
// 冒泡排序对于已排序的数组，会有不必要的判断，用noExchange做优化
// 最好效率发生在已排序数组中，是O(n)，最差效率发生在逆序时，是O(n2)
#include <iostream>

const int MAXSIZE = 10;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(int* L, int length) {
    if ( length <= 1)
        return;
    bool noExchange = false;        // 这个标记用来避免当输入数组是已排序的或近似已排序时，冒泡算法重复判断的效率问题

    for (int i = 0; i < length && !noExchange; i++) {
        noExchange = true;
        for (int j = length-1; j > i; j--) {
            if (L[j-1] > L[j]) {
                swap(&L[j-1], &L[j]);
                noExchange = false;
            }
        }
    }
}
int main() {
    int data[] = {35, 65, 84, 93, 28, 58, 38, 95, 61, 77};
    int length = sizeof(data) / sizeof(int);
    BubbleSort(data, length);

    for (int i = 0; i < length; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}