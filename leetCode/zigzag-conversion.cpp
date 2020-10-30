/* PROBLEM: The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows.
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR" */

/* METHOD #1 - Use a 2D vector - Traverse the string and for every character, determine in which row it will be inserted,
insert that char in the same row number in 2D vector. To get the final string, iterate the 2D vector in row-wise manner
and append each char in the final string 
Time Complexity = O(n^2)    because of traversal of 2D vector
Space Complexity = O(n)     2D vector to store n elements
Runtime: 36 ms      Memory: 14.4 MB  */


#include<iostream>
#include<vector>

// using namespace std;

class Solution{
public:
    std::string convert(std::string s, int numRows){

        /* if number of rows is 1, then the string remains same */
        if(numRows==1)
            return s;

        /* 2D vector for storing character sequence */
        std::vector<std::vector<char>> m(numRows);
        std::string res;

        int row=0;
        /* to determine, if we are filling vertically or diagonally */
        bool fillVertical = true;

        for(int i=0; i<s.length(); i++){
            if(fillVertical){
                if(row<numRows){
                    m[row].push_back(s[i]);
                    row++;
                }
                else{
                    fillVertical = false;
                    i--;
                    row--;
                }
            }
            else{
                // fill diagonally
                row--;
                if(row==0){
                    fillVertical = true;
                    i--;
                }
                else
                    m[row].push_back(s[i]);
            }
        }

        for(int i=0; i<m.size(); i++)
            for(int j=0; j<m[i].size(); j++)
                res.push_back(m[i][j]);

        return res;
    }

};


int main(){
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);

    int rows;
    std::cout << "Rows: ";
    std::cin >> rows;

    std::cout << Solution().convert(s, rows) << std::endl;

    return 0;
}