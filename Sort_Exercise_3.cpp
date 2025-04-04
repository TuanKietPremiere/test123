#include <iostream>
using namespace std;
const int MAXN = 1e5;

//edited by Huy abcasdklasjfjlaaj slkjglsajflkasjlfka,dskgjsa;dfjlkajisad,mfnsadlkflksahflkslk
// sdjaflkasjlkfjsfjsafknaslfasjf
// Chào mừng thế giới

void printArray(int a[], int n){
    if(n <= 0){
        cout << "[]\n";
        return;
    }
    cout << "[" << a[0];
    for(int i = 1; i < n; i++){
        cout << ", " << a[i];
    }
    cout << "]\n";
}

// TC: O(n), SC: O(1), only correct for non-negative integer array
/*
void mergeInPlace(int a[], int l, int mid, int r){
    int mx = max(a[mid], a[r]) + 1;
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        int x1 = a[i] % mx;
        int x2 = a[j] % mx;
        if(x1 <= x2){
            a[k++] += x1 * mx;
            i++;
        }
        else{
            a[k++] += x2 * mx;
            j++;
        }
    }
    while(i <= mid){
        int x1 = a[i] % mx;
        a[k++] += x1 * mx;
        i++;
    }
    while(j <= r){
        int x2 = a[j] % mx;
        a[k++] += x2 * mx;
        j++;
    }
    for(int i = l; i <= r; i++)
        a[i] /= mx;
}
*/

// Idea: Shell sort
// TC: average O(nlogn), worst O(n^2), SC: O(1)
void mergeInPlace(int a[], int l, int mid, int r){
    int gap = mid + 1 - l;
    for(; gap > 0; gap = gap / 2){
        for(int i = l + gap; i <= r; i++){
            int v = a[i], j;
            for(j = i; j >= l + gap && v < a[j - gap]; j -= gap)
                a[j] = a[j - gap];
            a[j] = v;
        }
    }
}

void mergeSortWithInPlaceMerging(int a[], int l, int r, int n){
    if(l >= r) return;
    int mid = (l + r) / 2;
    mergeSortWithInPlaceMerging(a, l, mid, n);
    mergeSortWithInPlaceMerging(a, mid + 1, r, n);
    mergeInPlace(a, l, mid, r);
    cout << "Merge " << l << ' ' << r << ": ";
    printArray(a, n);
}

int main(){
    int n, a[MAXN];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Initial Array: ";
    printArray(a, n);
    mergeSortWithInPlaceMerging(a, 0, n - 1, n);
    cout << "Final Sorted Array: ";
    printArray(a, n);
    return 0;
}