#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAXM = 100;
const int MAXN = 1000;

void merge(pair <string, int> a[], int l, int mid, int r){
    pair<string, int> aux[MAXN];
    for(int i = l; i <= r; i++)
        aux[i] = a[i];
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        if(aux[i].second >= aux[j].second)
            a[k++] = aux[i++];
        else 
            a[k++] = aux[j++];
    }
    while(i <= mid)
        a[k++] = aux[i++];
    while(j <= r)
        a[k++] = aux[j++];
}

void mergeSort(pair <string, int> a[], int l, int r){
    if(l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}

void loadBalancing(vector <int> processor[], int sumProcessor[], pair <string, int> a[], int m, int n){
    mergeSort(a, 0, n - 1);
    for(int i = 0; i < n; i++){
        int idxMin = 0;
        for(int j = 1; j < m; j++)
            if(sumProcessor[idxMin] > sumProcessor[j])
                idxMin = j;
        processor[idxMin].push_back(i);
        sumProcessor[idxMin] += a[i].second;
    }
}

int main(){
    int m, n;
    cin >> m >> n;
    pair <string, int> a[MAXN];
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    vector <int> processor[MAXM];
    int sumProcessor[MAXM] = {0};
    loadBalancing(processor, sumProcessor, a, m, n);
    int makespan = 0;
    for(int i = 0; i < m; i++){
        cout << "Processor " << i + 1 << ": ";
        for(int x : processor[i]){
            cout << a[x].first << ' ';
        }
        cout << "(load: " << sumProcessor[i] << ")";
        makespan = max(makespan, sumProcessor[i]);
        cout << endl;
    }
    cout << "Makespan: " << makespan;
    return 0;
}