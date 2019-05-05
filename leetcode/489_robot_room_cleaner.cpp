// INT, LONG OVERFLOW AGAIN !!!!

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

class Solution {
public:

    bool has_done(map<long, int>& visited, int x, int y)
    {
        long xn = x & 0xFFFFFFFF;
        long yn = y & 0xFFFFFFFF;
        return visited[xn << 32 | yn] == 1;
    }

    void done(map<long, int>& visited, int x, int y)
    {
        long xn = x & 0xFFFFFFFF;
        long yn = y & 0xFFFFFFFF;
        visited[xn << 32 | yn] = 1;
    }

    void cleanRoom(Robot& robot) {
        int x = 0;
        int y = 0;

        DIR in = UP;
        DIR cur = UP;
        stack<int> st;
        map<long, int> visited;

        robot.clean();
        done(visited, x, y);

        while (true)
        {
            int tries = 0;
            for (tries = 0; tries < 4; tries ++)
            {
                DIR nc;
                DIR nn;

                int xn = x;
                int yn = y;

                if (cur == UP)
                {
                    xn = x - 1;
                    nn = DOWN;
                    nc = RIGHT;
                }
                else if (cur == RIGHT)
                {
                    yn = y + 1;
                    nn = LEFT;
                    nc = DOWN;
                }
                else if (cur == DOWN)
                {
                    xn = x + 1;
                    nn = UP;
                    nc = LEFT;
                }
                else
                {
                    yn = y - 1;
                    nn = RIGHT;
                    nc = UP;
                }

                if (!has_done(visited, xn, yn) && robot.move())
                {
                    st.push(in);
                    x = xn;
                    y = yn;
                    in == nn;
                    break;
                }

                if (has_done(visited, xn, yn))
                    printf("visited %d %d.\n", xn, yn);

                robot.turnRight();
                cur = nc;
            }

            if (tries != 4)
            {
                robot.clean();
                done(visited, x, y);
                printf(" %d %d visit.\n", x, y);
            }
            else
            {

                if (x == 0 && y == 0)
                    return;

                while (cur != in)
                {
                    robot.turnRight();

                    if (cur == UP)
                        cur = RIGHT;
                    else if (cur == RIGHT)
                        cur = DOWN;
                    else if (cur == DOWN)
                        cur = LEFT;
                    else
                        cur = UP;
                }

                robot.move();

                if (in == UP)
                    x -= 1;
                else if (in == RIGHT)
                    y += 1;
                else if (in == DOWN)
                    x += 1;
                else
                    y -= 1;
                in = (DIR) st.top();
                st.pop();
            }
        }
    }
};
