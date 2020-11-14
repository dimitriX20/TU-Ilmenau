public class Main {    
  static int maze[][] = {{ 1,0,0,0,0,0,0,0},
                         { 1,1,0,0,0,0,0,0},
                         { 0,1,0,0,0,0,0,0},
                         { 1,1,1,1,1,0,0,0},
                         { 1,0,0,0,1,1,0,0},
                         { 1,0,0,0,0,1,0,1},
                         { 0,1,0,0,0,1,0,0},
                         { 0,1,1,1,1,1,1,1}}; 


  static void printSolution(boolean sol[][]){
      for (int x = 0; x < height; x++) {
          for (int y = 0; y < width; y++)
              System.out.print(sol[x][y] == true? " * ": " 0 ");
              System.out.println();
      }
  }   

  public static int height = maze.length, width = maze[0].length;
  public static int startX = 0, startY = 0, targetX= height-1, targetY = width-1; 
  public static boolean[][] visited = new boolean[height][width];
  public static final int[][] directions = {{-1, 0}, {1,0}, {0,-1}, {0,1}};    
  public static final char[] himmelsRichtungen= {'N', 'S' , 'W' , 'E'};

  static boolean validCoordinate(int x, int y){
      return (x >= 0 && y >= 0 && x <= height-1 && y <= width-1); 
  }  

  static boolean dfs(int x, int y) {
      if(maze[x][y] == 0) return false; 
      visited[x][y] = true;
      if(x == targetX && y == targetY)return true; 
      for (int i = 0; i < directions.length; i++) {
          int newX= x+ directions[i][0];
          int newY= y+ directions[i][1]; 
          if(validCoordinate(newX, newY)){
              if (!visited[newX][newY] && dfs(newX, newY)) return true;  
          }  
      }
       visited[x][y] = false;
       return false; 
  }

  public static void main(String[] args) {
      dfs(startX, startY); 
      printSolution(visited); 
      }
}
