#include <iostream>
#include <vector>
using namespace std;

long long maxSubarraySum(const vector<int>&, int);

int main() {

    int n;
    cout << "Enter the size of an Array : ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "Enter " << n << " values separated by space :";
    for(int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    long long result = maxSubarraySum(arr, n);
    cout << "Maximum Subarray sum : " <<result << endl;
    return 0;    
}

long long maxSubarraySum(const vector<int> &arr, int n) {
    int current_sum = 0;
    int max_sum = 0;
    for(int i = 0; i < n; i++) {
        current_sum += arr[i];
        max_sum = max(current_sum, max_sum);
        //if sum is below zero then start with new subarray by setting current_sum to 0
        if(current_sum < 0) 
            current_sum = 0;
    }
    return max_sum;
}