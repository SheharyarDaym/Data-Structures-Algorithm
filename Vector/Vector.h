#pragma
#include<iostream>
using namespace std;

template <class T>	// Class Template
class Vector {
private:
	int size;
	T* arr;

public:
// Constructors
	Vector(): size(0) {
		arr = new T[size];
	}

	Vector(int s) : size(s) {}

	Vector(int n, int s) {
		size = s;	
		for (int i = 0; i < size; i++) {
			arr[i] = n;	// initialize all element with n
		}
	}

// Modifiers
	void push_back(int n) {
		T* temp = new T[size];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		size++;
		delete arr;
		arr = new T[size];
		for (int i = 0; i < size; i++) {
			if (i == size - 1) {
				arr[i] = n;
			}
			else arr[i] = temp[i];
		}
		delete[] temp;
	}

	void pop_back() {
		T* temp = new T[size];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		if(size!=0) size--;
		delete arr;
		arr = new T[size];
		for (int i = 0; i < size; i++) {
			arr[i] = temp[i];
		}
		delete[] temp;
	}

	void insert(int index, T n) {
		arr[index] = n;
	}

	void erase(int index) {
        if (index < 0 || index >= size) {
            // Index out of bounds
            return;
        }
        
        T* temp = new T[size - 1]; 

        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) {
                temp[j++] = arr[i];
            }
        }
        
        delete[] arr; 
        arr = temp; 
        size--; 
    }

    void swap(Vector& v) {
        Vector Temp;
        Temp = *this;
        *this = v;
        v = Temp;
    }

// Capacity
	int Size() {
		return size;
	}
	
// Element access
	T& operator [] (int index) {
		return arr[index];
	}

    T& at (int index) {
        return arr[index];
    }

    T& first() {
        return arr[0];
    }

    T& back() {
        return arr[size-1];
    }
    



	void display() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	

};

