//package hacktober;
import java.util.Scanner;
import java.lang.String;
public class StringOperations 
{
	public static void main(String args[])
	{	
		Scanner sc  = new Scanner(System.in);
		System.out.println("Enter a String: ");
		String str1 = sc.nextLine();
		String str2 = "welcome to hacktober 2021";
		System.out.println(str1.charAt(6)); //returns character at the specified index
		System.out.println(str1.substring(2, 8));	//creates a substring, startindex inclusive and endindex exclusive
		System.out.println(str2.contains("hack"));	//checks whether the given string contains the substring, returns boolean value 
		System.out.println(String.join("-", "hacktober", "2021"));
		System.out.println(str1.compareToIgnoreCase(str2)); 
		/*returns 0 if strings are equal in length, value less than 0 if the string 
		 * has less characters than the other string 
		 * and a value greater than 0 if the string has more characters than the other string
		 * ignoring the case. 
		 */	
		System.out.println(str1.toLowerCase()); //converts string to lower case
		System.out.println(str1.concat(str2));	//joins two strings
		System.out.println(String.format("decimal value: %.2f", 34.8794));//returns the formatted string by given locale
		System.out.println(str2.replace('e', 'i')); //replaces characters
	}
}
/*
 * INPUT: 
 * Enter a String: 
 * PR for Hacktober FEST 2021
 * OUTPUT: 
 *  for H
 * true
 * hacktober-2021
 * -7
 * pr for hacktober fest 2021
 * PR for Hacktober FEST 2021welcome to hacktober 2021
 * decimal value: 34.88
 * wilcomi to hacktobir 2021
 */
