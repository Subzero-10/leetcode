#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void quicksort(int left, int right, vector<int>& arr){
    if(left>=right) return;
    int a = arr[left];
    int l = left;
    int r = right;
    while(left<right){
        while(left<right && arr[right] > a) right--;
        arr[left]=arr[right];
        while(left<right && arr[left] <= a) left++;
        arr[right]=arr[left];
    }
    arr[left] = a;
    quicksort(l, left-1, arr);
    quicksort(left+1, r, arr);
}

int main(){
    int n ;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    quicksort(0, n-1, arr);
    for(int i = 0; i<n-1; i++){
        cout<<arr[i] <<endl;
    }
    cout<<arr[n-1]<<endl;
    system("pause");
}