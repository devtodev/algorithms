package miguens.carlos.castleonthedrig;


import java.util.*;
import java.math.*;

public class Solution {

    public static void main(String[] args) {
            Scanner scn = new Scanner(System.in);
            BigInteger t = new BigInteger(scn.nextInt()+"");
            BigInteger t1 = new BigInteger(scn.nextInt()+"");
            int n = scn.nextInt();

            BigInteger result = new BigInteger("0");
            for(int i=2;i<n;i++){
            	result = t.add(t1.multiply(t1));
            	t = t1;
            	t1 = result;
     
            }
            System.out.println(result);
    }
}
 
