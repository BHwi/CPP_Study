#include <iostream>

using namespace std;

long GCD(long A, long B) 
{
    while(B != 0) {
        long r = A % B;
        A = B;
        B = r;
    }

    return A;
}

int main() 
{
    int T;
    long A, B;

    cin >> T;

    for(int testcase = 0; testcase < T; testcase++) 
    {
        cin >> A;
        cin >> B;

        cout << A * B / GCD(A, B) << endl;
    }
}