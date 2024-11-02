#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
// 非递归版本的二分搜索函数
int binarySearchIterative(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
// 测试函数
void testBinarySearch(int (*searchFunc)(int[], int, int, int), const char* funcName, int* arr, int size, int target) {
    auto start = high_resolution_clock::now();
    int result = searchFunc(arr, 0, size - 1, target);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if (result != -1) {
        cout << "元素 " << target << " 在数组中的索引为 " << result << endl;
    }
    else {
        cout << "元素 " << target << " 不在数组中" << endl;
    }
    cout << funcName << " 运行时间: " << duration.count() << " 微秒" << endl;
}
int main() {
    const int sizes[] = { 100, 1000, 10000, 100000, 1000000 };
    for (auto size : sizes) {
        int* arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = i + 1;
        }
        int target = size / 2; // 选择中间值作为目标值
        cout << "数组大小: " << size << endl;
        // 测试非递归版本
        testBinarySearch(binarySearchIterative, "非递归版本", arr, size, target);
        delete[] arr;
        cout << endl;
    }
    return 0;
}