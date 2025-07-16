#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<int> v1(n);
    for (long long i = 0; i < n; i++) cin >> v1[i];

    sort(v1.begin(), v1.end());

    long long m;
    cin >> m;
    vector<int> v2(m);
    for (long long i = 0; i < m; ++i) cin >> v2[i];
    

    for (long long i = 0; i < m; i++)
    {
        int x = v2[i];
        long long s = lower_bound(v1.begin(), v1.end(), x) - v1.begin();
        long long b = v1.end() - upper_bound(v1.begin(), v1.end(), x);
        cout << s << " " << b << endl;
    }

    return 0;
}

// Tham khao tu source (em copy ca bai do roi bo vao)