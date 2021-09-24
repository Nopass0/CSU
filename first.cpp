#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

int main() {
    fstream file;
    file.open("input.txt");
    
    while(file) {
      string str;
      getline(file, str);
      if(str.length()==0) continue;

      int len = str.length();
      int min = 10;
      int ID = 0;
      int max = 0;
      bool isNegative = false;
      for(int i=0; i < len; i++) {
        if(str.c_str()[i]=='-') {
          isNegative=true;
          continue;
        }
        if((str.c_str()[i]-'0'>max)&isNegative) {
          max=str.c_str()[i]-'0';
          if(ID==0) ID=i;
        }
        if((str.c_str()[i]-'0'<min)&!isNegative) {
          min=str.c_str()[i]-'0';
          ID=i;
        }
        else if(str.c_str()[i]-'0'==max) {
          if(isNegative==false) continue;
          else {
            if(ID==0) ID=i;
          }
        }
      }
      printf("%s\n", str.erase(ID, 1).c_str());
  }
}