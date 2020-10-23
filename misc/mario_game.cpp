#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

int main(){
    int n = 7;
    int m = 4;
    int d = 4;
    vector<int> A = {3, 4, 6, 7};

    unordered_set<int> us;

    vector<int>::iterator itr;
    for(itr = A.begin(); itr!=A.end(); itr++)
        us.insert(*itr);
    
    int finalPos = n+1;

    int flag=1;
    int currentPos = 0;
    int jumps=0;

    while(flag==1){
        for(int i=currentPos + d; i>currentPos; i--){
            // find if ith position is present in arrray A
            // vector<int>::iterator it = lower_bound(A.begin(), A.end(), i);
            // if(it != A.end() && *it == i){
            if(us.find(i) != us.end()){
                currentPos = i;
                jumps++;
                flag = 1;
                if(currentPos + d >= finalPos){
                    cout << jumps+1 << endl;
                    return 0;
                }
                else if(currentPos>=finalPos){
                    cout << jumps << endl;
                    return 0;
                }
                break;
            }
            else
                flag = 0;
        }

        if(flag==0){
            cout << "-1" << endl;
            return 0;
        }
    }

    

    return 0;
}