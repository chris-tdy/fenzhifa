#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// ��������Ԫ��
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// ������ֵ��ѡ���׼ֵ
int medianOfThree(std::vector<int>& arr, int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid]) swap(arr[left], arr[mid]);
    if (arr[left] > arr[right]) swap(arr[left], arr[right]);
    if (arr[mid] > arr[right]) swap(arr[mid], arr[right]);
    return mid;
}

// ���ֺ���
int partition(std::vector<int>& arr, int left, int right) {
    int pivotIndex = medianOfThree(arr, left, right);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]);  // ����׼ֵ�Ƶ�����ĩβ
    int storeIndex = left;

    for (int i = left; i < right; ++i) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }

    swap(arr[right], arr[storeIndex]);  // ����׼ֵ�ŵ���ȷ��λ��
    return storeIndex;
}

// ����ѡ����
int quickSelect(std::vector<int>& arr, int left, int right, int k) {
    if (left == right) return arr[left];

    int pivotIndex = partition(arr, left, right);

    if (k == pivotIndex) {
        return arr[k];
    }
    else if (k < pivotIndex) {
        return quickSelect(arr, left, pivotIndex - 1, k);
    }
    else {
        return quickSelect(arr, pivotIndex + 1, right, k);
    }
}

int main() {
    std::vector<int> arr = { 3, 6, 2, 7, 1, 5, 4 };
    int k = 3;  // Ѱ�ҵ�3С��Ԫ��

    // ��¼��ʼʱ��
    auto start = std::chrono::high_resolution_clock::now();

    int result = quickSelect(arr, 0, arr.size() - 1, k - 1);
    std::cout << "The " << k << "rd smallest element is " << result << std::endl;
    k += 1;
    result = quickSelect(arr, 0, arr.size() - 1, k - 1);
    std::cout << "The " << k << "rd smallest element is " << result << std::endl;
    // ��¼����ʱ��
    auto end = std::chrono::high_resolution_clock::now();

    // ��������ʱ��
    std::chrono::duration<double> duration = end - start;

    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
}