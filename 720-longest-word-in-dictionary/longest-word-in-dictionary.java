class Solution {
    public String longestWord(String[] words) {
         java.util.Arrays.sort(words);

        java.util.Set<String> set = new java.util.HashSet<>();
        String res = "";

        for (String w : words) {
            if (w.length() == 1 || set.contains(w.substring(0, w.length() - 1))) {
                set.add(w);
                if (w.length() > res.length()) {
                    res = w;
                }
            }
        }
        return res;
    }
}