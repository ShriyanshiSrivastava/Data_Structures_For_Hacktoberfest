import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l,r,a,b,m=0;
        int s;
        l = sc.nextInt();
        r = sc.nextInt();
        for(a=l;a<=r;a++)
        {
            for(b=a;b<=r;b++)
            {
                s = a^b;
                if(s>m)
                {
                    m = a^b;
                }
            }
        }
        System.out.println(m);
    }
}
