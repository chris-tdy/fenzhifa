#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
// �ǵݹ�汾�Ķ�����������
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
// ���Ժ���
void testBinarySearch(int (*searchFunc)(int[], int, int, int), const char* funcName, int* arr, int size, int target) {
    auto start = high_resolution_clock::now();
    int result = searchFunc(arr, 0, size - 1, target);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if (result != -1) {
        cout << "Ԫ�� " << target << " �������е�����Ϊ " << result << endl;
    }
    else {
        cout << "Ԫ�� " << target << " ����������" << endl;
    }
    cout << funcName << " ����ʱ��: " << duration.count() << " ΢��" << endl;
}
int main() {
    const int sizes[] = { 100, 1000, 10000, 100000, 1000000 };
    for (auto size : sizes) {
        int* arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = i + 1;
        }
        int target = size / 2; // ѡ���м�ֵ��ΪĿ��ֵ
        cout << "�����С: " << size << endl;
        // ���Էǵݹ�汾
        testBinarySearch(binarySearchIterative, "�ǵݹ�汾", arr, size, target);
        delete[] arr;
        cout << endl;
    }
    return 0;
}