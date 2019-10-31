/**
 *  Created by Zian Gong on 2019/10/24
 */
public class HelloWorld {
    public static void main(String[] args){
        boolean re=isPalindrome(1234321);
        System.out.println(re);
    }

    //Determine whether an integer is a palindrome
    public static boolean isPalindrome(int x) {
        boolean res=true;
       if(x<0)
           res=false;
       else{
           String str=String.valueOf(x);
           for(int i=0; i<str.length()/2; i++){
               if(str.charAt(i)!=str.charAt(str.length()-i-1))
                   res = false;
           }
       }
       return res;
    }
}
