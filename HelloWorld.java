/**
 *  Created by Zian Gong on 2019/10/24
 */
public class HelloWorld {
    public static void main(String[] args){
        HelloWorld helloWorld=new HelloWorld();
        boolean re=helloWorld.isPalindrome(1234321);
        System.out.println(re);
    }

    //Determine whether an integer is a palindrome
    public boolean isPalindrome(int x) {
        boolean res=true;
       if(x<0)
           res=false;
       else{
           int y=1;
           for(;x/y>=10;y*=10);
           while(x>0){
               int l=x/y;
               int r=x%10;
               if(l!=r){
                   res=false;
                   break;
               }
               x%=y;
               x/=10;
               y/=100;
           }
       }
       return res;
    }
}
