/* Given a 32-bit signed integer, reverse digits of an integer.
Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer 
range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows. */

/* METHOD #1 - Use string's reverse() - Convert the integer to string, reverse it using reverse() function. Then, convert
it back to integer using stoi() function which will throw error if the integer is out of range, in that case return 0.
Also check if the passed integer is negative because reverse() will not handle that.
Time complexity = O(n)    because of reverse()
Space complexity = O(1)
Runtime: 0 ms       Memory: 6.9 MB */


#include<iostream>
#include<algorithm>

/* try avoiding using namespace for the global namespace */
// using namespace std;

class Solution{
public:
    int reverse1(int x){
        /* convert integer to string, so that we can use the built-in reverse function of string */
        std::string num = std::to_string(x);
        int flag=0;
        /* checking if the integer is negative */
        if(num[0]=='-')
            flag=1;
        std::reverse(num.begin(), num.end());

        /* If integer is out of range, than stoi (string to int) will throw error -> return 0 */
        try{
            if(flag==1)
                return -std::stoi(num);
            return std::stoi(num);
        }
        catch(std::out_of_range& oor){
            return 0;
        }
    }

};


int main(){
    int x;
    std::cout << "Enter a number: ";
    std::cin >> x;

    std::cout << Solution().reverse1(x) << std::endl;

    return 0;
}