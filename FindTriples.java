/**
 *  Created by Zian Gong on 2019/11/8
 *
 *  In a list, find all possible three integers which sum equals 0
 *
 */
import java.util.*;

public class FindTriples {

    public static void main(String[] args){
        FindTriples ft=new FindTriples();
        int[] nums=new int[6];
        nums[0]=-1;
        nums[1]=0;
        nums[2]=1;
        nums[3]=2;
        nums[4]=-1;
        nums[5]=-4;
        List<List<Integer>> res=ft.findTriples(nums);
        System.out.println(res);
    }

    public List<List<Integer>> findTriples(int[] nums){
        List<List<Integer>> res = new ArrayList();
        for(int i=0;i<nums.length-2;i++){
            for(int j=i+1;j<nums.length-1;j++){
                for(int k=j+1;k<nums.length;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        List<Integer> tt = new ArrayList();
                        tt.add(nums[i]);
                        tt.add(nums[j]);
                        tt.add(nums[k]);
                        Collections.sort(tt);
                        int eq = 0;//if eq=1 tt already in res; eq=0 add tt
                        int ct=0;//to count how many elements are same in a pair of list
                        for(int o=0;o<res.size();o++){
                            ct=0;//refresh ct every pair of lists
                            for(int p=0;p<tt.size();p++){
                                if(tt.get(p)==res.get(o).get(p))
                                    ct+=1;
                            }
                            if(ct==3){
                                eq=1;
                                break;
                            }
                        }
                        if(eq!=1)
                            res.add(tt);
                        else
                            eq = 0;
                    }
                }
            }
        }
        return res;
    }
}
