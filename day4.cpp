#include<bits/stdc++.h>
using namespace std;
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

//345
string reverseVowels(string s){
    int n=s.length();
    int low=0;
    int high=n-1;
    while(low<=high){
     bool lowIsVowel = (s[low]=='a'||s[low]=='e'||s[low]=='i'||s[low]=='o'||s[low]=='u'||
                            s[low]=='A'||s[low]=='E'||s[low]=='I'||s[low]=='O'||s[low]=='U');
        bool highIsVowel = (s[high]=='a'||s[high]=='e'||s[high]=='i'||s[high]=='o'||s[high]=='u'||
                             s[high]=='A'||s[high]=='E'||s[high]=='I'||s[high]=='O'||s[high]=='U');
    
        if(!lowIsVowel) low++;
        else if(!highIsVowel) high--;
        else {
            swap(s[low],s[high]);
            low++;
            high--;
        }
    }
    return s;

}

int main(){
    // --- reverseString (344) ---
    vector<char> v6 = {'h','e','l','l','o'};
    string s6="hello";
    reverseString(v6);
    cout << "Reversed String: ";
    for(char c : v6) cout << c;
    cout << endl;

    string result=reverseVowels(s6);
    cout<<"reversed vowel string ->"<< result;
    cout<<endl;




}
