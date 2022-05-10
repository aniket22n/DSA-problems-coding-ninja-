#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < int > countSmallerOrEqual(int *, int *, int, int);
int find_index(int *, int, int);

int main() {

    int n, m;
    cout << "Enter the size of array A and B :";
    cin >> n >> m;
    int a[n], b[m];

    cout << "Enter the array A elements : ";
    for( int i = 0; i < n; i++)
        cin >> a[i];
    
    cout << "Enter the array B elements : ";
    for(int i = 0; i < m; i++)
        cin >> b[i];

    sort(b, b + m);

    vector<int> res (n, 0);
    res = countSmallerOrEqual(a, b, n, m);

    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}

vector < int > countSmallerOrEqual(int * a, int * b, int n, int m) {

    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++)
        ans[i] = find_index(b, m, a[i]);
    return ans;
} 

int find_index(int arr[], int m, int K)
{
    int low = 0, high = m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == K) {
            low = mid + 1;
        }
        else if (arr[mid] < K)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high + 1;
}