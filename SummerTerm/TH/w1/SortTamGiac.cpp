#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Triangle {
    int a, b, c;
};

struct ValidTriangle {
    Triangle t;
    long long area2;
};

bool isValid(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

long long areaSquared(int a, int b, int c) {
    long long la = a, lb = b, lc = c;
    long long s = la + lb + lc;
    long long p = s / 2;
    return p * (p - la) * (p - lb) * (p - lc);
}

int main() {
    int n;
    cin >> n;
    vector<Triangle> triangles(n);
    vector<ValidTriangle> validTriangles;

    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        triangles[i] = {a, b, c};

        if (isValid(a, b, c)) {
            long long area2 = areaSquared(a, b, c);
            if (area2 > 0) {
                validTriangles.push_back({{a, b, c}, area2});
            }
        }
    }

    sort(validTriangles.begin(), validTriangles.end(), [](ValidTriangle& x, ValidTriangle& y) {
        return x.area2 > y.area2;
    });

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (isValid(triangles[i].a, triangles[i].b, triangles[i].c)) {
            long long area2 = areaSquared(triangles[i].a, triangles[i].b, triangles[i].c);
            if (area2 > 0)
                triangles[i] = validTriangles[k++].t;
        }
    }

    for (const auto& t : triangles) {
        cout << t.a << " " << t.b << " " << t.c << '\n';
    }

    return 0;
}



// Tham khao tu 
// https://m365.cloud.microsoft/chat/entity1-d870f6cd-4aa5-4d42-9626-ab690c041429/eyJpZCI6IlZYTmxjbFl4ZkdoMGRIQnpPaTh2YzNWaWMzUnlZWFJsTFdsdWRDNXZabVpwWTJVdVkyOXRMM3hQU1VRNk9XWXpOamxrTXpRdE5HVTJNeTAwTVRVMkxXSXpNR1V0TWpKaU5UZGpZV1ZsWldKbWZEZzNaVGRsWVRVMUxUYzVZak10TkRJNU5TMWhZelV5TFdSa1lXTTNZVEEzTjJKaU4zd3lNREkxTFRBM0xURTJWREF5T2pVNU9qUTJMakkxTlRRMU1EVmEiLCJzY2VuYXJpbyI6InNoYXJlTGlua1ZpYVBvcG92ZXIiLCJwcm9wZXJ0aWVzIjp7InByb21wdFNvdXJjZSI6InVzZXIiLCJjbGlja1RpbWVzdGFtcCI6IjIwMjUtMDctMTZUMDI6NTk6NDYuMjI3WiJ9LCJjaGF0VHlwZSI6IndlYiIsInZlcnNpb24iOjEuMX0
// https://chatgpt.com/c/68771457-6c7c-8001-8e3c-4b5600f6634b