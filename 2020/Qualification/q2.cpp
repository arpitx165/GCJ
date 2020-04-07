/*
Problem link : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
*/
#include <iostream>
using namespace std;

int main(){

    int t;
    cin >> t;
    for(int t1=1;t1<=t;t1++) {
        string s;
        cin >> s;
        string ans="";
        int cur=0;
        for(int i=0;i<s.length();i++){
            int req = s[i]-'0';
            if(cur > req){
                while(cur > req){
                    ans+=')';
                    cur--;
                }
            } else if(cur < req){
                while(cur < req){
                    ans+='(';
                    cur++;
                }
            }
            ans+=s[i];
        }
        while(cur){
            ans+=')';
            cur--;
        }
        cout << "Case #" << t1 << ": " << ans << endl;
    }
    return 0;
}