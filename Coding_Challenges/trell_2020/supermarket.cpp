/* Not complete - Wrong Input */

#include<vector>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Solution{
public:
    int minValueof(int a, int b){
        return (a < b) ? a : b;
    }
    
    vector<int> supermarket(vector<vector<int>> howMuchToBuy,vector<int> priceKg){
        //write the solution here.
        vector<int> result;
        for(int i=0; i<howMuchToBuy.size(); i++){
            int friends = howMuchToBuy[i][0];
            int kilogramsToBuy = howMuchToBuy[i][1];
            
            vector<vector<int>> Table(friends+1, vector<int>(kilogramsToBuy + 1, 0));
            for(int j=1; j<=friends; j++){
                for(int k=0; k<=j; k++){
                    Table[j][k] = INT32_MAX;
                    if(k==0){
                        Table[j][0] = 0;
                    }
                    else if(priceKg[k] > 0){
                        Table[j][k] = minValueof(Table[j][k], Table[j-1][j-k] + priceKg[k]);
                    }
                }
            }
            
            result.push_back(Table[friends][kilogramsToBuy] == 0 ? -1 : Table[friends][kilogramsToBuy]);
        }

        return result;
    }
};

int main(){
    int C, K,N,val;
    string line;
    vector<vector<int>> howMuchToBuy;
    vector<int> priceKg;

    cin >> C;

    for(int i = 0; i < C; i++){
        cin>>N>>K;

        howMuchToBuy.push_back({N,K});
        cin.ignore();
        getline(cin, line);
        istringstream stream(line);

        while(stream>>val){
            priceKg.push_back(val);
        }
    }
        
    vector<int> ans = Solution().supermarket(howMuchToBuy,priceKg);
    for(int i:ans){
        cout<<i<<endl;
    }

}