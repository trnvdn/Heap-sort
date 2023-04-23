#include <iostream>

using namespace std;

class List {
private:
    int *array;
    int maxSize;
    int size;

    void heapify(int i, int n, int start) {
        int largest = i;
        int left = 2 * i + 1 - start;
        int right = 2 * i + 2 - start;

        if (left < n - start && array[left] > array[largest]) {
            largest = left;
        }

        if (right < n - start && array[right] > array[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(array[i + start], array[largest + start]);
            heapify(largest, n, start);
        }
    }

    void heapifyReverse(int i, int n, int start) {
        int smallest = i;
        int left = 2 * i + 1 - start;
        int right = 2 * i + 2 - start;

        if (left < n - start && array[left] < array[smallest]) {
            smallest = left;
        }

        if (right < n - start && array[right] < array[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(array[i + start], array[smallest + start]);
            heapifyReverse(smallest, n, start);
        }
    }

public:
    List(int maxSize) {
        this->maxSize = maxSize;
        array = new int[maxSize];
        size = 0;
    }

    ~List() {
        delete[] array;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == maxSize;
    }

    void printList() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void HeapSort(bool ascending = true, int start = 0) {
        if (start < 0 || start >= size) {
            cout << "Invalid start position" << endl;
            return;
        }

        if (ascending) {
            for (int i = size / 2 - 1; i >= start; i--) {
                heapify(i, size, start);
            }

            for (int i = size - 1; i > start; i--) {
                swap(array[start], array[i]);
                heapify(start, i, start);
            }
        } else {
            for (int i = size / 2 - 1; i >= start; i--) {
                heapifyReverse(i, size, start);
            }

            for (int i = size - 1; i > start; i--) {
                swap(array[start], array[i]);
                heapifyReverse(start, i, start);
            }
        }
    }

    void add(int item) {
        if (isFull()) {
            cout << "List is full" << endl;
            return;
        }

        array[size] = item;
        size++;
    }

    void clear() {
        size = 0;
    }
};

int main() {
    // declare an object of List class
    List list(10);

    // create an unsorted list of integer items
    list.add(5);
    list.add(3);
    list.add(8);
    list.add(2);
    list.add(2);

    // print the content of the list object
    cout << "Unsorted List: ";
    list.printList();

    list.HeapSort(true,2);
    list.printList();


    return 0;
}
