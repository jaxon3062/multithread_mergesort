#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> tmp_arr;

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

typedef struct bound {
     int left;
     int right;
} bound;

void *mt_merge_sort(void *args) {
     bound *B = (bound*)args;
     int left = B->left;
     int right = B->right;
     if (left == right) return NULL;

     pthread_t tidL, tidR;
     pthread_attr_t attr;
     pthread_attr_init(&attr);

     int mid = (left + right) / 2;
     bound left_half = (bound){.left = left, .right = mid};
     bound right_half = (bound){.left = mid+1, .right = right};
     pthread_create(&tidL, &attr, mt_merge_sort, (void*)(&left_half)); // merge_sort(left, mid);
     pthread_create(&tidR, &attr, mt_merge_sort, (void*)(&right_half)); // merge_sort(mid+1, right);
     pthread_join(tidL, NULL);
     pthread_join(tidR, NULL);

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
     return NULL;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>> n;
    arr.resize(n);
    tmp_arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin>> arr[i];
    }

    if (argc == 1 || (string)argv[1] == "normal") merge_sort(0, n-1);
    else if ((string)argv[1] == "mt") {
         bound B = (bound){0, n-1};
         mt_merge_sort((void*)&B);
    }else {
         cout<< "No sort\n";
         return 0;
    }

    for (int i = 0; i < n; i++) {
        cout<< arr[i]<< ' ';
    }
    cout<< '\n';
    return 0;
}

