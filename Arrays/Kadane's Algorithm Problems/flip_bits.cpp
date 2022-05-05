#include <iostream>
#include <vector>
using namespace std;

long long maxSubarraySum(const vector<int>&, int);

int main() {

    int n;
    cout << "Enter the size of an Array : ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "Enter " << n << " values (0's & 1's)  separated by space :";
    for(int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    long long result = maxSubarraySum(arr, n);
    cout << "Maximum Number of One's in subarray : " <<result << endl;
    return 0;    
}

long long maxSubarraySum(const vector<int> &arr, int n) {

    int current_sum = 0;
    int max_sum = 0;
    int number_of_ones = 0;

    for(int i = 0; i < n; i++) {

        if(arr[i] == 1) {
            number_of_ones += 1;
            current_sum -= 1;
        }
        else 
            current_sum += 1;
        
        current_sum += arr[i];
        max_sum = max(current_sum, max_sum);

        //if sum is below zero then start with new subarray by setting current_sum to 0
        if(current_sum < 0) 
            current_sum = 0;
    }
    return max_sum + number_of_ones;
}