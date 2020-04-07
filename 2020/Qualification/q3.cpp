#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
 using namespace std;

 int main(){
    int t;
    cin >> t;
    for(int t1=1;t1<=t;t1++){
        int n,st,end;
        string ans="";
        cin >> n;
        vector < pair < int, pair <int, int> > > a;
        for(int i=0;i<n;i++){
            cin >> st >> end;
            a.push_back(make_pair(st,make_pair(end, i)));
            ans+='0';
        }
        sort(a.begin(), a.end());
        int flag=0;
        vector <int> c(2,0);
        for(int i=0;i<n;i++){
            int ind = a[i].second.second;
            if(c[0] <= a[i].first){
                c[0] = a[i].second.first;
                ans[ind]='C';
            } else if(c[1] <= a[i].first) {
                c[1] = a[i].second.first;
                ans[ind]='J';
            } else{
                flag=1;
                break;
            }
        }
        cout << "Case #" << t1 << ": ";
        if(flag==1){
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
 }