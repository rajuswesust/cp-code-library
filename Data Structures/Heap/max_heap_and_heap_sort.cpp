#include <bits/stdc++.h>
using namespace std;

int left(int i) {
    return (2*i);
}

int right(int i) {
    return (2*i + 1);
}

int parent(int i) {
    return i/2;
}

void print_heap(int h[], int n) {
    for(int i = 1; i < n; i++)
        cout << h[i] << " ";
    cout << endl;
}

void max_heapify(int h[], int n, int i) {
    int l = left(i);
    int r = right(i);
    int ind;    //largest value among index i and it's child l, r will be stored

    //cout << "(" << i << ")" << l << " " << r << endl;

    if(l < n && h[i] < h[l])
        ind = l;
    else
        ind = i;
    if(r < n && h[ind] < h[r])
        ind = r;

    //cout << "##" << ind << endl;

    //base case - if h[i] is the largest
    if(ind == i)
        return;

    swap(h[i], h[ind]);
    max_heapify(h, n, ind);
}

void build_heap(int h[], int n) {
    for(int i = n/2; i >= 1; i--) {
        max_heapify(h, n, i);
        cout << i << " : " << endl;
        print_heap(h, n);
    }
}

//deleting root of the heap
//swap root and last element(by doing this we are maintaining complete BT)
//call max_heapify() to adjust the heap(max heap hoye jabe)
//heap er size 1 kore kombe
void heap_sort(int h[], int n) {
    int i = n-1;
    while(i > 1) {
        swap(h[1], h[i]);
        max_heapify(h, i, 1);
        i--;
    }
}

int main() {
    int heap[] = {0, 4, 7, 12, 3, 5, 17, 10, 1, 2};
    int n = sizeof(heap) / sizeof(heap[0]);

    //print_heap(heap, n);
    //max_heapify(heap, n, 3);
    //print_heap(heap, n);

    build_heap(heap, n);
    print_heap(heap, n);

    heap_sort(heap, n);
    print_heap(heap, n);

    return 0;
}

