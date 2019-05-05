// why val should be true when isLeaf is false !!!!
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
    void cn(vector<vector<int>>& grid, int x, int y, int n, Node** node)
    {
        bool same = true;
        int v = grid[x][y];
        for (int i = x; i < x + n; i ++)
            for(int j = y; j < y + n; j ++)
                if (grid[i][j] != v)
                {
                    same = false;
                    break;
                }
        Node* z = new Node(grid[x][y], same, NULL, NULL, NULL, NULL);
        *node = z;

        if (!same)
        {
            z->val = true;
            cn(grid, x, y, n / 2, &z->topLeft);
            cn(grid, x, y + n / 2, n / 2, &z->topRight);
            cn(grid, x + n / 2, y, n / 2, &z->bottomLeft);
            cn(grid, x + n / 2, y + n / 2, n / 2, &z->bottomRight);
        }
    }

 public:
    Node* construct(vector<vector<int>>& grid) {
        if (!grid.size())
            return NULL;
        Node* n = NULL;
        cn(grid, 0, 0, grid.size(), &n);
        return n;
    }
};
