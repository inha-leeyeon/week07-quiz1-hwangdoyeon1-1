#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Point {
    public:
    Point(int px = 0, int py = 0) : x(px),y(py){}
    int getX() const{return x;}
    int getY() const{return y;}
    void setX(int px){x=px;}
    void setY(int py){y=py;}
    private:
    int x;
    int y;
};

class Square : public Point {
    public:
    Square(const string na, int x, int y,int s) :Point(x,y){side=s;area=s*s;name=na;}
    unsigned int getSide() const{return side;}
    unsigned int getArea() const{return area;}
    string getName() const{return name;}
    void setSide(unsigned int s){side=s;}
    void setArea(unsigned int s){area=s*s;}
    void setName(string na){name=na;}
    void print1()
    {
        cout<<name<<'('<<getX()<<", "<<getY()<<") side="<<side<<", area="<<area<<'\n';
    }
    void print2()
    {
        cout<<name<<'('<<getX()+side<<", "<<getY()<<") side="<<side<<", area="<<area<<'\n';
    }
    void print3()
    {
        cout<<name<<'('<<getX()<<", "<<getY()+side<<") side="<<side<<", area="<<area<<'\n';
    }
    private:
    int side; 
    unsigned int area{ 0 };
    string name;
};

int main()
{
    vector<Square> v;
    vector<pair<int,int>> area,xc,yc;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        string name;
        int x,y,s;
        cin>>name>>x>>y>>s;
        Square sq(name,x,y,s);
        v.push_back(sq);

        area.push_back({s*s,i});
        xc.push_back({x+s,i});
        yc.push_back({y+s,i});
    }

    sort(area.begin(),area.end());
    sort(xc.begin(),xc.end());
    sort(yc.begin(),yc.end());

    cout<<"\nSquares in increasing order of area\n";
    for(int i=0;i<n;i++)
    {
        v[area[i].second].print1();
    }
    cout<<'\n';
    cout<<"Squares in increasing order of max x-coordinate\n";
    for(int i=0;i<n;i++)
    {
        v[xc[i].second].print2();
    }
    cout<<'\n';
    cout<<"Squares in increasing order of max y-coordinate\n";
    for(int i=0;i<n;i++)
    {
        v[yc[i].second].print3();
    }
    
    return 0;
}