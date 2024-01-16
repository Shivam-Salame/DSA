#include <bits/stdc++.h>
using namespace std;

vector<string> allPossibleStrings( string s ) {
    int size = s.length();
    vector<string> ans;
    for (int ind = 0; ind < (1 << size ); ind++) {
        string subsequence = "";
        for( int idx = 0 ; idx < size    ; idx++) {
            //check if ith bit is set or not
            if ( ind & ( 1 << idx ) ) {
                subsequence += s[idx];
            }
        }
        // adding subsequence to vector<string>
        if( subsequence.length() > 0 ){
            ans.push_back(subsequence);
        }
    }
    sort( ans.begin(), ans.end() );
    return ans;
}

int main()
{   
    string s  = "abc";    
    vector<string> ans = allPossibleStrings( s );
    for( auto it: ans ){
        cout << it << " "; 
    } 
    return 0;
}