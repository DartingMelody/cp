import java.util.*;

public class ACMSpoj{

  private static int noOfAbs(String str, List<String> words, int n){
    str = str.toLowerCase();
    int m = str.length();
    int[][] dp = new int[m+1][n+1];
    for(int i = 0;i<=m;i++){
      for(int j = 0;j<=n;j++){
        dp[i][j] = 0;
      }
    }
    dp[m][n] = 1;
    int last = n;int cnt = 0;
    for(int k = words.size()-1;k>=0;k--){
      int strt = last - words.get(k).length();
      for(int i = m-1-cnt;i>=0;i--){
        int rem_letters = i;
        int rem_words = k;
        if(rem_letters < rem_words){
          break;
        }
        for(int j = last-1;j>=strt;j--){
          int tt = j-strt;
          if(str.charAt(i)==words.get(k).charAt(tt)){
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
      // for(int i=strt-1;i>=0;i--){
      //   dp[m-1-cnt][i] = dp[m-1-cnt][i+1];
      // }
      cnt++;
    }
    // for(int i = 0;i<=m;i++){
    //   for(int j = 0;j<=n;j++){
    //     System.out.print(dp[i][j]+" ");
    //   }
    //   System.out.println();
    // }
    return dp[0][0];
  }

  public static void main(){
    // System.out.println("hello world");
    //input area
    Scanner in = new Scanner(System.in);
    //int id1 = Integer.parseInt(input.nextLine());
    int wLength = in.nextInt();
    while(wLength!=0){
      Set<String> wasteWords = new HashSet<String>();
      in.nextLine();
      for(int i = 0;i<wLength;i++){
        String waste = in.nextLine();
        wasteWords.add(waste);
      }
      String testCase = in.nextLine();
      while(!testCase.equals("LAST CASE")){
        String[] strList = testCase.split(" ");
        String str = strList[0];
        List<String> words = new ArrayList<String>();
        int len = 0;
        for(int i = 1;i<strList.length;i++){
          if(!wasteWords.contains(strList[i])){
            words.add(strList[i]); 
            len+=strList[i].length();          
          }
        }
        int n = noOfAbs(str, words, len);
        if(n!=0)
          System.out.println(str+" can be formed in "+n+" ways");
        else
          System.out.println(str+ " is not a valid abbreviation");
        testCase = in.nextLine();
      }
      wLength = in.nextInt();
    }  
    // closing scanner2
    in.close();
  }
}