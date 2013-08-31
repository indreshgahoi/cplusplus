import java.util.Scanner;
 class Main1 {

    static String s1=new String("");
    static String s2=new String("") ;
    static int no = 0;

    static  void check(char ch) {
        for (int k = 0; k < Main1.s2.length(); k++) {
            if (ch == '.') {
                Main1.no = Main1.no + Main1.s2.length();
                Main1.s2 ="";
				break ;
            } else if (Main1.s2.charAt(k) == ch || ch!='.'){
			 Main1.no=Main1.no+(Main1.s2.substring(k+1,Main1.s2.length()).length());
                Main1.s2=""+Main1.s2.substring(0,k+1);
			}
                break ;
             else if (Main1.s2.charAt(k)<ch) {
			    Main1.no=Main1.no+(Main1.s2.substring(k,Main1.s2.length()).length());
                Main1.s2=""+Main1.s2.substring(0,k)+ch;
                //System.out.println(s2);
            }else {if((k==Main1.s2.length()-1)){
                         Main1.s2=""+Main1.s2+ch;
                        // System.out.println(s2);
			 
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
          
        for (int j = 0; j < Main1.s1.length(); j++) {
            if (s2.length()==0) {
                Main1.s2 = Main1.s1.substring(j,j+1);
				if(Main1.s2.charAt(0)=='.')
				{
				s2="";
				}
			    } else {
				//System.out.println(no);
				
                check(Main1.s1.charAt(j));
                //System.out.println(s2);
                //Main1.no=Main1.no+s2.length();
                // System.out.println(""+ Main1.no);
            }
        }
		Main1.no=Main1.no+s2.length();
        System.out.println("the result is:" + Main1.no);
        
        // </editor-fold>
}}
