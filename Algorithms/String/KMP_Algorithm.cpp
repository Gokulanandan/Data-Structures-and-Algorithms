#include <iostream>
#include <vector>
using namespace std;

int main(){
    string str = "AAABAAADABBAC";
    string pattern = "AAADA";

    // KMP Algorithm revolves around creating a Longest Prefix Suffix Table
    // Creating the LPS table
    int prevLps = 0;
    int i = 1, j = 0;
    vector<int> lps(pattern.length(), 0);
    while(i < pattern.length()){
        if(pattern[prevLps] == pattern[i]) {
            lps[i] = prevLps +1;
            prevLps += 1;
            i += 1;
        } else if (prevLps == 0){
            lps[i] = 0;
            i += 1;
        } else {
            prevLps = lps[prevLps-1];
        }
    }

    // Now LPS table is Created, Search the main string using the LPS table
    i=0;
    while(i<str.length()){
        if(str[i] == pattern[j])  {
            i++;
            j++;
        } else if(j == 0){
            i++;
        } else {
            j = lps[j -1];
        }

        if(j == pattern.length()) {
        cout << "Found Pattern at Index : " << i-j << endl; 
        }
    }
    return 0;
}