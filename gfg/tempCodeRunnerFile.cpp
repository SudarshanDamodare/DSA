t solve(int idx, int prev, vector<vector<int>> &data){
//   int maxi=INT_MIN;
//   if(idx==0){
//     for(int i=0;i<k;i++){
//       if(i!=prev){
//         maxi=max(maxi,data[idx][i]);
//       }
//     }
//     return maxi;
//   }

//   if(dp[idx][prev]!=-1) {
//     cout<<"hello\n";
//     return dp[idx][prev];
//   }

//   for(int i=0;i<k;i++){
//     int points = 0;
//     if(i!=prev){
//       points = data[idx][i] + solve(idx-1, i, data);
//     }
//     maxi=max(maxi,points);
//   }
//   return dp[idx][prev] = maxi;
// }