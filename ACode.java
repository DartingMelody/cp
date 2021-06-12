import java.util.*;
import java.lang.*;

public class ACode{

  public static Long comb(String num){
    if(num.charAt(0)=='0') return 0L;
    List<Long> dp = new ArrayList<Long>();
    for(int j = 0;j<=num.length();j++){
      dp.add(Long.valueOf(0));
    }
    dp.set(1,Long.valueOf(1));
    dp.set(0,Long.valueOf(1));
    int prev = num.charAt(0)-'0';
    for(int i = 1;i<num.length();i++){
      int curr = num.charAt(i)-'0';
      if(curr!=0)
        dp.set(i+1,dp.get(i));
      if(prev*10+curr==0 ||(curr==0 && prev*10+curr>=30)){
        return 0L;
      }
      if(prev*10+curr>=10&&prev*10+curr<=26){
        dp.set(i+1, dp.get(i+1)+dp.get(i-1));
      }
      prev = curr;
    }
    return dp.get(num.length());
  }
  public static void main(){
    Scanner in = new Scanner(System.in);
    //int id1 = Integer.parseInt(input.nextLine());
    String number = in.nextLine();
    while(!(number.length()==1 && number.charAt(0)-'0'==0)){
      Long ans = comb(number);
      System.out.println(ans);
      number = in.nextLine();
    }
  }
}