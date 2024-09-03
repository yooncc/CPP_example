#include <iostream>

using namespace std;

long long x, y;

int main()
{
   cin >> x >> y;

   
   if (x==0 && y==0) {
      cout << 1;
   }
   else if ((x > 0 && y > 0) || (x < 0 && y < 0)) {   // 1사분면 && 3사분면
      long long cur = abs(x)+abs(y);   // 위치

      if (y > 0) {
         cout << ((3 * cur * cur) - (2 * cur) + 1) - abs(x);
      }
      else {
         cout << ((3 * cur * cur) + cur + 1) - abs(x);
      }
   }
   else {   // 2사분면 && 4사분면
      long long cur = max(abs(x), abs(y));   // 위치
      
      if (y == 0) {
         if (x > 0) {
            cout << ((3 * cur * cur) + cur + 1) + abs(x) + (cur - abs(y));
         }
         else {
            cout << ((3 * cur * cur) - (2 * cur) + 1) + abs(x) + (cur - abs(y));
         }
      }
      else if (y > 0) {
         cout << ((3 * cur * cur) - (2 * cur) + 1) + abs(x) + (cur - abs(y));
      }
      else {
         cout << ((3 * cur * cur) + cur + 1) + abs(x) + (cur - abs(y));
      }
      
   }


   return 0;
}

