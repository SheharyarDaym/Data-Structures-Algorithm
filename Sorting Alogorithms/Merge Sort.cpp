template <class T>
void Sorting<T>::merge(T* arr, int low, int mid, int high) {
    int n = high - low + 1;
    T* temp = new T[n];  
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i < n; i++) {
        arr[low + i] = temp[i];
    }

    delete[] temp;  
}

template <class T>
void Sorting<T>::Merge_Sort(T* arr, int low, int high) 
{
    if (low < high) {
        int middle = (low + high) / 2;  // low + (high - low) / 2
        Merge_Sort(arr, low, middle);
        Merge_Sort(arr, middle + 1, high);
        merge(arr, low, middle, high);
    }
}
