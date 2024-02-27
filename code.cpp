class Solution {
  public:
  set<string>st;
  void solve(string S , int i ,string ch){
      if(i==S.length()){
          string str=ch;
          int n=str.size();
          if(n>1){
              if((str[0]=='a' || str[0]=='e' || str[0]=='i'|| str[0]=='u'|| str[0]=='o') &&
               (str[n-1]!='a'&& str[n-1]!='e'&& str[n-1]!='i'&& str[n-1]!='u'&& str[n-1]!='o'))
               st.insert(str);
          }
          return;
      }
      solve(S , i+1 ,ch+S[i]);
      solve(S , i+1 , ch);
  }
    set<string> allPossibleSubsequences(string S) {
        // code here
        string ch="";
        solve(S , 0 , ch);
        return st;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
