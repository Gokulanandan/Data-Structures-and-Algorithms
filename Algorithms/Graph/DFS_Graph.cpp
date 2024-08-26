#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#define MAX_NODE 8

void dfs_hash(int k, vector<int> arr[], unordered_set<int> &seen) {
    auto it = seen.find(k);
    if(it == seen.end()) {
        seen.insert(k);
        for(int i=0; i<arr[k].size();i++){
            it = seen.find(arr[k][i]);
            if(it == seen.end()) {
                dfs_hash(arr[k][i], arr, seen);
            }
        }
    }
}

void dfs_vector(int k, vector<int> arr[], vector<int> &seen) {
    if(!seen[k]) {
        seen[k] = 1;
        cout << k << "->";
        for(int i=0; i<arr[k].size();i++){
            if(!seen[arr[k][i]]) {
                dfs_vector(arr[k][i], arr, seen);
            }
        }
    }
}

int main(){
    vector<int> node[MAX_NODE];
    vector<int> seen(MAX_NODE, 0);
    //unordered_set<int> seen;

    cout<<"Enter the Graph Details below " <<endl;
    cout<<"Enter Two Node details with a Space in between \
            eg., 1 2 , where 1 is connected to 2.         \
            This is a Directed Graph" << endl;
    int n = MAX_NODE;
    while(n) {
        int p, q;
        cin >>p>>q;
        node[p].push_back(q);
        n--;
    }

    //dfs_hash(0, node, seen);
    dfs_vector(0, node, seen);
    cout << "null" << endl;

    for(int i=0; i<=7;i++){
        cout << "["<<i<< "] : " << seen[i]<<endl;
    }

    /*for(auto &it : seen){
        cout << it << " ";
    }*/
    return 0;
}