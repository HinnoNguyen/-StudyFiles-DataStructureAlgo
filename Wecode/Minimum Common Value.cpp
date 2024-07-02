/*
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

Input:

First line contains n, m are number of elements in nums1 and nums2 respectively
Second line are n elements of nums1
Third line are m elements of nums2

Output:

Example
INPUT	OUTPUT	EXPLAIN
3 2
1 2 3
2 4	2	The smallest element common to both arrays is 2
4 4
1 2 3 6
2 3 4 5	2	The smallest element common to both arrays is 2

*/


#include <iostream>
#include <vector>
using namespace std;

int smallestCommon(vector<int> nums1, vector<int> nums2) {
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            return nums1[i];
        } 
        else if (nums1[i] < nums2[j]) {
            i++;
        } 
        else {
            j++;
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums1;
    vector<int> nums2;

    int val = 0;
    for (auto i = 0; i < n; i++) {
        cin >> val;
        nums1.push_back(val);
    }
    for (auto i = 0; i < m; i++) {
        cin >> val;
        nums2.push_back(val);
    }

    cout << smallestCommon(nums1, nums2) << endl;

    return 0;
}
