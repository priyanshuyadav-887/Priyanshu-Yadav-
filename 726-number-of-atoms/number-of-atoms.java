class Solution {
 public String countOfAtoms(String formula) {
        Stack<Map<String, Integer>> stack = new Stack<>();
        stack.push(new HashMap<>());
        int i = 0, n = formula.length();

        while (i < n) {
            char c = formula.charAt(i);

            if (c == '(') {
                stack.push(new HashMap<>());
                i++;
            } else if (c == ')') {
                Map<String, Integer> top = stack.pop();
                i++;
                int start = i;
                while (i < n && Character.isDigit(formula.charAt(i))) i++;
                int mult = start < i ? Integer.parseInt(formula.substring(start, i)) : 1;

                for (String key : top.keySet()) {
                    int val = top.get(key) * mult;
                    stack.peek().put(key, stack.peek().getOrDefault(key, 0) + val);
                }
            } else {
                int start = i++;
                while (i < n && Character.isLowerCase(formula.charAt(i))) i++;
                String atom = formula.substring(start, i);

                start = i;
                while (i < n && Character.isDigit(formula.charAt(i))) i++;
                int count = start < i ? Integer.parseInt(formula.substring(start, i)) : 1;

                stack.peek().put(atom, stack.peek().getOrDefault(atom, 0) + count);
            }
        }

        Map<String, Integer> map = stack.pop();
        List<String> keys = new ArrayList<>(map.keySet());
        Collections.sort(keys);

        StringBuilder sb = new StringBuilder();
        for (String key : keys) {
            sb.append(key);
            int val = map.get(key);
            if (val > 1) sb.append(val);
        }

        return sb.toString();
        
    }
}