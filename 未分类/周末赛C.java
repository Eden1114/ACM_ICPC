		import java.util.*;
		import java.math.BigDecimal;
		import java.math.BigInteger;

		public class Main {
			public static void main(String[] args) {
				
				Scanner s =new Scanner(System.in);
				BigInteger N,K;
				
				N = s.nextBigInteger();
				K = s.nextBigInteger();
				BigInteger T = new BigInteger("1");
				BigInteger Z = new BigInteger("0");
				
				
				while(K.compareTo(Z) != 0)
				{
					N = N.shiftRight(1);
					K = K.subtract(T);
				}
				
				if(N.compareTo(T) <= 0)
				{
					System.out.println("Your wish is granted!");
				}
				
				else
				{
					System.out.println("You will become a flying monkey!");
				}
				
			}
		}