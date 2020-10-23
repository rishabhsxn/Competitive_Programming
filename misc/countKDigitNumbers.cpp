#include<iostream>
#include<string>

using namespace std;

int countKDigitNumbers(int arr[], int n, int k){
    int count = 0;

    for(int i=0; i<n; i++){
        string str = to_string(arr[i]);
        int len = str.length();

        if(len==k)
            count++;
    }

    return count;
}

int main(){
    int arr[] = {1, 2, 22, 3, 34, 899, 112, 3, 44, 552};
    int n = 10;
    int k = 2;

    int count = countKDigitNumbers(arr, n, k);

    cout << count << endl;

    return 0;
}