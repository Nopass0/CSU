#include <cstdio>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
    fstream file;
    file.open("input.txt");
    
    while(file) {
      string str;
      getline(file, str);
      if(str.length()==0) continue;

      int len = str.length();
      long long max=-999999999999999999;
      bool isNegative = false;
      for(int i=0; i < len; i++) {
        string nstr = str;
        if(str[i]!='-') nstr.erase(i, 1);
        if(atoi(nstr.c_str())>max) {
          max = atoi(nstr.c_str());
        }
      }
      
      printf("%lld\n", max);
      
  }
}