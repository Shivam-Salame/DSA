#include<bits/stdc++.h>
using namespace std;

void subsequence(int idx, vector<int> &dataStore, vector<int> &arr, int size) {
    if( ind == size ) {
        for ( auto it: dataStore ) {
            cout << it << " "; 
        }
        cout << endl;
        return;
    }
    // pick
    dataStore.push_back(arr[ind]);
    subsequence(ind + 1, dataStore, arr, size);

    // not-pick
    dataStore.pop_back(arr[ind]);
    subsequence(ind + 1, dataStore, arr, size);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "2", stdout);
    #endif

    vector<int> arr[] = { 3, 1, 2 };
    int size = arr.size();
    vector<int> dataStore;

    subsequence(0, dataStore, arr, size);

    return 0;
}