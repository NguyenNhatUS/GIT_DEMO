#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;
        if (B.size() < A.size()) swap(A, B);
        int l = 0;
        int r = A.size();
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;
            int Aleft,Aright,Bleft,Bright;
            if(i > 0) Aleft = A[i - 1];
            else Aleft = INT_MIN;
            if(i < A.size()) Aright = A[i];
            else Aright = INT_MAX;
            if(j > 0) Bleft = B[i - 1];
            else Bleft = INT_MIN;
            if(j < B.size()) Bright = B[i];
            else Bright = INT_MAX;
            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 != 0) {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }
            else if (Aleft > Bright) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
        return -1;
    }
    };

int main() {

    return 0;
}