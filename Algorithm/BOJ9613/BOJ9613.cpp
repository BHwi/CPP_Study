#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll GCD(ll A, ll B) {
    while(B != 0) {
        ll r = A % B;
        A = B;
        B = r;
    }

    return A;
}

int main() {
    int t, n, data;
    ll sum;

    cin >> t;

    for(int T = 0; T < t; T++) {
        cin >> n;
        sum = 0;

        vector<ll> arr;

        for(int i = 0; i < n; i++) {
            cin >> data;
            arr.push_back(data);
        }

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                sum += GCD(arr[i], arr[j]);
            }
        }

        cout << sum << endl;
    }    
}