#include <iostream>
#include <vector>


using namespace std;

int main()
{
   cin.tie(NULL)->ios::sync_with_stdio(false);
   
   int N;
   vector<int> v;
   vector< pair<int,int> > m;
   cin >> N;
   
   for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      v.push_back(x);
   }

   cin >> N;
   for (int i = 0; i < N; i++) {
      int x, y;
      cin >> x >> y;
      pair<int, int> pi;
      pi.first = x; pi.second = y;
      m.push_back(pi);
   }

   for (auto it = m.begin(); it != m.end(); it++) {
      if ((it->first) == 1) {
         for (int i = 0; i < v.size(); i++) {
            if ((i + 1) % (it->second) == 0) {
               v[i] = !v[i];
            }
         }
      }
      else {
         int rPoint = (it->second) - 1;
         int maxL = -1;
         for (int i = 1; ; i++) {
            if (rPoint-i < 0 || rPoint+i >= v.size()) {
                break;
            }
            if (v[rPoint - i] == v[rPoint + i]) {
               maxL = i;
            }
            else {
               break;
            }
         }
         if (maxL != -1) {
            for (int i = 1; i <= maxL; i++) {
               v[rPoint - i] = !v[rPoint - i];
               v[rPoint + i] = !v[rPoint + i];
            }
            v[rPoint] = !v[rPoint];
         }
         else {
            v[rPoint] = !v[rPoint];
         }
      }
   }
   
   for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
      
      if ((i + 1) % 20 == 0) {
         if ((i + 1) != v.size()) {
            cout << endl;
         }
      }
   }

   return 0;
}