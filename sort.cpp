#include<iostream>
#include<iostream>
#include<vector>

using namespace std;

//1.冒泡算法
vector<int> bubble_sort(int array[], int N) {
    vector<int> result;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i-1; j++) {
            if (array[j] > array[j + 1]) {
                int value = array[j+1];
                array[j + 1] = array[j];
                array[j] = value;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        result.push_back(array[i]);
    }
    return result;
}

//2.选择排序
vector<int> select_sort(int array[], int N) {
    vector<int> result;
    for (int i = 0; i < N; i++) {
        int max = array[0];
        int max_location = 0;
        for (int j = 0; j < N - i; j++) {
            if (array[j] > max) {
                max = array[j];
                max_location = j;
            }
        }
        array[max_location] = array[N - i-1];
        array[N-i-1] = max;
    }
    for (int i = 0; i < N; i++) {
        result.push_back(array[i]);
    }
    return result;
}

//3.插入排序
vector<int> insertion_sort(int array[], int N) {
    vector<int> result;
    for (int i = 1; i < N; i++) {
        int n = i;
        int key = array[n];
        while (array[n - 1] > key) {
            array[n] = array[n - 1];
            n--;
            if (n == 0) {
                break;
            }
        }
        array[n] = key;
    }
    for (int i = 0; i < N; i++) {
        result.push_back(array[i]);
    }
    return result;    
}

//4.快速排序
void QuickSort(vector<int>& result, int L, int R) {
    if (L >= R) {
        return;
    }
    int left = L;
    int right = R;
    int pivot = result[left];
    while (left < right) {
        while (left < right && result[right] >= pivot) {
            right--;
        }
        if (left < right) {
            result[left] = result[right];
        }
        while (left < right && result[left] <= pivot) {
            left++;
        }
        if (left < right) {
            result[right] = result[left];
        }
        if (left >= right) {
            result[left] = pivot;
        }
    }
    QuickSort(result, L, right - 1);
    QuickSort(result, right + 1, R);
}
vector<int> quick_sort(int array[], int N) {
    vector<int> result;
    for (int i = 0; i < N; i++) {
        result.push_back(array[i]);
    }
    int L = 0;
    int R = N - 1;
    QuickSort(result, L, R);
    return result;
}

//5.堆排序
void HeapSort(vector<int>& result, int count, int location) {
    if (location<0 || location>count) {
        return;
    }

    int left_location = 2 * location + 1;
    int right_locaton = 2 * location + 2;
    int max = result[location];

    if (left_location < count && max < result[left_location]) {
        max = result[left_location];
    }
    if (right_locaton < count && max < result[right_locaton]) {
        max = result[right_locaton];
    }

    if (max != result[location]) {
        if (left_location < count && max == result[left_location]) {
            result[left_location] = result[location];
            HeapSort(result, left_location, count);
        }
        else if (right_locaton < count && max == result[right_locaton]) {
            result[right_locaton] = result[location];
            HeapSort(result, right_locaton, count);
        }
        result[location] = max;
    }
}
vector<int> heap_sort(int array[], int N) {
    vector<int> result;
    for (int i = 0; i < N; i++) {
        result.push_back(array[i]);
    }
    for (int count = N; count > 0; count--) {
        for (int location = count / 2; location >= 0; location--) {
            HeapSort(result, count, location);
        }
        int value = result[0];
        result[0] = result[count - 1];
        result[count - 1] = value;
    }
    return result;
}

//6.归并排序
void Merge(int left, int mid, int right, vector<int>& result) {
    int i = left;
    int j = mid;
    vector<int> temp;
    while (i < mid && j <= right) {
        if (result[i] < result[j]) {
            temp.push_back(result[i]);
            i++;
        }
        else {
            temp.push_back(result[j]);
            j++;
        }
    }
    while (i < mid) {
        temp.push_back(result[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(result[j]);
        j++;
    }
    for (int i = 0; i <= right-left; i++) {
        result[i + left] = temp[i];
    }
}
void MergeSort(int left, int right, vector<int>& result) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    MergeSort(left, mid, result);
    MergeSort(mid + 1, right, result);
    Merge(left, mid+1, right, result);
}
vector<int> merge_sort(int array[], int N) {
    int left = 0;
    int right = N - 1;
    vector<int> result;
    for (int i = 0; i < N; i++) {
        result.push_back(array[i]);
    }
    MergeSort(left, right, result);
    return result;
}

//7.希尔排序
void shell_swap(int a, int b, vector<int>& result) {
    int temp = result[a];
    result[a] = result[b];
    result[b] = temp;
}
vector<int> shell_sort(int array[], int N) {
    vector<int> result;

    for (int i = 0; i < N; i++) {
        result.push_back(array[i]);
    }
    for (int gap = N / 2; gap > 0; gap--) {
        for (int i = gap; i < N; i++) {
            for (int j = i - gap; j >= 0 && result[j] > result[j + gap]; j -= gap) {
                shell_swap(j, j + gap, result);
            }
        }
    }
    return result;
}

int main()
{
    int array[] = { 2,6,1,5,0,8,4,3,10 };
    int N = sizeof(array)/4;
    vector<int> sorted;
    
    //sorted= bubble_sort(array, N);
    //sorted = select_sort(array, N);
    //sorted = insertion_sort(array, N);
    //sorted = quick_sort(array, N);
    //sorted = heap_sort(array, N);
    //sorted = merge_sort(array, N);
    sorted = shell_sort(array, N);
    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << " ";
    }
    cout << endl;
    return 0;

}
