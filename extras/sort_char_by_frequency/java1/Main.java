/*

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

*/

import java.util.*;
class Solution {
    public String frequencySort(String s) {
        
        HashMap<Character,Integer> map = new HashMap<Character,Integer>();
        
        ValueComparator bvc =  new ValueComparator(map);
        
        TreeMap<Character,Integer> sorted_map = new TreeMap<Character,Integer>(bvc);
        
        for(char c : s.toCharArray()){
          if(map.containsKey(c))
            map.put(c, map.get(c)+1);
          else
            map.put(c, 1);
        }


        sorted_map.putAll(map);
        
     //   System.out.println("results: "+sorted_map);

        String sorted = "";

        for(Map.Entry<Character, Integer> e : sorted_map.entrySet()){
          String temp = Character.toString(e.getKey());
          String temp2 = temp.repeat(e.getValue());
          sorted += temp2;
        }
        
        return sorted;
    }
}

class ValueComparator implements Comparator<Character> {

    Map<Character,Integer> base;
    public ValueComparator(Map<Character,Integer> base) {
        this.base = base;
    }
  
    public int compare(Character a, Character b) {
        if (base.get(a) > base.get(b)) {
            return -1;
        } else {
           return 1;
        }
    }
}
public class Main {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        Solution sl = new Solution();
        System.out.println(sl.frequencySort(s));

    }
}