import java.util.*;
import javax.sound.midi.*;

class Main {
    static String res = "";
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String a = in.next();
        String b = in.next();
        solve(a, b);
        System.out.println(res);
    }
    
    public static void solve(String a, String b) {
        if(a.length() == 0 && b.length() == 0) return;
        int l = b.length();
//        String last = b.substring(b.length()-1, b.length());
        String first = a.substring(0,1);
        res = first + res;
        //System.out.println(res);
        int index = b.indexOf(first);
//        System.out.println(index);
        
        if(!a.substring(index+1).equals("")) {
//            System.out.println(a.substring(index+1));
//            System.out.println(b.substring(index+1));
            solve(a.substring(index+1), b.substring(index+1));
        }
            
        if(!a.substring(1,index+1).equals("")) {
//            System.ou    t.println(a.substring(1,index+1));
//            System.out.println(b.substring(0,index));
            solve(a.substring(1, index+1) , b.substring(0, index));
        }
    }
}