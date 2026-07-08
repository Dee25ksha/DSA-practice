#include<bits/stdc++.h>
using namespace std;
//leetcode 414
int thirdMax(vector<int>& nums) {
        int max1=INT_MIN;
        int max2=INT_MIN;
        int max3=INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==max1||nums[i]==max2||nums[i]==max3) continue;
            if(max1==INT_MIN || nums[i]>max1) {
                max3=max2;
                max2=max1;
                max1=nums[i];
            }
            else if(max2==INT_MIN || nums[i]>max2) {
                max3=max2;
                max2=nums[i];
            }
            else if(max3==INT_MIN||nums[i]>max3) {
                max3=nums[i];
            }
        }
        return max3==INT_MIN ? max1:max3;

        
        
    }

//leetcode 169 (Boyer-Moore Majority Voting Algorithm)
int majority(vector<int>& nums){
    int candidate=-1;
    int count=0;
    for(int n:nums){
        if(count==0) {
            candidate=n;
            count=1;
        }
        else if(n==candidate) count++;
        else count--;
    }
    return count;
}

//dutch national flag algorithm 
void DNF(vector<int> &nums){
    int n=nums.size();
    int mid=0;
    int high=n-1;
    int low=0;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            mid++;
            low++;
        }
        else if(nums[mid]==1) mid++;
        else {
            swap(nums[high],nums[mid]);
            high--;
        }
    }
}

//kadane's algorithm
void kadane(vector<int> &nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        int currSum;
        currSum+=nums[i];
        int maxSum=max(currSum, maxSum);
        if(currSum<0) currSum=0; //reset

    }
}

void kadane2(vector<int> &nums){
    int n=nums.size();
    int maxSum=INT_MIN;
    int currSum=0;
    int start=0, ansStart=0, ansEnd=0;
    for(int i=0;i<n;i++){
        if(currSum==0){
            start=i;
        }
        currSum+=nums[i];
        if(currSum>maxSum){
            maxSum=currSum;
            ansStart=start;
            ansEnd=i;
        }
        if(currSum<0) currSum=0;

    }
     cout << "Subarray = [ ";
    for(int i = ansStart; i <= ansEnd; i++){
        cout << nums[i] << " ";
    }
     cout << "]" << endl;
}

//1200
vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
       sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        for(int i = 1; i < arr.size(); i++){
            minDiff = min(minDiff, arr[i] - arr[i-1]);
        }

        vector<vector<int>> result;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i-1] == minDiff){ //condition ->
            //b - a equals to the minimum absolute difference of any two elements in arr
                result.push_back({arr[i-1], arr[i]});
            }
        }

        return result;
    }


//344
void reverseString(vector<char> &s){
    int n=s.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        swap(s[low],s[high]);
        low++;
        high--;
    }
    return ;

}


int main(){
    // --- thirdMax (414) ---
    vector<int> v1 = {3, 2, 1};
    cout << "Third Max: " << thirdMax(v1) << endl;

    // --- majority (169) ---
    vector<int> v2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majority(v2) << endl;

    // --- DNF (Dutch National Flag) ---
    vector<int> v3 = {2, 0, 2, 1, 1, 0};
    DNF(v3);
    cout << "DNF sorted: ";
    for(int x : v3) cout << x << " ";
    cout << endl;

    // --- kadane's algorithm ---
    vector<int> v4 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Kadane: ";
    kadane(v4);   // this one already prints inside the function

    // --- minimumAbsDifference (1200) ---
    vector<int> v5 = {4, 2, 1, 3};
    vector<vector<int>> result = minimumAbsDifference(v5);
    cout << "Min Abs Diff Pairs: ";
    for(auto &pair : result){
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    
    return 0;
}