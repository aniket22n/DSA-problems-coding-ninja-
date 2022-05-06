#include <iostream>

using namespace std;

void sort012(int *, int);

int main() {

    int n; 
    cout << "Enter the size of an Array : ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " values separated by space (0's, 1's and 2's allowed only) : ";
    for(int i  = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort012(arr, n);
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
void sort012(int *arr, int n)
{
	int low = 0, mid = 0, high = n - 1;

    while( mid <= high) {

        if(arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            mid += 1;
            low += 1; 
        }
        else if(arr[mid] == 1) {
            mid += 1;
        }
        else {
            swap(arr[mid], arr[high]);
            high -= 1;
        }
    }
}
