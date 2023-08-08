class Solution {
    class Pair{
        int r;
        int c;
        int time;
        Pair(int r, int c, int time){
            this.r = r;
            this.c = c;
            this.time = time;
        }
    }
    public int orangesRotting(int[][] grid) {
        Queue<Pair> que = new ArrayDeque<>();
        int count = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 2){
                    que.add(new Pair(i, j, 0));
                }
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        int[][] dir = {{-1, 0}, {0, -1}, {1,0}, {0, 1}};
        int time = 0;
        while(que.size() > 0){
            Pair curr = que.remove();
            time = Math.max(time, curr.time);
            for(int[] d: dir){
                int nr = curr.r + d[0];
                int nc = curr.c + d[1];

                if(nr < 0 || nc < 0 || nr >= grid.length || nc >= grid[0].length) continue;

                if(grid[nr][nc] == 1){
                    que.add(new Pair(nr, nc, curr.time + 1));
                    count--;
                    grid[nr][nc] = 2;
                }
            }
        }

        if(count > 0) return -1;

        return time;
    }
}