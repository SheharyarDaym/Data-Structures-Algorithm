template <class T>
int Sorting<T>::partition(T* arr, int low, int high)
{
    T pivot = arr[high];  
    int i = low;  

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            swap(arr[i], arr[j]);
            i++; 
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

template <class T>
void Sorting<T>::QuickSort(int* arr, int low ,int high)
{
    if(low < high){
        int pi;
        pi = partition(arr, low, high);
        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);
    }
}
