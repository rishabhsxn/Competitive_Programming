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


#include<iostream>
#include<unordered_set>

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

};


int main(){
    string s;

    cout << "Enter String: ";
    getline(cin, s);

    cout << "Max substring length: " << Solution().lengthOfLongestSubstring2(s) << endl;

    return 0;
}