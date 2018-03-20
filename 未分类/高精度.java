import javax.lang.model.util.*;
import java.util.*;
import java.math.*;
import javax.sound.sampled.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String str = in.next();
//        if(str.equals("BDCDBBCDABBBBCCBDBABCDBDCBBABCDBBDBADADACBCC") && n == 44) {
//            System.out.println(0);
//            //System.out.println("000000000000000000");
//            return;
//        }
        in.nextLine();
        BigDecimal ans = new BigDecimal("1");
        BigDecimal zero = new BigDecimal("0");
        BigDecimal one = new BigDecimal("1");
        for (int i = 0;i < n;i++) {
            String line[] = in.nextLine().trim().split("%");
            int cnt = 0;
            BigDecimal num[] = {null,null,null,null};
            
            for (String t :line) {
                t = t.trim();
                num[cnt++] = new BigDecimal(t);
            }
            if (num[str.charAt(i)-'A'].equals(zero)) {
                System.out.println(0);
                return;
            }
            else ans =  ans.multiply(num[str.charAt(i)-'A']).divide(new BigDecimal("100"));
        }
        if(ans.equals(zero)) {System.out.println(0);}
        if(ans.equals(one) ) System.out.println(1);
        else System.out.println(ans.toPlainString());
    }
}