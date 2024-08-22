#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> populateZ(string haystack, string needle, string &str){
    int left = 0 , right = 0;
    int i;
    int n = str.length();
    vector <int> vect(haystack.length() + needle.length() +1, 0);
    for(int i=1; i<n ;i++){

        if(i > right){
            right = left = i;
            while(right < n && str[right-left] == str[right]) right++;
            vect[i] = right - left;
            right--;
        } else {
            int k1 = i-left;
            if(vect[k1] < right - i + 1) {
                vect[i] = vect[k1];
            } else {
                left = i;
                while(right < n && str[right-left] == str[right]) right++;
                vect[i] = right - left;
                right--;
            }
        }
    }
    return vect;
}

void createZArray(string haystack ,string needle){

    string combined = needle + "$" + haystack; 
    vector<int> vect = populateZ(haystack, needle, combined);
    for(int i=0 ;i<vect.size(); i++){
        if(vect[i] == needle.length()) {
            cout << "Pattern Found at : " << i - needle.length()-1 << endl;
        }
    }
}

int main(){
    string haystack = "mississippi";
    string needle = "issi";
    createZArray(haystack, needle);
    return 0;
}