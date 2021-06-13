import java.util.*;

public class Assignments{ 
  private static long assignWays(int[][] dp, int[][] in, int n, int i, int mask){
    if(i==n){
      if(mask==((1<<n)-1))
        return 1;
      else
        return 0;
    }
    if(dp[i][mask]!=-1)return dp[i][mask];
    long ans = 0;
    for(int j = 0;j<n;j++){
      ans = assignWays(dp,in, n, i+1, mask);
      if((mask&(1<<(n-j-1)))==0){
        ans+=assignWays(dp, in,n, i+1, mask|(1<<(n-j-1)));
      }
    }
    return dp[i][mask] = ans;
  }
  public static void main(){
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while(t--){
      long dp[20][1<<20];
      for(int i = 0;i<20;i++){
        for(int j = 0;j<(1<<20);j++){
          dp[i][j] = -1;
        }
      }
      int n = sc.nextInt();
      int[][] in = new int[n][n];
      for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
          in[i][j] = sc.nextInt();
        }
      }
      long ans = assignWays(dp,in,n,0);
      System.out.println(ans);
    }
  }
}