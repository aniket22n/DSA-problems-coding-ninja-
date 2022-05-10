#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possibleToMakeTriangle(vector<int> &);

int main() {
    int n;
    cout << "Enter the size of an array : ";
    cin >> n;
    cout << "Enter " << n << " elements : ";
    vector<int> arr(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(possibleToMakeTriangle(arr))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

    return 0;
}
bool possibleToMakeTriangle(vector<int> &arr) {

    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size() - 2; i++) {
        if(arr[i] + arr[i + 1] > arr[i + 2] && arr[i + 2] - arr[i] < arr[i + 1])
            return true;
    }
    return false;
}