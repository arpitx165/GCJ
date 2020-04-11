#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n;
        cin >> n;
        vector <string> val(n, "");
        for(int j=0;j<n;j++){
            cin >> val[j];
        }
        /*for(int j=0;j<n;j++){
            cout << val[j] << " ";
        }
        cout << endl;*/
        string ans="", suffix="", prefix="", inbetween="";
        int flag=0;
        for(int j=0;j<n;j++){
            int k=0,k1=0;
            for(k=0;k<val[j].size();k++){
                if(val[j][k]=='*')
                    break;
                else if(k < prefix.size() && prefix[k]!=val[j][k]){
                    flag=1;
                    break;
                }
                else if(prefix.size()==k)
                    prefix+=val[j][k];
            }
            for(k1=val[j].size()-1;k1>=0 && flag==0;k1--){
                if(val[j][k1]=='*')
                    break;
                else if(val[j].size()-k1-1 < suffix.size() && suffix[val[j].size()-k1-1]!=val[j][k1]){
                    flag=1;
                    break;
                }
                else if(suffix.size()==val[j].size()-k1-1)
                    suffix+=val[j][k1];
            }
            for(int p1=k;p1<k1 && flag==0;p1++){
                if(val[j][p1]!='*')
                    inbetween+=val[j][p1];
            }
            if(flag){
                break;
            }
        }
        if(flag){
            cout << "Case #" << i << ": " << '*'  << endl;
        } else {
            reverse(suffix.begin(),suffix.end());
            ans = prefix+inbetween+suffix;
            cout << "Case #" << i << ": " << ans  << endl;
        }
    }
    return 0;
}