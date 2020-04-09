/*
*
*
* INPUT
    abc acb cab def dfe lkj jkl kjl

* OUTPUT
    abc acb cab
    def dfe
    lkj jkl kjl

*
*
* */



import java.util.*;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {

        List<List<String>> anagrams = new ArrayList<>();

        HashMap<String, List<String>> map = new HashMap<>();

        for(int i = 0; i < strs.length; i++){

            char[] letters = strs[i].toCharArray();
            Arrays.sort(letters);
            String newWord = new String(letters);

            if(map.containsKey(newWord)){
                map.get(newWord).add(strs[i]);
            }else{

                List<String> words = new ArrayList<>();
                words.add(strs[i]);
                map.put(newWord, words);

            }

        }

        for(String s: map.keySet()){
            List<String> values = map.get(s);
            if(values.size() >= 1)
                anagrams.add(values);
        }

        return anagrams;
    }
}

public class Anagram {

    public static void main(String[] args){

        Scanner s = new Scanner(System.in);
        List<String> list = new ArrayList<>();
//        while (s.hasNextLine())
//            list.add(s.next());
        String words = s.nextLine();
        String words_array[] = words.split(" ");


//        String[] strs = list.toArray(new String[0]);

        List<List<String>> anagrams = new Solution().groupAnagrams(words_array);

        for (List<String> l1 : anagrams) {
            for (String n : l1) {
                System.out.print(n + " ");
            }

            System.out.println();
        }
    }
}