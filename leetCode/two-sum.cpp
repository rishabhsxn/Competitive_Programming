/* PROBLEM - Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order. */

/* METHOD #1 - BRUTE FORCE - Iterate the array and for every element, check the whole array for element together with which
the sum is equal to the target.
Time Complexity = O(n^2)
Space Complexity = O(1)  */

/* METHOD #2 - USING HASHMAP - (Two Iterations) - In first iteration, add the elements in the hashmap (value, index).
In second iteration, for every element, search it's counterpart (target - element) in the HashMap which takes O(1) generally.
Time Complexity = O(n)
Space Complexity = O(n)  */


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// for debugging purpose
void printMap(unordered_map<int, int> m){
    unordered_map<int, int>::iterator itr;
    for(itr=m.begin(); itr!=m.end(); itr++)
        cout << itr->first << " : " << itr->second << "  ";
    cout << endl;
}


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

        vector<int> twoSum2(vector<int>& nums, int target){
            unordered_map<int, int> m;

            // mapping elements(keys) with index(values)
            for(int i=0; i<nums.size(); i++){
              m[nums[i]] = i;
            }

            // find counterpart for every element in the hashmap
            for(int i=0; i<nums.size()-1; i++){
                // if counterpart found
                if( (m.find(target-nums[i]) != m.end()) && (m[target-nums[i]] != i) )
                    return {i, m[target-nums[i]]};
            }

            return {};
        }

};

int main(){
    vector<int> nums = {11, 7, 2, 16, 11};
    int target = 22;

    vector<int> sol = Solution().twoSum2(nums, target);
    
    vector<int>::iterator itr;
    for(itr=sol.begin(); itr!=sol.end(); itr++)
        cout << *itr << ' ';

    cout << endl;
    return 0;
}