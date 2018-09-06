//leetcode:489. Robot Room Cleaner
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    int dx[4] = {1, 0,-1, 0}; // up, right, down, left
    int dy[4] = {0, 1, 0, -1};
    unordered_map<int,unordered_map<int, int>> hash;
    int x =0;
    int y =0;
    int dir = 0; 
    void cleanRoom(Robot& robot) {
        //skip all visited area.
        if(hash[x][y] == 1 ){
            return;
        }
        hash[x][y] = 1; //mark as visited.
        robot.clean();
        //DFS to clean all four directions
        for(int i = 0; i < 4; i++){
            if(robot.move()){
                //change direction
                x+=dx[dir]; //keep track on dir
                y+=dy[dir];
                cleanRoom(robot); //the location of robot change after this statement
                //all thread share one robot, get back to previous location
                robot.turnRight();
                robot.turnRight();
                robot.move(); 
                robot.turnRight();
                robot.turnRight(); // facing up again.
                x-=dx[dir];
                y-=dy[dir];
            }
            robot.turnRight();
            dir=(dir+1)%4;
        }
        
    }
};