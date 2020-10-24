/* PROBLEM: Given a string s, find the length of the longest substring without repeating characters. */

/* METHOD #1: Brute Force - For every element, iterate the string ahead till a character repeats, compare and update
the maximum length encountered till now. For checking repetition of characters use an unordered_set. 
After checking for each element, empty the set.
Time complexity = O(n^2)
Space complexity = O(n)  
Runtime: 1304 ms    Memory: 148.1 MB */

/* METHOD #2: Brute Force #2 - In this method, we will check all the substrings for the repetition. Use set for
checking repetition of characters. This is the least efficient method. 
Time Complexity = O(n^3)
Runtime: Time exceeded on Leetcode */

/* METHOD #3: Sliding Window - Use a Set to check repetition of characters. Traverse the elements, if not in set, include it
in set and increase the window size in forward direction. If an element is present in set, remove the oldest element of window 
from set and the window.
Worst case will be when all the characters are same: "bbbbb", each element will be visited once by i and j -> O(2n)
Time Complexity = O(n) 
Space Complexity= O(n) 
Runtime: 52 ms    Memory: 11 MB */

/* METHOD #4: Optimized Sliding Window - Instead of shrinking window from left one-by-one, directly move the left side of the 
window to the repeated character's index + 1 because till that all the substrings will have repetition of that character. 
To move to the repeated character's index directly, use a map (key=char, val=index)
Time Complexity = O(n) 
Space Complexity = O(n) 
Runtime: 20 ms    Memory: 8.6 MB */

#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;


class Solution{
public:    
    int lengthOfLongestSubstring1(string s){
        int maxLen=0;
        int len=0;
        unordered_set<char> c;

        /* outer loop for setting next element as new starting point.
        Reason for traversing till (s.length() - maxLen) is that after that element, a substring of length greater than maxLen
        will not be found */
        for(int i=0; i<s.length()-maxLen; i++){
            /* inner loop for checking max length of string till no repetition encountered */
            for(int j=i; j<s.length(); j++){
                /* if element is not found in set, increase len, add it to set and move ahead */
                if(c.find(s[j]) == c.end()){
                    c.insert(s[j]);
                    len++;
                    /* Compare and Update maxLen in every iteration to avoid failing in case of s.length() = 1 */
                    if(len>maxLen)
                        maxLen = len;
                }
                /* if element is found - a) empty the set   b) reset len    c) break inner loop */
                else{
                    len = 0;
                    c.clear();
                    break;
                }
            }
        }
        return maxLen;
    }

    /* Utility function for method #2 */
    bool isThereRepetition(int start, int end, string s){
        unordered_set<char> c;
        for(int i=start; i<end; i++){
            /* If char is found in set, return true */
            if(c.find(s[i]) != c.end())
                return true;
            else
                c.insert(s[i]);
        }
        return false;
    }

    int lengthOfLongestSubstring2(string s){
        int maxLen=0;
        for(int i=0; i<s.length(); i++)
            for(int j=i+1; j<=s.length(); j++)
                if(!isThereRepetition(i, j, s))
                    maxLen = max(maxLen, j-i);

        return maxLen;
    }

    int lengthOfLongestSubstring3(string s){
        int maxL = 0;
        int i=0, j=0;   // initially window is at 0
        int n = s.length();
        unordered_set<char> us;

        while(i<n && j<n){
            /* If not found, add to set, expand window ahead and update maxL */
            if(us.find(s[j]) == us.end()){
                us.insert(s[j++]);
                maxL = max(maxL, j-i);
            }
            /* if found, remove ith element from set, increase i */
            else
                us.erase(s[i++]);
        }

        return maxL;
    }

    int lengthOfLongestSubstring4(string s){
        unordered_map<char, int> m;
        int maxLen = 0;

        /* i = left boundary of window      j = right boundary of window */
        for(int i=0, j=0; j<s.length(); j++){
            if(m.find(s[j]) != m.end()){
                /* Because of this statement, we aren't required to delete the elements which were thrown out of window. This
                condition will run even when the character is not repeated in the window substring, but is present in map
                simply because it was once a part of the window. In this case, present value of i will be greater than
                old index of that character. So, i will remain same. 
                m[s[j]] + 1 because, new window will start after next index from repeated character's index */
                i = max(i, m[s[j]] + 1);
            }

            /* update maxL in every iteration and add the current index to map. Repeated character's old index will
            be overwritten by new index */
            maxLen = max(maxLen, j-i+1);
            m[s[j]] = j;
        }

        return maxLen;
    }

};


int main(){
    string s;

    cout << "Enter String: ";
    getline(cin, s);

    cout << "Max substring length: " << Solution().lengthOfLongestSubstring4(s) << endl;

    return 0;
}