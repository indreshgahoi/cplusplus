/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 

import java.util.Scanner;
/**
 *
 * @author indresh
 */import java.util.Scanner;
public class Main {

    static String s1="";
    static String s2="";
    static int no = 0;

    static void check(char ch) {
        for (int k = 0; k < s2.length(); k++) {
            if (ch == '.') {
                Main.no = Main.no + s2.length();
                s2 ="";
				break ;
            } else if (s2.charAt(k) == ch && ch!='.')
                break ;
             else if (s2.charAt(k)<ch) {
			    no=no+(s2.substring(k,s2.length()).length());
                s2=s2.substring(0,k)+ch;
				break ;
            }else {if(k==s2.length()-1)
			{s2=s2+ch;
               break ;          
			}
            }


        }}


    public static void main(String[] str) {
        System.out.println("Enter the no of string of sensor data");
        Scanner in = new Scanner(System.in);

        int num = in.nextInt();
        for (int j = 0; j < num; j++) {
            System.out.println("Enter the" + (j + 1) + "th String");

            s1 = s1+in.next();

        }

        for (int j = 0; j < s1.length(); j++) {
            if (s2.length()==0) {
                s2 = s1.substring(j,j+1);
				if(s2.charAt(0)=='.')
				{
				s2="";
				}
			    } else {
				System.out.println(no);
				System.out.println(s2);
                check(s1.charAt(j));
            }
        }
		Main.no=Main.no+s2.length();
        System.out.println("the result is:" + Main.no);// </editor-fold>
}}

