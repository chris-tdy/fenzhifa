#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // for std::swap
int partition(std::vector<int>& arr, int low, int high);
// 快速排序函数
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high); // 获取分区点
        quickSort(arr, low, pivot - 1); // 递归排序左子数组
        quickSort(arr, pivot + 1, high); // 递归排序右子数组
    }
}
// 分区函数
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = low - 1; // 比基准小的元素的索引

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]); // 将较小的元素交换到左边
        }
    }
    std::swap(arr[i + 1], arr[high]); // 将基准放到正确的位置
    return i + 1;
}
int main() {
    std::vector<int> arr = { 1, 2, 3, 4, 5, 6,7,8,9,10,11,12,13,14 };
    int n = arr.size();
    // 记录开始时间
    auto start = std::chrono::high_resolution_clock::now();
    // 调用快速排序
    quickSort(arr, 0, n - 1);
    // 记录结束时间
    auto end = std::chrono::high_resolution_clock::now();
    // 计算排序所花费的时间
    std::chrono::duration<double> duration = end - start;
    std::cout << "排序耗时: " << duration.count() << " 秒" << std::endl;
    // 打印排序后的数组
    std::cout << "排序后的数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}