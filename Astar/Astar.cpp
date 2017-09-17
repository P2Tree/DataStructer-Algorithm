//
// Created by PWE on 2017/9/8.
//
#include <math.h>
#include "Astar.h"

void Astar::InitAstar(vector<vector<int>> &_maze) {
    maze = _maze;
}

int Astar::calcG(Point *temp_start, Point *point) {
    int extraG = (abs(point->x - temp_start->x) + abs(point->y - temp_start->y)) == 1 ? kCost1 : kCost2;
    int parentG = point->parent == nullptr ? 0 : point->parent->G;
    return parentG + extraG;
}

int Astar::calcH(Point *point, Point *end) {
    return (int)sqrt((double)(end->x - point->x) * (double)(end->x - point->x)
                + (double)(end->y - point->y) * (double)(end->y - point->y)) * kCost1;
}

int Astar::calcF(Point *point) {
    return point->G + point->H;
}

Point *Astar::getLeastFpoint() {
    if (!openList.empty()) {
        auto resPoint = openList.front();
        for (auto &point : openList)
            if (point->F < resPoint->F)
                resPoint = point;
        return resPoint;
    }
    return NULL;
}

Point *Astar::findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner) {
    openList.push_back(new Point(startPoint.x, startPoint.y));
    while(!openList.empty()) {
        auto curPoint = getLeastFpoint();   // 找到openList中F最小的点
        openList.remove(curPoint);  // 从开启列表中删除
        closeList.push_back(curPoint);  // 加入到关闭列表
        auto surroundPoints = getSurroundPoints(curPoint, isIgnoreCorner);  // 找到当前点周围的8个格子可以通过的格子
        for (auto &target : surroundPoints) {
            //对于某一个格子，如果它不在开启列表，加入开启列表，设置当前格为其父节点，计算F G H
            if (!isInList(openList, target)) {
                target->parent = curPoint;
                target->G = calcG(curPoint, target);
                target->H = calcH(target, &endPoint);
                target->F = calcF(target);

                openList.push_back(target);
            }
                //对于某个格子，如果它在开启列表中，计算G值，如果比原来的大，就什么也不做，否则设置它的父节点为当前点，并更新G和F
            else {
                int tempG = calcG(curPoint, target);
                if (tempG < target->G) {
                    target->parent = curPoint;
                    target->G = tempG;
                    target->F = calcF(target);
                }
            }
            Point *resPoint = isInList(openList, &endPoint);
            if (resPoint)
                return resPoint;
        }
    }
    return nullptr;
}

list<Point*> Astar::GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner) {
    Point *result = findPath(startPoint, endPoint, isIgnoreCorner);
    list<Point*> path;
    while(result) {
        path.push_back(result);
        result = result->parent;
    }
    return path;
}

Point *Astar::isInList(const list<Point *> &list, const Point *point) const {
    for (auto p : list)
        if (p->x == point->x && p->y == point->y)
            return p;
    return nullptr;
}

bool Astar::isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const {
    if (target->x < 0 || target->x > maze.size()-1
            || target->y < 0 && target->y > maze[0].size()-1
            || maze[target->x][target->y] == 1
            || target->x == point->x && target->y == point->y
            || isInList(closeList, target))
        return false;   // 物理条件不可达
    else {
        if (abs(point->x - target->x) + abs(point->y - target->y) == 1)  // 非斜角
            return true;
        else {
            // 斜角要判断是否被转角绊住
            if (maze[point->x][target->y] == 0 && maze[target->x][point->y] == 0)
                return true;
            else
                return isIgnoreCorner;  // 如果忽略转角绊住，则这里返回正常
        }
    }
}

vector<Point*> Astar::getSurroundPoints(const Point *point, bool isIgnoreCorner) const {
    vector<Point*> surroundPoints;

    for (int x = point->x - 1; x <= point->x + 1; x++)
        for (int y = point->y - 1; y <= point->y + 1; y++)
            if (isCanreach(point, new Point(x, y), isIgnoreCorner))
                surroundPoints.push_back(new Point(x, y));

    return surroundPoints;
}
