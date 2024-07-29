template <class T>
void Sorting<T>::BubbleSort(T* arr, int size)
{
    // Time Complexity O(n^2) & Space Complexity O(1)..
    // Bubble sort is a Stable because it doesn't swap same elements..
    // Repeated swap 2 adjacent elements if they are in wrong order..
    int s = size;
    for(int i=0; i<size; i++){
        int count = 0;
        for(int j=0; j<s; j++){
            if(arr[j] > arr[j+1] && (j!=s-1)){ // (j!=s-1), means last element (out of bound)
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count = 1;
            }
        }
        if(count == 0) break;   // Just for optimizing the code
        s--;
    }
}
