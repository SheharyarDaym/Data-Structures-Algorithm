template <class T>
void Sorting<T>::insertionSort(T* arr, int size)
{
    // Time Complexity O(n^2) & Space Complexity O(1)
    // Application of insertion sort is more applicable when array is almost sorted / only few elements are unsorted.. 
    // Insertion sort is an Stable because it does not swap same elements..
    // Repeatedly take elements from unsorted suubarray and & insert in sorted subarray..
    for(int i=1; i<size; i++){
        int curr = arr[i];
        
        int j = i-1;
        while(j>=0 && arr[j] > curr){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}
