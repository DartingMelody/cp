#include <bits/stdc++.h>

using namespace std;

vector<string> fn(string str){
    vector<string> strList;
    string words = "";
    for(int i = 0;i<str.length();i++){
        if(str[i]==' '){
            strList.push_back(words);
            words = "";
        }
        else{
            words = words+str[i];
        }
    }
    if(words !="")
    strList.push_back(words);
    return strList;
}
int noOfAbs(string str, vector<string> words, int n){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    // cout<<"Strs is "<<str<<"\n";
    int m = str.length();
    vector<vector<int>> dp;
    for(int i = 0;i<=m;i++){
        vector<int> dp1;
        for(int j = 0;j<=n;j++){
            int x = 0;
            dp1.push_back(x);
        }
        // dp1.push_back(1);
        dp.push_back(dp1);
    }
    dp[m][n] = 1;
    // vector<int> dp1;
    // for(int j = 0;j<=n;j++){
    //      int x = 1;
    //     dp1.push_back(x);
    // }
    // dp.push_back(dp1);
    int last = n;int cnt = 0;
    for(int k = words.size()-1;k>=0;k--){
      int strt = last - words[k].length();
      for(int i = m-1-cnt;i>=0;i--){
        int rem_letters = i;
        int rem_words = k;
        if(rem_letters < rem_words){
          break;
        }
        for(int j = last-1;j>=strt;j--){
          int tt = j-strt;
          if(str[i]==words[k][tt]){
            // if(i==m-1-cnt){
            // dp[i+1][j+1] = dp[i+1][last];
            // }
            dp[i][j] = dp[i+1][last];
            if(last!=j+1)
                dp[i][j]+=dp[i+1][j+1];
            if(j!=last-1)
                dp[i][j]+=dp[i][j+1];
          }
          else if(j!=last-1)
          {
            dp[i][j] = dp[i][j+1];
          }
        } 
      }
      last = strt;
    //   for(int i=strt-1;i>=0;i--){
    //      dp[m-1-cnt][i] = dp[m-1-cnt][i+1];
    //   }
      cnt++;
    }
    // for(int i = 0;i<=m;i++){
    //   for(int j = 0;j<=n;j++){
    //     cout<<dp[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
    return dp[0][0];
}
int main()
{
    // cout<<"Hello World"<<"\n";
     int wLength;
  cin>>wLength;
  while(wLength!=0){
      set<string, greater<string> > wasteWords;
      for(int i = 0;i<wLength;i++){
        string waste;
        cin>>waste;
        wasteWords.insert(waste);
      }
      cin.ignore();
      string testCase;
      getline(std::cin, testCase);
      vector<string> strList = fn(testCase);
       while(!(strList[0]=="LAST"&& strList[1]=="CASE")){
         vector<string> words;
         int len = 0;
         string str = strList[0];
         for(int i = 1;i<strList.size();i++){
           if(wasteWords.find(strList[i])==wasteWords.end()){
             words.push_back(strList[i]); 
             len+=strList[i].length();          
           }
         }
         int n = noOfAbs(str, words, len);
         if(n!=0)
           cout<<str<<" can be formed in "<<n<<" ways"<<"\n";
         else
           cout<<str<<" is not a valid abbreviation"<<"\n";
         getline(std::cin, testCase);
         strList = fn(testCase);
       }
      cin>>wLength;
    }
    return 0;
}