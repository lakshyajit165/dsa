import java.util.*;

class Solution {

    public String frequencySort(String s) {

        Map<Character, Integer> map = new HashMap<>();

        // define priority queue to sort by frequency(second element of the map)
        PriorityQueue<Character> queue = new PriorityQueue<>((x,y) -> map.get(y) - map.get(x));

        for(char ch:s.toCharArray()) 
            map.put(ch, map.getOrDefault(ch, 0) + 1);

        for(char ch: map.keySet()) 
            queue.offer(ch); // insert a particular element into the priority queue
        StringBuffer sb = new StringBuffer();

        while(!queue.isEmpty()) {

            char ch = queue.poll();

            for(int i = 0; i < map.get(ch); i++)
                sb.append(ch);
        }

        return sb.toString();
    }
}
public class Main{

    public static void main(String[] args){

        Solution s = new Solution();

        Scanner sc = new Scanner(System.in);
        
        String str = sc.next();

        System.out.println(s.frequencySort(str));

    }
}