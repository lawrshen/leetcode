#include <vector>
using namespace std;

void maxheap(vector<int> &arr, int root, int last) {
    while (1) {
        int child = 2 * root + 1;
        if (child > last) {
            break;
        }
        if (child + 1 <= last && arr[child + 1] > arr[child]) {
            child++;
        }
        if (arr[root] > arr[child]) {
            break;
        }
        swap(arr[root], arr[child]);
        root = child;
    }
}

void heapSort(vector<int> &arr) {
    int last = arr.size() - 1; // 0 1 2 3 4
    for (int i = last / 2; i >= 0; i--) {
        maxheap(arr, i, last);
    }
    for (int i = last; i >= 0; i--) {
        swap(arr[0], arr[i]);
        maxheap(arr, 0, i - 1);
    }
}