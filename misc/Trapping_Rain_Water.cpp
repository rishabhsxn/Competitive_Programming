/* Question: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute 
how much water it is able to trap after raining.
Input: 3
       2 0 2
Output: 2

solution: https://www.geeksforgeeks.org/trapping-rain-water/

METHOD #1: A block (element in array) can hold water if there is a left wall AND a right wall at any distance from them.
So, for every element, iterate left and right and find highest walls. If any of these walls are not taller than the block itself, 
then it can't hold water. If both are taller, then the block will hold water drops equal to minimum of height differences of left 
and right wall w.r.t. to the block.
Time complexity: O(n^2)
Space complexity: O(1)

METHOD #2: (a) Instead of finding left and right wall while iterating the blocks, find the lmax and rmax before iterating and save them
in two different arrays.
(b) It can be further improved by using lmax and rmax variables instead of array

*/

#include<iostream>

using namespace std;

int calculateTotalWater(int size, int blocks[]);
int calculateTotalWater2a(int size, int blocks[]);

int main(){
    int size;

    cout << "Enter no. of inputs: ";
    cin >> size;

    int blocks[size];

    cout << "Enter " << size << " numbers: " << endl;
    for(int i=0; i<size; i++)
        cin >> blocks[i];

    int waterDrops = calculateTotalWater2a(size, blocks);
    cout << "\nTotal water drops: " << waterDrops << endl << endl;


    return 0;
}


int calculateTotalWater(int size, int blocks[]){
    int water = 0;
    int maxLeftHeight=0, maxRightHeight=0;
    for(int i=1; i<size; i++){
        maxLeftHeight = maxRightHeight = blocks[i];

        // find height of highest left wall
        for(int j=i; j>=0; j--)
            maxLeftHeight = max(maxLeftHeight, blocks[j]);
        
        // if there is no left wall taller than the block, then it can't hold water drops
        if(maxLeftHeight != blocks[i]){

            // find height of highest right wall
            for(int k=i; k<size; k++)
                maxRightHeight = max(maxRightHeight, blocks[k]);

            // if there is no right wall taller than the block, then it can't hold water drops
            if(maxRightHeight != blocks[i]){
                water += min(maxLeftHeight-blocks[i], maxRightHeight-blocks[i]);
            }
        }
    }

    return water;
}

int calculateTotalWater2a(int size, int blocks[]){
    int leftMax[size], rightMax[size], water=0;

    leftMax[0] = blocks[0];
    rightMax[size-1] = blocks[size-1];

    // find highest left wall for every block
    for(int i=1; i<size; i++)
        leftMax[i] = max(leftMax[i-1], blocks[i]);

    // find highest right wall for every block
    for(int j=size-2; j>=0; j--)
        rightMax[j] = max(rightMax[j+1], blocks[j]);

    // find water stored using above left and right wall data
    for(int k=0; k<size; k++){
        if(leftMax[k]>blocks[k] && rightMax[k]>blocks[k])
            water += min(leftMax[k], rightMax[k]) - blocks[k];
    }

    return water;
}