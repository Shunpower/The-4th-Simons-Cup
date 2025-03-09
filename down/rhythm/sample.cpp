#include <vector>
#include "rhythm.h"
std::vector <int> ans;
std::vector <int> rhythm(int n, int q, int c){
    long long x=remind(1,n);
	ans.clear();
	for(int i = 1; i <= n; i++) ans.push_back(x);
	return ans;
}