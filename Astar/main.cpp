#include <iostream>
#include "Astar.h"
using namespace std;

int main() {
    // 初始化一个地图，1为障碍物，0为可通过
    vector<vector<int>> maze = {
            {1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,1,1,0,1,0,0,0,0,1},
            {1,0,0,1,1,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,1,0,0,1,1,1},
            {1,1,1,0,0,0,0,0,1,1,0,1},
            {1,1,0,1,0,0,0,0,0,0,0,1},
            {1,0,1,0,0,0,0,1,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1}
    };
    Astar astar;
    astar.InitAstar(maze);  // 输入地图

    // 设置起始点和结束点
    Point start(1, 1);
    Point end(6, 10);

    // 寻找路径
    list<Point*> path = astar.GetPath(start, end, false);

    // 打印
    for (auto &p : path)
        cout << '(' << p->x << ',' << p->y << ')' << endl;

    return 0;
}