#include <iostream>
#include <vector>
using namespace std;

long long maxSubarraySumConcat(const vector<int>&, int, int);

int main() {

    int n, k;
    cout << "Enter the size of an Array and value for k separated by space : ";
    cin >> n >> k;
    vector<int> arr(n, 0);
    cout << "Enter " << n << " values separated by space : ";
    for(int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    long long result = maxSubarraySumConcat(arr, n, k);
    cout << "Maximum Subarray sum after" << k << " concatenations : " <<result << endl;
    return 0;    
}

long long maxSubarraySumConcat(const vector<int> &arr, int n, int k)
{
	long long current_sum = 0;
	long long max_sum = arr[0];
	long long sum = 0;
	for(int j = 0; j < n; j++) {
		current_sum += arr[j];
		max_sum = max(max_sum, current_sum);
		if(current_sum < 0)
			current_sum = 0;
		sum += arr[j];
	}
	if(k > 1) {
		for(int j = 0; j < n; j++) {
		current_sum += arr[j];
		max_sum = max(max_sum, current_sum);
		if(current_sum < 0)
			current_sum = 0;
		}
	}
	else 
		return max_sum;
	
	if (sum > 0) 
		return max_sum + (k - 2)*sum; 
	else 
		return max_sum;
}