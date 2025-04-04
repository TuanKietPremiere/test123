#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1e4;
const int MAXKEY = 37; // 36 ki tu + 1 ki tu rong

int key(char ch){
    if(ch >= '0' && ch <= '9')
        return ch - '0' + 1;
    else
        return ch - 'a' + 11;
}

void radixSort(string a[], int n){
    string aux[MAXN];
    int maxLen = 0;
    for(int i = 0; i < n; i++)
        maxLen = max(maxLen, static_cast<int>(a[i].length()));
    for(int i = maxLen - 1; i >= 0; i--){
        int count[MAXKEY + 1];
        for(int j = 0; j <= MAXKEY; j++)
            count[j] = 0;
        for(int j = 0; j < n; j++){
            if(i < static_cast<int>(a[j].length())){
                count[key(a[j][i]) + 1]++;
            }
            else
                count[1]++;
        }
        for(int j = 1; j <= MAXKEY; j++)
            count[j] += count[j - 1];
        for(int j = 0; j < n; j++){
            if(i < static_cast<int>(a[j].length())){
                aux[count[key(a[j][i])]++] = a[j];
            }
            else
                aux[count[0]++] = a[j];
        }
        for(int j = 0; j < n; j++)
            a[j] = aux[j];
    }
}

int main(){
    int n;
    string a[MAXN];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    radixSort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    return 0;
}