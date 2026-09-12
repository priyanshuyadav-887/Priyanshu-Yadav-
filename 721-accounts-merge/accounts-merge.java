import java.util.*;

class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, String> parent = new HashMap<>();
        Map<String, String> owner = new HashMap<>();
        for (List<String> acc : accounts) {
            String name = acc.get(0);
            for (int i = 1; i < acc.size(); i++) {
                String email = acc.get(i);
                parent.put(email, email);
                owner.put(email, name);
            }
        }
        for (List<String> acc : accounts) {
            String first = acc.get(1);
            for (int i = 2; i < acc.size(); i++) {
                union(parent, first, acc.get(i));
            }
        }
        Map<String, TreeSet<String>> map = new HashMap<>();
        for (String email : parent.keySet()) {
            String root = find(parent, email);
            map.putIfAbsent(root, new TreeSet<>());
            map.get(root).add(email);
        }
        List<List<String>> res = new ArrayList<>();
        for (String root : map.keySet()) {
            List<String> list = new ArrayList<>();
            list.add(owner.get(root));
            list.addAll(map.get(root));
            res.add(list);
        }

        return res;
    }

    private String find(Map<String, String> parent, String x) {
        if (!parent.get(x).equals(x)) {
            parent.put(x, find(parent, parent.get(x)));
        }
        return parent.get(x);
    }

    private void union(Map<String, String> parent, String a, String b) {
        String pa = find(parent, a);
        String pb = find(parent, b);
        if (!pa.equals(pb)) {
            parent.put(pa, pb);
        }
    }
}