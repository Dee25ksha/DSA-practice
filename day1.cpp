#include<bits/stdc++.h>
using namespace std;

//gcd
int gcd(int a,int b){
    if(a==0 || b==0){
        return max(a,b);
    }
    int r=min(a,b);
    while(r>0){
        if(a%r==0 && b%r==0){
            break;
        }
        r--;
    }
    return r;

}
//lcm
int lcm(int a, int b){
    int g=max(a,b);
    int s=min(a,b);
    for(int i=g;i<=a*b;i+=g){
        if(i%s==0) return i;
    }
    // return (a/gcd(a,b))*b;
}

//Sieve of Eratosthenes
int prime(int n){
    int count=0;
    vector<int> nums(n+1,1);

    for(int i=2;i*i<n;i++){
        if(nums[i]==1){
            for(int j=i*i;j<n;j+=i){
                nums[j]=0;
            }

        }
    }
    for(int i=2;i<=n;i++){
        if(nums[i]==1) count++;

    }
    return count;

} 


int main() {
    int a=20;
    int b=28;

    cout<<gcd(20,28)<<endl;
    cout<<lcm(5,11)<<endl;
    cout<<prime(26);

    return 0;
}