class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
    int n = img1.length;
        List<int[]> A = new ArrayList<>();
        List<int[]> B = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) A.add(new int[]{i, j});
                if (img2[i][j] == 1) B.add(new int[]{i, j});
            }
        }

        Map<String, Integer> map = new HashMap<>();
        int max = 0;

        for (int[] a : A) {
            for (int[] b : B) {
                int dx = a[0] - b[0];
                int dy = a[1] - b[1];

                String key = dx + "," + dy;
                int count = map.getOrDefault(key, 0) + 1;
                map.put(key, count);

                max = Math.max(max, count);
            }
        }

        return max;     
    }
}