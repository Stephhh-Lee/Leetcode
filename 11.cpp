import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int city = scanner.nextInt()+1;
        int road = scanner.nextInt();
        int[][] matrix = new int[city][city];
        for(int i =0 ;i < road;i++){
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            matrix[start][end] = 1;
        }
        DFS(city,matrix);
        int[] rowSum = new int[city];
        int[] columnSum = new int[city];
        for(int i = 0;i < city;i++){
            for(int j = 0;j <  city;j++){
                rowSum[i] += matrix[i][j];
                columnSum[i] += matrix[j][i];
            }
        }
        int importantCity = 0;
        for(int i = 0;i < city;i++){
            if(columnSum[i] > rowSum[i]) importantCity++;
        }
        System.out.println(importantCity);
    }

    private static int firstVertex(int v,int city,int[][] matrix) {

        if (v<0 || v>(city-1))
            return -1;

        for (int i = 0; i < city; i++)
            if (matrix[v][i] == 1)
                return i;

        return -1;
    }


    private static int nextVertex(int v, int w,int city,int[][] matrix) {

        if (v<0 || v>(city-1) || w<0 || w>(city-1))
            return -1;

        for (int i = w + 1; i < city; i++)
            if (matrix[v][i] == 1)
                return i;

        return -1;
    }
    private static void DFS(int i, boolean[] visited,int city,int[][] matrix) {

        visited[i] = true;
        for (int w = firstVertex(i,city,matrix); w >= 0; w = nextVertex(i, w,city,matrix)) {
            if (!visited[w])
                DFS(w, visited, city,matrix);
        }
    }

    public static void DFS(int city,int[][] matrix) {
        boolean[] visited = new boolean[city];
        for (int i = 0; i < city; i++)
            visited[i] = false;
        for (int i = 0; i < city; i++) {
            if (!visited[i])
                DFS(i, visited,city,matrix);
        }
    }
}
