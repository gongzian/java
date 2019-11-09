/**
 *  Created by Zian Gong on 2019/11/9
 *
 *  In a list, find all possible three integers which sum equals 0
 *
 */
import java.util.*;

public class FindTriples {

    public static void main(String[] args){
        FindTriples ft=new FindTriples();
        int[] nums = {-1,0,1,2,-1,-4,5,9,7,45,1,6,54,9,-9,-5,-4,-3};
        List<List<Integer>> res=ft.findTriples(nums);
        System.out.println(res);
    }

    public List<List<Integer>> findTriples(int[] nums) {
        List<List<Integer>> res = new ArrayList();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length-2; i++) {
            int left = i+1;
            int right = nums.length-1;
            if (i == 0 || nums[i] != nums[i-1]) {
                while (left < right) {
                    if (nums[i] + nums[left] + nums[right] == 0) {
                        List<Integer> tt = new ArrayList();
                        tt.add(nums[i]);
                        tt.add(nums[left]);
                        tt.add(nums[right]);
                        res.add(tt);
                        while (nums[right] == nums[right-1])
                            right--;
                        while (nums[left] == nums[left+1])
                            left++;
                        right--;
                        left++;
                    } else if (nums[i] + nums[left] + nums[right] < 0)
                        left++;
                    else
                        right--;
                }
            }
        }
        return res;
    }
}
