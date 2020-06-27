import java.util.*;

// Definition for a binary tree node.
class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
}
 
class Solution {
    
    ArrayList<String> nums = new ArrayList<>();
    
    public void getNumbers(String s, TreeNode root) {
       
       
            s += Integer.toString(root.val);
            
            // logic to add numbers formed from root to "leaf" nodes only
            
           if(root.left == null && root.right != null){
                getNumbers(s, root.right);
            }else if(root.left != null && root.right == null){
                getNumbers(s, root.left);
            }else if(root.left == null && root.right == null){
                nums.add(s);
            }else{
                getNumbers(s, root.left);
                getNumbers(s, root.right);
           }
            
        
    }
    
    public int sumNumbers(TreeNode root) {
        
        if(root == null)
            return 0;
        
        String s = "";
        
        getNumbers(s, root);
        
        int sum = 0;
        for(String str: nums){
            // System.out.println(str + " ");
            sum += Integer.parseInt(str);
        }
        return sum;
        
       
    }
}
public class SumRootToLeaf {

    public static void main(String[] args) {

        // input for tree nodes.
    }
}