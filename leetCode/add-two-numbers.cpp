/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse 
order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself. */

/* METHOD #1 - Iterate the lists and add the digits. Store in a new linked list and manage carry. 
Time complexity = O(m+n)
Space complexity = O(n) 
Runtime: 40 ms      Memory: 71.5 MB*/

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Utility function (ListNode is struct, that's why all it's data and members are accessible through objects */
void print(ListNode* l){
    while(l){
        if(l->next)
            cout << l->val << " -> ";
        else
            cout << l->val << endl;
        l = l->next;
    }
}
  
class Solution {
public:
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        int carry=0;
        int flag=0;

        ListNode *result = nullptr, *follower = nullptr, *temp = nullptr;

        while(l1 && l2){
            int sum = l1->val + l2->val + carry;

            if(sum>9){
                carry = sum/10;
                sum %= 10;
            }
            else
                carry = 0;

            temp = new ListNode(sum);

            if(flag==0){
                flag=1;
                result = follower = temp;
            }
            else{
                follower->next = temp;
                follower = temp;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        /* Now, we have 3 possible cases ->     
        a) l1 or l2 is still left & carry is zero  ---  Simply join remaining list to result list  
        b) l1 or l2 is still left & carry is non-zero  ---  Check for further carry propagation in remaining list and then join
        c) l1 and l2 are fully traversed & carry is non-zero  ---  add a node with carry value at last of result list */

        /* addRemainingList() function will handle case (a) & (b) */
        if(l1){
            addRemainingList(l1, carry);
            follower->next = l1;
        }
        else if(l2){
            addRemainingList(l2, carry);
            follower->next = l2;
        }
        /* case (c) */
        else if(carry!=0)
            follower->next = new ListNode(carry);
        

        return result;
    }

    void addRemainingList(ListNode* l, int carry){

        /* if carry is zero, not required to modify anything in the remaining list, just connect to result list.
        Else if carry is non-zero, check if it will further create chain of carries or not */
        if(carry != 0){

            /* if it will not create further carries, just add it to remaining list's first node */
            if(carry + l->val <= 9)
                l->val = l->val + carry;

            /* if it creates further carries, solve for entire list till carry becomes zero or list ends */
            else{
                ListNode* follower = nullptr;
                while(l && carry!=0){
                    int sum = l->val + carry;
                    if(sum>9){
                        carry = sum/10;
                        sum %= 10;
                    }
                    else
                        carry = 0;
                    
                    l->val = sum;

                    follower = l;
                    l = l->next;
                }

                /* Check if after all the digits(nodes), carry is still not 0.
                If yes, then need to add extra node at tail of list using follower pointer */
                if(carry!=0){
                    ListNode* last = new ListNode(carry);
                    follower->next = last;
                }

            }
        }
    }
};


int main(){

    // vector<int> a = {3, 4, 2};  // store reversed in LinkedList
    // vector<int> b = {4, 6, 5};

    // vector<int> a = {9,9,9,9,9,9,9};
    // vector<int> b = {9,9,9,9};

    vector<int> a = {5};
    vector<int> b = {7};

    ListNode *l1, *l2, *temp;
    
    temp = nullptr;
    for(int i=0 ; i<a.size() ; i++)
        temp = new ListNode(a[i], temp);
    l1 = temp;

    temp = nullptr;
    for(int i=0; i<b.size(); i++)
        temp = new ListNode(b[i], temp);
    l2 = temp;

    print(l1);
    print(l2);

    ListNode* result = Solution().addTwoNumbers1(l1, l2);

    cout << "Result: ";
    print(result);

    return 0;
}