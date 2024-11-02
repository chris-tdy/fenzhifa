#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // for std::swap
int partition(std::vector<int>& arr, int low, int high);
// ����������
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high); // ��ȡ������
        quickSort(arr, low, pivot - 1); // �ݹ�������������
        quickSort(arr, pivot + 1, high); // �ݹ�������������
    }
}
// ��������
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // ѡ�����һ��Ԫ����Ϊ��׼
    int i = low - 1; // �Ȼ�׼С��Ԫ�ص�����

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]); // ����С��Ԫ�ؽ��������
        }
    }
    std::swap(arr[i + 1], arr[high]); // ����׼�ŵ���ȷ��λ��
    return i + 1;
}
int main() {
    std::vector<int> arr = { 1, 2, 3, 4, 5, 6,7,8,9,10,11,12,13,14 };
    int n = arr.size();
    // ��¼��ʼʱ��
    auto start = std::chrono::high_resolution_clock::now();
    // ���ÿ�������
    quickSort(arr, 0, n - 1);
    // ��¼����ʱ��
    auto end = std::chrono::high_resolution_clock::now();
    // �������������ѵ�ʱ��
    std::chrono::duration<double> duration = end - start;
    std::cout << "�����ʱ: " << duration.count() << " ��" << std::endl;
    // ��ӡ����������
    std::cout << "����������: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}