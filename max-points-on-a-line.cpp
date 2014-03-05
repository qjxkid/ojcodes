#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
         

bool cmpless(Point a, Point b) {
    if (a.x < b.x) {
        return true;
    }
    if (a.x == b.x) {
        return (a.y < b.y);
    }
    else {
        return false;
    }
}

bool cmpequal(Point a, Point b) {
    return (a.x == b.x && a.y == b.y);
}

int getMaxPoints(vector<Point> &points, int index) {
    int i = index;
    int len = points.size();
    int x = points.at(index).x;
    int y = points.at(index).y;
    Point tmp;
    double k;
    unordered_map<double, int> mymap;
    int maxnum = 0;
    for (i = index+1; i < len; i++) {
        tmp = points.at(i);
        if (tmp.x == x) {
            k = -1;
        }
        else {
            k = (double)(tmp.y - y) / (double)(tmp.x - x);
        }
        mymap[k]++;
        maxnum = maxnum > mymap[k] ? maxnum : mymap[k];
    }

    return maxnum;
}

int maxPoints(vector<Point> &points) {
    //make points unique
    sort(points.begin(), points.end(), cmpless);
    //points.erase(unique(points.begin(), points.end(), cmpequal), points.end());
    int len = points.size();
    if (len == 0) return 0;
    if (len == 1) return 1;

    int maxnum = getMaxPoints(points, 0);
    int tmp = maxnum;
    int i;
    int x = points.at(0).x;
    int y = points.at(0).y;
    int samenum = 1;
    for (i = 1; i < len; i++) {
        if (x == points.at(i).x && y == points.at(i).y) {
            samenum++;
            if (i == len-1) {
                maxnum = maxnum > samenum ? maxnum : samenum;
            }
            continue;
        }
        else {
            tmp = getMaxPoints(points, i-1);
            tmp = samenum + tmp;
            maxnum = maxnum > tmp ? maxnum : tmp;
            samenum = 1;
            x = points.at(i).x;
            y = points.at(i).y;
        }
    }
    return maxnum;
}

int main() {
    //unordered_map<double,int> a;
    //a[1.1]++;
    //cout<<a[1.1];
    Point a[] = {
        //Point(0,0),
        Point(0,0),
        //Point(1,1),
        //Point(2,1),
        //Point(1,5),
        //Point(2,10),
        //Point(1,3),
        //Point(2,2),
        //Point(1,1),
        //Point(3,15),
        //Point(3,2),
        //Point(2,3),
        //Point(1,1),
        //Point(4,20),
        //Point(2,2),
        //Point(3,3),
                };
    int asize = sizeof(a)/sizeof(Point);
    int i;
    vector<Point> b;
    for (i = 0; i < asize; i++) {
        b.push_back(a[i]);
    }
    cout<<maxPoints(b);

    return 0;
}
