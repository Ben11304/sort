#include<iostream>
// #include<vector> 
#include<algorithm>
#include<ctime>
#include<random>
// #include<Merge_sort>
#define MAXN 1000000
#define NUM 10
using namespace std;

int ARR[NUM][MAXN];
void merge(vector<int>& arr, int left, int mid, int right);
void merge_sort(vector<int>& arr, int left, int right);
void Rand_Arr(int num);


int main() {
    vector<int> vec(ARR[1],ARR[1]+MAXN-1);
	merge_sort(vec,0,MAXN-1);
    for(int i=0;i<MAXN;i++){
        cout<<vec[i]<<endl;
    }
    

    return 0;
}
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void Rand_Arr(int num){
	int tmp=0;
	while (tmp<num){
    // khởi tạo bộ sinh số ngẫu nhiên
    mt19937_64 rng(time(nullptr));
    // tạo số rand dom trong khoảng 
    uniform_int_distribution<int> uni_dist(1, 1000000); // giá trị ngẫu nhiên trong khoảng từ 1 đến 1000000

    // khởi tạo mảng ngẫu nhiên
    for(int i = 0; i < MAXN; ++i) {
        ARR[tmp][i] = uni_dist(rng);
    }
    tmp++;
	}
}
void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}