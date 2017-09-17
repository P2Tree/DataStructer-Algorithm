//
// Created by PWE on 2017/9/8.
//

#ifndef ASTAR_ASTAR_H
#define ASTAR_ASTAR_H
#include <vector>
#include <list>
#include <clocale>

using namespace std;

const int kCost1 = 10;  // 直着移动一格的消耗
const int kCost2 = 14;  // 斜着移动一格的消耗

struct Point {
    int x,y;    // 坐标，x为横轴，y为纵列
    int F,G,H;  // F = G + H, G为从起点到网格上指定方格的移动耗费，
                // H为从指定方格到终点的预计耗费，最终选择下一步走哪个格取决于F
    Point *parent;  // parent的坐标
    Point(int _x, int _y):x(_x),y(_y),F(0),G(0),H(0),parent(nullptr) {
    }
};

class Astar {
public:
    void InitAstar(vector<vector<int>> &_maze);
    list<Point*> GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);

private:
    Point *findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
    vector<Point*> getSurroundPoints(const Point *point, bool isIgnoreCorner) const;
    bool isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const;    // 判断某点是否可用于下一步判断
    Point *isInList(const list<Point*> &list, const Point *point) const;    // 判断开启/关闭列表中是否含有某点
    Point *getLeastFpoint();    // 从开启列表中返回F值最小的节点

    int calcG(Point *temp_start, Point *point);
    int calcH(Point *point, Point *end);
    int calcF(Point *point);

private:
    vector<vector<int>> maze;
    list<Point*> openList;
    list<Point*> closeList;
};

#endif //ASTAR_ASTAR_H
