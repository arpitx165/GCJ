/*
Problem link : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    int t,b;
    cin >> t >> b;
    while(t--){
        string ans(b,'0');
        int m=0,m1=0;
        int q=0;
        for(int i=1;i<=b/2;i++){
            cout << i << endl;
            cin >> ans[i-1];
            cout << b-i+1 << endl;
            cin >> ans[b-i];
            if(ans[i-1] == ans[b-i]){
                m=i-1;
            } else {
                m1=i-1;
            }
            q+=2;
            if(q%10==0){
                string tmp[4]={ans,ans,ans,ans};
                reverse(tmp[1].begin(),tmp[1].end());
                reverse(tmp[2].begin(),tmp[2].end());
                for(int i=0;i<b;i++){
                    tmp[0][i]^=1;
                    tmp[2][i]^=1;
                }
                char x,y;
                cout << m+1 << endl;
                 cin >> x;
                 cout << m1+1 << endl;
                 cin >> y;
                for(int i=0;i<4;i++){
                    if(tmp[i][m] == x && tmp[i][m1] == y){
                        ans=tmp[i];
                         break;
                    }
                }
                q+=2;
            }
        }
        //cerr << ans << "  " << q << endl;
        cout <<  ans << endl;
        char st;
        cin >> st;
        if(st=='Y')
            continue;
        else
            return 0;
    }
    return 0;
}