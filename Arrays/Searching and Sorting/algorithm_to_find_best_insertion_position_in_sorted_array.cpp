#include <iostream>
#include <vector>
using namespace std;

int bestInsertPos(vector<int>,int ,int);

int main() {

    int n, m;
    cout << "Enter the size of array :";
    cin >> n;

    vector<int> a(n, 0);
    cout << "Enter the array elements : ";
    for( int i = 0; i < n; i++)
        cin >> a[i];
    
    cout << "Enter the element to be inserted : ";
    cin >> m;
    
    int ans;
    if(n)
        ans = bestInsertPos(a, n, m);
    else
        ans = 0;

    cout << ans << endl;

    return 0;
}

int bestInsertPos(vector<int> arr, int n, int m) {

    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == m)
            return mid;
        if(arr[mid] > m)
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return high + 1;
}