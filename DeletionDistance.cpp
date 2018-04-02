#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LCS(string& str1, string& str2, int i, int j, vector<vector<int> >& cache) {
    if(i>=str1.size() || j>=str2.size()) return 0;

    if(cache[i][j]!=0) return cache[i][j];
    if(str1[i]==str2[j]) {
        cache[i][j]=1+LCS(str1, str2, i+1, j+1, cache);
    } else {
        cache[i][j]=max(LCS(str1, str2, i+1, j, cache), LCS(str1, str2, i, j+1, cache));
    }

    return cache[i][j];
}

int deletionDistance(string& word1, string& word2) {
    int cacheSize=word1.size()>word2.size()?word1.size():word2.size();
    vector<vector<int> > cache(cacheSize, vector<int>(cacheSize, 0));
    int debug = LCS(word1, word2, 0, 0, cache);
    return word1.size() + word2.size() - 2*debug;
}
    
int main() {
  string str1="dog", str2="frog";
  cout<<deletionDistance(str1, str2);
  
  return 0;
}
