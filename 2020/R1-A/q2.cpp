#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int t1=1;t1<=t;t1++){
        int n;
        cin >> n;
        cout << "Case #" << t1 << ": " << endl;
        if(n <= 500)
        {
            for(int i=0;i<n;i++)
                cout << i+1 << " " << 1 << endl;
        } else {
            int mem[30] ={0};
            int l_set = 0;
            n=n-30;
            /*30 + 2^x-1+2^x1-1+2^x3-1 = n-30*/
            for(int i=30;i>0;i--){
                if(n >= (1 << i)){
                    n -= (1 << i)-1;//because we have considered 30 already(n-30)
                    mem[i]=1;
                }
            }
            for(int i=0;i<30;i++){
                if(l_set){
                    if(mem[i]){
                        for(int j=i;j>=0;j--) {
                            cout << i+1 << " " << j+1 << endl;
                        }
                        l_set=0;
                    } else {
                        cout << i+1 << " " << i+1 << endl;
                    }
                } else {
                        if(mem[i]){
                            for(int j=0;j<=i;j++){
                                cout << i+1 << " " << j+1 << endl; 
                            }
                            l_set=1;
                        } else {
                            cout << i+1 << " " << 1 << endl;
                        }     
                    }
            }
            if(n){
                for(int i=31;i<31+n;i++){
                    if(l_set){
                        cout << i << " " << i <<endl;
                    } else {
                        cout << i << " " << 1 << endl;
                    }
                }
            }
        }
    }

    return 0;
}