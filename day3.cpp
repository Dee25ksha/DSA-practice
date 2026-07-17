#include<bits/stdc++.h>
using namespace std;


//leetcode 1523(count odd numbers in an interval range)
int countOdds(int low, int high) {

        int n=(high-low)+1;
        //if n comes out to be even 
        if(n%2==0) return n/2;
        //if n comes out to be odd 
        else {
            if(low%2!=0 || high%2!=0) return (n/2)+1;
            else return n/2;
        }
        
    }


//leetcode 414

int thirdMax(vector<int>& nums) {
        long max1 = LONG_MIN;
        long max2 = LONG_MIN;
        long max3 = LONG_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max1 || nums[i] == max2 || nums[i] == max3) continue;//edge case for big negative values present in the array beacsue there is no chnace that they are comin  in max1, max2 or max3
            if (nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if (nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            }
            else if (nums[i] > max3) {
                max3 = nums[i];
            }
        }
        //following this case ->"If the third maximum does not exist, return the maximum number."
        return max3 == LONG_MIN ? max1 : max3;
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

//leetcode 448(find all numbers disappeared in an array)
vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n=nums.size();
        int i=0;
        vector<int> ans;
        while(i<n){
            int correctindex=nums[i]-1;
            if(nums[i]!=nums[correctindex]){
                swap(nums[i], nums[correctindex]);
            }
            else i++;
        }
      
    
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                ans.push_back(i+1);
            }
        }return ans;
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

//leetcde 75 (sort colors)
void sortColors(vector<int>& nums) {
        int n=nums.size();
        int mid=0;//here mid will be acting as current beacuse the curr(mid) is placed at the right position by swapping it with low or high
        int high=n-1;
        int low=0;

        while(mid<=high){
            //when nums[i] is 0 we will take it the first thta is by swapping mid with low 
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            //when nums[i] is 1
            else if(nums[mid]==1){
                //we dont need swap here beacuse the swapping done in above and below would automaticaaly place the 1 at right position thta is why we only neeed to do is mid++;
                mid++;
            }
            //when nums[i] is 2 we will take it to the last thta tis swappin mid with high 
            else{
                swap(nums[high],nums[mid]);
                high--;
            }
        }
        return;
        
    }


//kadane's algorithm
void kadane(vector<int> &nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        int currSum;
        currSum+=nums[i];
        int maxSum=max(currSum, maxSum);
        if(currSum<0) currSum=0; //reset, this is the kadane lagorithm

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

//leetcode 905 (sort array by parity)
vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even;
        vector<int> odd; 
        vector<int> r;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) even.push_back(nums[i]);
            else continue;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0) odd.push_back(nums[i]);
            else continue;
           
        }
        for(int i=0;i<even.size();i++){
            r.push_back(even[i]);
        }
        for(int j=0;j<odd.size();j++){
            r.push_back(odd[j]);
        }

        return r;
        
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

//leetcode 189(rotate array)
void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        //modolo to reduce the value of index(i) if it greater than k, 
        //if a element is at  ith post then after rotaion it will be at i+k th position , 
        //make sure that if k=7 and n=3 , if we do n-k it will lead to engative value that's why modulo is done to reduce it and start it form 1 because 
        k=k%n;
        if(n==0)return;
        reverse(nums.begin(),nums.begin()+(n-k));
        reverse(nums.begin()+(n-k),nums.end());
        reverse(nums.begin(),nums.end());
        
}

//leetcode 283(moving zeros to the end)
void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }
        while (i < n) {
            nums[i] = 0;
            i++;
        }
    }

//leetcode 217
bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto &p:mp){
            if(p.second>1) return true;
        }
        return false;
        
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
    // --- countOdds (1523) ---
    cout << "Count Odds: " << countOdds(3, 7) << endl;
    // --- thirdMax (414) ---
    vector<int> v1 = {3, 2, 1};
    cout << "Third Max: " << thirdMax(v1) << endl;

    // --- majority (169) ---
    vector<int> v2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majority(v2) << endl;

    //--leetcode 448 (find all numbers disappeared in an array)---
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> disappeared = findDisappearedNumbers(nums);     
    cout << "Disappeared Numbers: ";
    for(int x : disappeared) cout << x << " ";
    cout << endl;


    // --- DNF (Dutch National Flag) ---
    vector<int> v3 = {2, 0, 2, 1, 1, 0};
    DNF(v3);
    cout << "DNF sorted: ";
    for(int x : v3) cout << x << " ";
    cout << endl;

    // --- sortColors (75) ---
    vector<int> v6 = {2, 0, 2, 1, 1, 0};    
    sortColors(v6);
    cout << "Sort Colors: ";
    for(int x : v6) cout << x << " ";
    cout << endl;

    // --- kadane's algorithm ---
    vector<int> v4 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Kadane: ";
    kadane(v4);   // this one already prints inside the function

    // --- kadane2 (with subarray) ---
    vector<int> v7 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Kadane2: ";
    kadane2(v7);   // this one already prints inside the function   

    // --- sortArrayByParity (905) ---
    vector<int> v8 = {3, 1, 2, 4};
    sortArrayByParity(v8);
    cout << "Sort Array by Parity: ";
    for(int x : v8) cout << x << " ";
    cout << endl;

    // --- minimumAbsDifference (1200) ---
    vector<int> v5 = {4, 2, 1, 3};
    vector<vector<int>> result = minimumAbsDifference(v5);
    cout << "Min Abs Diff Pairs: ";
    for(auto &pair : result){
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    // --- rotate (189) ---
    vector<int> v9 = {1, 2, 3, 4, 5, 6, 7};
    rotate(v9, 3);

    // --- moveZeroes (283) ---
    vector<int> v10 = {0, 1, 0, 3, 12};
    moveZeroes(v10);

    // --- containsDuplicate (217) ---
    vector<int> v11 = {1, 2, 3, 1};
    cout << "Contains Duplicate: " << (containsDuplicate(v11) ? "true" : "false") << endl;

    return 0;
}