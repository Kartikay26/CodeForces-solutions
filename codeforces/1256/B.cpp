// By R^ML^L
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
  ll q;
  cin >> q;
  while(q--)
  {
    ll n;
    cin >> n;
    ll arr[n];
    vector<bool> used(n,false);
    map<ll,ll> pos;
    for(ll i=0; i<n; i++)
    {
      cin >> arr[i];
      pos[arr[i]] = i;
    }
    for(ll i=1;i<=n; i++)
    {
      while( (pos[i] > i-1) && (!(used[pos[i]-1])))
      {
        // cerr << "debug "<<pos[i]<<" "<<i<<endl;
        ll index = pos[i]-1;
        if(arr[index] < arr[index+1])
        	break;
        swap(arr[index],arr[index+1]);
        used[index] = true;
        pos[arr[index+1]]++;
        pos[arr[index]]--;
      }
    }
    for(ll i=0; i<n; i++)
    {
      cout << arr[i] <<" ";
    }
    cout << endl;
 
  }
  return 0;
}