#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include <utility>
#define int int64_t
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define vin(x,v) for(auto &x:v)cin>>x;
#define vout(x,v)for(auto x:v)cout<<x<<" ";
#define MEM(a, b) memset(a, (b), sizeof(a))
#define loop(i, j, k) for (int i=j ; i<k ; i+=1)
#define rloop(i, j, k) for (int i=j ; i>=k ; i-=1)
#define rep(i, j) loop(i, 0, j)
#define rrep(i, j) rloop(i, j, 0)
#define MP make_pair
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;



void solve(){
    int n;cin>>n;
    int arr[n+2][n+2];
    MEM(arr,0);
    loop(i,1,n+1){
        loop(j,1,n+1){
            char c;cin>>c;
            // cout<<c;
            if(c=='o'){
                arr[i-1][j]=1;

                arr[i+1][j]=1;

                arr[i][j+1]=1;

                arr[i][j-1]=1;
                arr[i][j]=0;
            }
        }
    }
    int count=0;
    loop(i,1,n+1){
        loop(j,1,n+1){
            if(arr[i][j]==1){count++;}
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    if(count%2==0)cout<<"YES";
    else cout<<"NO";
}


signed main(){
ios_base::sync_with_stdio(false);cin.tie(NULL); 
 //#ifndef ONLINE_JUDGE
        //FOR GETTING INPUT FROM input.txt
        //freopen("input.txt", "r", stdin);
        //FOR GETTING INPUT FROM input.txt	
        //freopen("output.txt", "w", stdout);
//	#endif
  int t=1;
  //cin>>t;
  while(t--){
     solve();
  cout<<endl;
  }
}