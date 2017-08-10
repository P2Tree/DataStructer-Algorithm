// Time complication of Binary Search is O(logn)
// Time complication of Interpolation Search is O(logn), but It's performance is better than Bianry Search
#include <iostream>
#include <string.h>

using namespace std;

int Binary_Search(int* a, int n, int key) {
    if (n == 0)
        return -1;
    int head = 0;
    int tail = n-1;
    int mid;
    while(tail-head >= 0) {
        mid = head + (tail - head) / 2;
        // Interpolation Search
        // exchange mid with:
        // mid = head + (key - a[head]) / (a[tail] - a[head]) * (tail - head);
        if (a[mid] == key)
            return mid;
        else if(a[mid] < key)
            head = mid + 1;
        else if(a[mid] > key)
            tail = mid - 1;
    }
    return -2;
}

int main() {
    int ordered_list[] = {1, 16, 24, 35, 47, 59, 62, 73, 88, 94};
    int position = Binary_Search(ordered_list, sizeof(ordered_list) / sizeof(int), 16);
    if (position >= 0)
        cout << "find the position is: " << position+1 << endl;
    else if(position == -1)
        cout << "Please input valid value" << endl;
    else if (position == -2)
        cout << "Can't find the position of 'key'" << endl;
    return 0;
}