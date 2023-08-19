#include <iostream>
#include <pthread.h>

#define maxN 100

using namespace std;

int arr[maxN];
int tmp_arr[maxN];

void swap(int ind1, int ind2) {
     int tmp = arr[ind1];
     arr[ind1] = arr[ind2];
     arr[ind2] = tmp;
}

void merge_sort(int left, int right) {
     if (left == right) return;

     int mid = (left + right) / 2;
     merge_sort(left, mid);
     merge_sort(mid+1, right);

     int ind = mid + 1;
     int l = left;
     for (int i = left; i <= right; i++) {
         if (l == mid+1) {
             tmp_arr[i] = arr[ind++];
         }else if (ind == right+1) {
             tmp_arr[i] = arr[l++];
         }else if (arr[l] > arr[ind]) {
             tmp_arr[i] = arr[ind++];
         }else {
             tmp_arr[i] = arr[l++];
         }
     }
     for (int i = left; i <= right; i++) arr[i] = tmp_arr[i];
     return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>> n;
    for (int i = 0; i < n; i++) {
        cin>> arr[i];
    }

    merge_sort(0, n-1);
    for (int i = 0; i < n; i++) {
        cout<< arr[i]<< ' ';
    }
    cout<< '\n';
    return 0;
}

