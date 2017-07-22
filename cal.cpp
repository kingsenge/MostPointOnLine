// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<map>
#include<vector>

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

using namespace std;

class Solution {
public:
    void recordPoint(double cor,map<double,int>& rate,int& nMax )
    {
        map<double,int>::iterator oIter = rate.find(cor);
        if(oIter==rate.end())
        {
            rate[cor] = 2;
            if(nMax < 2)
                nMax = 2;
            return ;
        }
       
        oIter->second++;
        if(oIter->second>nMax)
            nMax = oIter->second;
    }
    
    int maxPoints(vector<Point>& points) {
        int nSize = points.size();
        double nRate = 0;
        double delX = 0,delY = 0;
        int iRet = 0,i=0;
        if(nSize == 1)
            return 1;
   
        map<double,int> mapRate;
        map<double,int> mapXulimit;
        map<double,int> mapYulimit;
        int         samePoint =0 ;
		int			nMax = 0;

        for(int j= i+1;j< nSize;j++)
        {
            if(j == i)
                continue;
                
            if(points[j].x == points[i].x &&points[j].y == points[i].y)
            {
                samePoint++;
                continue;
            }
                
            if(points[j].x == points[i].x)
            {
                recordPoint(points[j].x,mapXulimit,nMax);
                continue;
            }
            delX = points[j].x - points[i].x;
                
            if(points[j].y == points[i].y)
            {
                recordPoint(points[j].y,mapYulimit,nMax);
                continue;
            }
            delY = points[j].y - points[i].y;
                
            nRate = delX/delY;
            recordPoint(nRate,mapRate,nMax);
        }
            
		if(nMax == 0)
			nMax=samePoint+1;
		else
			nMax+=samePoint;
        
        return nMax;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution a;
	vector<Point> b;
	b.push_back(Point(-4,1));
	b.push_back(Point(-7,7));
	b.push_back(Point(-1,5));
	b.push_back(Point(9,-25));

	int iRet = a.maxPoints(b);
	printf("%d",iRet);
	return 0;
}

