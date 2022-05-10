#include <iostream>

using namespace std;

int search(int*, int ,int);

int main() {

    int n, key;
    cout << "Enter the size of an array : ";
    cin >> n;
    cout << "Enter " << n << " elements in rotated sorted order : ";
    int arr[n];
    for(int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }  
    cout << "Enter the element to serach index : ";
    cin >> key;

    int res = search(arr, n, key);
    if(res == -1) 
        cout << "element is not found" << endl;
    else 
        cout << key << " is found at " << res << " index" << endl;
        
    return 0;
}

int search(int* arr, int n, int key) {
  int low=0,high=n-1;
   while(low<=high){
       int mid=low+(high-low)/2;
       if(arr[mid]==key)
           return mid;
       if(arr[low]<=arr[mid]){
           if(arr[low]<=key and key<arr[mid]){
               high=mid-1;
           }
           else{
               low=mid+1;
           }
       }
       else{
           if(arr[high]>=key){
               low=mid+1;
           }
           else{
               high=mid-1;
           }
       }
   }
   if(arr[low]==key) return low;
   else
       return -1;
}