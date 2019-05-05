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
enum DIR {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
};

class Cell {
    int x;
    int y;
    DIR in;
    DIR leae;
};

class Solution {
    stack 
    map<int, int> visited;
public:
    void cleanRoom(Robot& robot) {
    }
};
