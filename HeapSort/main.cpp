#include <iostream>

using namespace std;

class List {
private:
    int *array;
    int maxSize;
    int size;

    void heapify(int i, int n, int start)
    {
        int largest = i;
        int left = 2 * i + 1 - start;
        int right = 2 * i + 2 - start;

        if (left < n - start && array[left] > array[largest])
        {
            largest = left;
        }

        if (right < n - start && array[right] > array[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(array[i + start], array[largest + start]);
            heapify(largest, n, start);
        }
    }

    void heapifyReverse(int i, int n, int start)
    {
        int smallest = i;
        int left = 2 * i + 1 - start;
        int right = 2 * i + 2 - start;

        if (left < n - start && array[left] < array[smallest])
        {
            smallest = left;
        }

        if (right < n - start && array[right] < array[smallest])
        {
            smallest = right;
        }

        if (smallest != i)
        {
            swap(array[i + start], array[smallest + start]);
            heapifyReverse(smallest, n, start);
        }
    }

public:
    List(int maxSize)
    {
        this->maxSize = maxSize;
        array = new int[maxSize];
        size = 0;
    }

    ~List()
    {
        delete[] array;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == maxSize;
    }

    void printList()
    {
        if(!isEmpty())
        {
            for (int i = 0; i < size; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout<<"Heap is empty"<<endl;
        }
    }

    void HeapSort(bool ascending = true, int start = 0)
    {
        if (start < 0 || start >= size)
        {
            cout << "Invalid start position" << endl;
            return;
        }

        if (ascending)
        {
            for (int i = size / 2 - 1; i >= start; i--)
            {
                heapify(i, size, start);
            }

            for (int i = size - 1; i > start; i--)
            {
                swap(array[start], array[i]);
                heapify(start, i, start);
            }
        }
        else
        {
            for (int i = size / 2 - 1; i >= start; i--)
            {
                heapifyReverse(i, size, start);
            }

            for (int i = size - 1; i > start; i--)
            {
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
};


struct Node {
    int data_priority;
    int data_value;
    Node* next;
};

class PriorityQueue {
private:
    int size;
    Node* head;

public:
    PriorityQueue() {
        size = 0;
        head = nullptr;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void Enqueue(int priority, int value) {
        Node* newNode = new Node();
        newNode->data_priority = priority;
        newNode->data_value = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = newNode;
        } else {
            Node* current = head;
            Node* prev = nullptr;

            while (current != nullptr && current->data_priority >= priority) {
                prev = current;
                current = current->next;
            }

            if (prev == nullptr) {
                newNode->next = head;
                head = newNode;
            } else {
                prev->next = newNode;
                newNode->next = current;
            }
        }

        size++;
    }

    int DequeueMax() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int maxVal = head->data_value;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;

        return maxVal;
    }

    void PrintQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = head;

        while (current != nullptr) {
            cout << current->data_priority << ": " << current->data_value << endl;
            current = current->next;
        }
    }
};



int main() {
    List list(10);

    list.add(5);
    list.add(3);
    list.add(8);
    list.add(2);
    list.add(2);
    list.add(10);
    list.add(4);

    cout << "Unsorted List: ";
    list.printList();

    list.HeapSort();
    list.printList();

    list.HeapSort(false);
    cout<<"Start from 3 and sort by ascending: "<<endl;
    list.HeapSort(true,3);
    list.printList();

    PriorityQueue pq;
    pq.Enqueue(3,87);
    pq.Enqueue(2,17);
    pq.Enqueue(4,3);
    pq.Enqueue(1,90);
    pq.Enqueue(5,43);
    pq.Enqueue(6,75);
    pq.PrintQueue();
    cout<<pq.DequeueMax()<<endl;
    pq.PrintQueue();


    return 0;
}
