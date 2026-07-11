#include<bits/stdc++.h>
using namespace std;

//recursive approach of solving fibonacci series
// int fibonacci(int n){
//     if(n==0 || n==1) return 1;
//     return fibonacci(n-1)+fibonacci(n-2);
// }
//dp approach of solving fibonacci series
int fibonacci(int n){
    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];

}
//leetcode 70 ->climbing stairs
//kiitne tareka ha jisse ham steps climb kar skte ha this is whta question is asking 
    int climbStairs(int n) {
        //fibonacci me n==0 ha to return 0 hoga otherwise stair climb karne ke liye 1 to count hoga that's why return 1 for both base case 
        //this is the brute force approach as recursion  is cusing TLE
        
        // if (n==0 || n==1) return 1;
        // return climbStairs(n-1)+climbStairs(n-2);
        //n-1  -> you took 1 step
        //n-2  -> you took 2 steps
        vector<int> dp(n+1);
        //it means you are at the top of the stairs and no steps needed, there is only 1 way to stay there
        //this acts a sbase so the recurrence works correctly for all other values of n
        dp[0]=1;// not physical scenario just a starting point
        //the second base case is when you are at the first step, there is only 1 way to reach the top from there, which is to take 1 step 
        dp[1]=1;
        for(int i=2; i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

        
        
    }
//LEETCODE->202(happy number)
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n != 1) {
            if(seen.count(n)){// here seen.count means that if the number 
                //is already present in the set then it means we are in a loop and will never reach 1, so return false
                return false;
            }
            seen.insert(n);
            int happy_no = 0;

            while(n > 0) {
                int digit = n % 10;
                happy_no += digit * digit;
                n /= 10;
            }

            n = happy_no;
        }

        return true;
    }

//LEETCODE->268(missing number)
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        //required sum
        int total=n*(n+1)/2;
        //actual sum
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return total-sum;

}
//leetoce 507(perfect number
bool checkPerfectNumber(int num) {
        if(num==1) return false;
        vector<int> r;
        int sum=1;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                int q=num/i;
                sum+=i;
                sum+=q;

            }


        }
        if(sum==num) return true;
         return false;
    }

//leetcode 118(pascal trianlge)

vector<vector<int>> generate1(int numRows) {
    if(numRows==0) return{};
    if(numRows==1) return{{1}}; //base for the below recursive function
    //here previous is creating the rows
    vector<vector<int>>previous=generate1(numRows-1); //recursive call will go till numrows=1(base case)
    vector<int>newRows(numRows,1);//intializing the new row at first with 1
    for(int i=1;i<numRows-1;i++){ //making the loop in such a way that the first and last element is 1
        newRows[i]=previous.back()[i-1]+previous.back()[i]; //then adding the perious rowws elemnts to get this rows element 
    }
    previous.push_back(newRows);//pushing it to the previous vector 
    return previous;

    
}
void printMatrix(vector<vector<int>>& mat){
    for(auto &row : mat){
        for(int x : row) cout << x << " ";
        cout << "\n";
    }
}


//LEETCODE 119(pascal triangle II)
vector<vector<int>> generate2(int numRows) {
    if(numRows==0) return{};
    if(numRows==1) return{{1}};

    vector<vector<int>> previous = generate2(numRows-1);
    vector<int> newRows(numRows,1);
    for(int i=1;i<numRows-1;i++){
        newRows[i] = previous.back()[i-1] + previous.back()[i];   // fixed
    }
    previous.push_back(newRows);
    return previous;
}

vector<int> getRow(int rowIndex) {
    vector<vector<int>> previous = generate2(rowIndex + 1); //above function works  as 0 indexing where the row question is demanding is 1 indexig soif it is asking for rowindex=3 then according to  0 based indexing rowindex would be 4
    return previous.back();
}
void printVector(vector<int>& v){
    for(int x : v) cout << x << " ";
    cout << "\n";
}


//leercode 50

double calcpow(double x , long long n){
    if(n==0) return 1.00;//any number to the power 0 is 1 

    double half=calcpow(x, n/2);

    if(n%2==0) return half*half;
    
    else return x*half*half;

}
double myPow(double x, int n) {
    long long N=n;
    if(N<0){
        x=1/x;
        N=-N;
    }
    return calcpow(x,N);
    
}












int main(){
   vector<int> arr={3,0,1};
    cout<<fibonacci(3);
    cout<<climbStairs(3);
    cout<<isHappy(19);
    cout<<missingNumber(arr);
    cout<<checkPerfectNumber(28);
    vector<vector<int>> triangle = generate1(5);
    printMatrix(triangle);

    vector<int> row = getRow(3);
    printVector(row);
    cout<<myPow(2.0, 10);

}