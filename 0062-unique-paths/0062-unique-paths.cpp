#define ll long long
class Solution {
public:
    const ll mod = 2000000033;
    
    int modInv(ll x, ll y){
        x = x % mod;
        if ( y == 0) return 1; 
        
        ll res = 1;
        if ( y & 1){
            res = x; 
        }
        ll temp = modInv(x, y/2);
        ll temp2 = (temp * temp ) % mod; 
        res = ( res * temp2) % mod; 
        return res; 
    }

    int uniquePaths(int m, int n) {
        
        vector<ll> fact(205); 
        fact[0] = fact[1] = 1;
        for(ll i = 2; i<=201; ++i){
            fact[i] = ( i * fact[i-1] ) % mod; 
        }

        ll a = fact[m + n - 2]; 
        ll b = fact[n-1]; 
        ll c = fact[m-1]; 
        ll d = (b * c) % mod; 

        return (a * modInv(d, mod-2)) % mod;
    }
};