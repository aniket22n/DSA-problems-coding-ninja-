#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> findFirstLastPosition(vector<int>&, int, int);

int main() {

    int n, x;
    cout << "Enter the size of an array : ";
    cin >> n;
    cout << "Enter " << n << " space separated elements :";
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << "Enter an element to find first and last appearance : ";
    cin >> x;

    pair<int, int> p = findFirstLastPosition(arr, n, x);
    cout << p.first << " " << p.second << endl;

    return 0;
}
pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x) {

    int first = -1, last = -1;    
    int low = 0, high = n - 1;
    bool found = false;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == x) {
            first = mid;
            high = mid - 1;
        } 
        else {
            if(arr[mid] > x) 
                high = mid - 1;
            else 
                low = mid + 1;
        }            
    }
    low = first, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == x) {
            last = mid;
            low = mid + 1;   
        }
        else {
            if(arr[mid] > x) 
                high = mid - 1;
            else 
                low = mid + 1;
            }            
    }
    return make_pair(first, last);
}