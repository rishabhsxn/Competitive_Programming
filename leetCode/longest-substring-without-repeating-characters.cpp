/* PROBLEM: Given a string s, find the length of the longest substring without repeating characters. */

/* METHOD #1: Brute Force - For every element, iterate the string ahead till a character repeats, compare and update
the maximum length encountered till now. For checking repetition of characters use an unordered_set. 
After checking for each element, empty the set.
Time complexity = O(n^2)
Space complexity = O(n)  
Runtime: 1304 ms    Memory: 148.1 MB */

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

};


int main(){
    string s;

    cout << "Enter String: ";
    getline(cin, s);

    cout << "Max substring length: " << Solution().lengthOfLongestSubstring1(s) << endl;

    return 0;
}