template <class T>
void Sorting<T>::SelectionSort(T* arr, int size)
{
    // Time Complexity O(n^2) & Space Complexity O(1)
    // Selection sort is an Unstable because it swap same elements..
    // Repeatedly find minimum element in unsorted array & place it 
    // at begining of the array --> Until Array is sorted..
    T min = arr[0];
    for(int i=0; i<size; i++){
        min = i;
        for(int j=i; j<size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(i != min){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
