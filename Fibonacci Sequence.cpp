#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define INF 1000000
#define MOD 1000000007
using namespace std;
void multi(unsigned long long int arr1[][2], unsigned long long int arr2[][2], unsigned long long int arr3[][2])
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                arr3[i][j] += (arr1[i][k] * arr2[k][j]) % MOD;
                arr3[i][j] %= MOD;
            }
        }
    }
}

int main()
{
    unsigned long long int n;
    unsigned long long int rzlt[2][2];
    unsigned long long int v[65][2][2];
    cin >> n;
    if(n==0){
        cout<<1;
        return 0;
    }
    n--;
    ms(v, 0);
    ms(rzlt, 0);

    v[0][0][1] = 1, v[0][1][0] = 1, v[0][0][0] = 1;
    for (int i = 1; i <= 64; i++) {
        multi(v[i - 1], v[i - 1], v[i]);
    }
    rzlt[0][0] = 1, rzlt[1][1] = 1;
    int i = 0;
    unsigned long long int temp[2][2];
    while (n) {
        if ((n & 1) == 1) {

            ms(temp, 0);
            multi(v[i], rzlt, temp);
            for (int k = 0; k < 2; k++)
                for (int j = 0; j < 2; j++)
                    rzlt[k][j] = temp[k][j];
        }
        i++;
        n = n >> 1;
    }
    unsigned long long int u=(rzlt[1][0]+rzlt[1][1])%MOD;
    cout<<u%MOD;
    return 0;
}
