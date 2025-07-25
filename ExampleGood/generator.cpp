#include "testlib.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
 
// This generator expects three command-line parameters:
//   argv[1] : n (the size of the array)
//   argv[2] : mode (one of: "rand", "incr", "decr", "equal", "two", "alternating", "zigzag")
//   argv[3] : M (the maximum value allowed, a positive integer)
 
int main(int argc, char* argv[]){
    // Register generator (seed taken from command-line if provided)
    registerGen(argc, argv, 1);
    if(argc < 4){
        cerr << "Usage: " << argv[0] << " n mode M\n";
        return 1;
    }
    int n = atoi(argv[1]);
    string mode = argv[2];
    long long M = atoll(argv[3]);
 
    // Output format: first line is T (# test cases). We output one test case per file.
    cout << 1 << "\n";
    cout << n << "\n";
    vector<long long> a(n);
 
    if(mode == "rand"){
        // Completely random numbers in [1, M].
        for (int i = 0; i < n; i++){
            a[i] = rnd.next(1LL, M);
        }
    }
    else if(mode == "incr"){
        // Nearly increasing sequence from 1 to M.
        if(n == 1) a[0] = 1;
        else {
            for (int i = 0; i < n; i++){
                // use integer interpolation; ensure last is M and first is 1.
                a[i] = 1 + (long long)( (M - 1) * i / (n - 1) );
            }
        }
    }
    else if(mode == "decr"){
        // Nearly decreasing from M down to 1.
        if(n == 1) a[0] = M;
        else {
            for (int i = 0; i < n; i++){
                a[i] = M - (long long)((M - 1) * i / (n - 1));
            }
        }
    }
    else if(mode == "equal"){
        // All entries equal. Choose one random number in [1, M] and fill.
        long long x = rnd.next(1LL, M);
        for (int i = 0; i < n; i++){
            a[i] = x;
        }
    }
    else if(mode == "two"){
        // Only two distinct values: 1 and 2.
        for (int i = 0; i < n; i++){
            a[i] = rnd.next(1, 2);
        }
    }
    else if(mode == "alternating"){
        // Alternate between M and 1.
        for (int i = 0; i < n; i++){
            a[i] = (i % 2 == 0 ? M : 1);
        }
    }
    else if(mode == "zigzag"){
        // Starting with a random number then force peaks and valleys.
        // For even indices, use a high value; for odd, use a low value.
        for (int i = 0; i < n; i++){
            if(i % 2 == 0)
                a[i] = M;
            else
                a[i] = 1;
        }
        // Optionally, introduce a little randomness.
        for (int i = 0; i < n; i++){
            if(rnd.next(0, 1)) { // coin toss; if true, perturb a little within a small range.
                long long delta = rnd.next(0LL, min((long long)100, M-1));
                if(i % 2 == 0)
                    a[i] = max(1LL, M - delta);
                else
                    a[i] = 1 + delta;
            }
        }
    }
    else{
        // Unknown mode; default to random.
        for (int i = 0; i < n; i++){
            a[i] = rnd.next(1LL, M);
        }
    }
 
    // Output the array, space-separated.
    for (int i = 0; i < n; i++){
        cout << a[i] << (i+1 < n ? " " : "\n");
    }
 
    return 0;
}
