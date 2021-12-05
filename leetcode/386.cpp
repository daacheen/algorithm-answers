#include "cppincludes.h"

class Solution {
public:
  
  
  void dfs(int base, int n, vector<int>& result) {
    if (base > n) {
      return;
    }
    result.push_back(base);
    dfs(base*10, n, result);
    if (base % 10 != 9) {
      dfs(base + 1, n, result);
    }
  }
    vector<int> lexicalOrder(int n) {
        
      vector<int> result;
      dfs(1, n, result);
      return result;
    }
};