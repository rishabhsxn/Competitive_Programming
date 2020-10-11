/* PROBLEM - Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order. */

/* METHOD #1 - BRUTE FORCE - Iterate the array and for every element, check the whole array for element together with which
the sum is equal to the target.
Time Complexity = O(n^2)
Space Complexity = O(1)  */

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        vector<int> twoSum1(vector<int>& nums, int target){
            for(int i=0; i<nums.size()-1; i++){
                for(int j=i+1; j<nums.size(); j++){
                    if(nums[i]+nums[j] == target)
                        return {i, j};
                }
            }

            return {};
        }
};

int main(){
    vector<int> nums = {11, 7, 2, 15};
    int target = 9;

    vector<int> sol = Solution().twoSum1(nums, target);
    
    vector<int>::iterator itr;
    for(itr=sol.begin(); itr!=sol.end(); itr++)
        cout << *itr << ' ';

    cout << endl;
    return 0;
}