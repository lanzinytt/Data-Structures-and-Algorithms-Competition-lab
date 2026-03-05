#include <bits/stdc++.h>
using namespace std;

int main() {
  const int N=10;
  for(int i=0;i<N;i++) {
    system("gen.exe > test.in"); 
    system("a.exe < test.in > a.out"); 
    system("b.exe < test.in > b.out"); 
    if (system("fc a.out b.out")) {
      system("pause"); 
      return 0;
    }
  }
  system("pause");
}