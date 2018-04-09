//Author: Yifan Ding & (你的名字)
//cite: Work together .drawcircle .text and .grid belong to (你的名字) others belong to Yifan Ding

#include <iostream>
#include <fstream>
using namespace std;
class Postscript {

private:
    ofstream file;
public:
    Postscript(const string &name) {
        file.open(name);    //equals ofstream file(name)
    }
    ~Postscript(){
        file.close();
    }

    void line(int m, int n, int i, int j) {
        file << m << ' ' << n << " moveto " << i << ' ' << j << " lineto  stroke\n";

    }

    void setColor(float r, float g, float b) {
        file  << r << ' ' << g << ' ' << b << " setrgbcolor" <<  "\n";
        file << '\n';
    }

    void drawRect(int x, int y, int a, int b) {
        file << x << ' ' << y << " moveto\n" << x + a << ' ' << y << " lineto\n" << x + a
             << ' ' << y + b << " lineto\n" << x << ' ' << y + b << " lineto\n"
             << "closepath gsave stroke\n";
        file << '\n';
    }

    void fillRect(int x, int y, int a, int b) {
        file << x << ' ' << y << " moveto\n" << x + a << ' ' << y << " lineto\n" << x + a
             << ' ' << y + b << " lineto\n" << x << ' ' << y + b << " lineto\n"
             << "closepath gsave fill\n";
        file << '\n';
    }

    void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
        file << x1 << ' ' << y1 << " moveto\n" << x2 << ' ' << y2 << " lineto\n"
             << x3 << ' ' << y3 << " lineto\n" << "closepath gsave stroke\n";
        file << '\n';
    }

    void fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
        file << x1 << ' ' << y1 << " moveto\n" << x2 << ' ' << y2 << " lineto\n"
             << x3 << ' ' << y3 << " lineto\n" << "closepath gsave fill\n";
        file << '\n';
    }

    void setFillColor(double r, double g, double b){
        file << "grestore gsave " << r << " " << g << " " << b << " setrgbcolor fill\n";
    }

    void setStrokeColor(double r, double g, double b){
        file << "grestore gsave " << r << " " << g << " " << b << " setrgbcolor 2 setlinewidth stroke\n";
    }


 /*   void drawCircle(int x, int y, int r) {


    }
*/

/*
    void text() {

    }

    void  grid() {

    }
    */
};


int main() {
    Postscript p("test2.ps");
    p.line(0,0, 200,700);  // 0 0 moveto 300 400 lineto stroke
    int r = 255, g = 0, b = 0;
    p.setColor(r, g, b);
    p.drawRect(100,50, 100, 50);   // x y moveto x+w y lineto x+w y+h lineto ... closepath stroke
    p.fillRect(200, 150, 200, 150);   // x y moveto x+w y lineto x+w y+h lineto ... closepath fill
    p.setFillColor(0, 0, 255); // 1.0 0.5 0 setrgbcolor
    // optional, figure out how you want to manage color
    p.setStrokeColor(0, 255, 0);
    p.drawTriangle(100,150, 200,150, 150,300);
    p.fillTriangle(0,0, 100,0, 50,100);
  /*  p.drawCircle(200,400,100); // x y 0 360 r arc stroke
    p.text(300,100, "testing testing 123"); // look it up  setfont  (ABC) show
    p.grid(300, 50, 500, 400, 50, 700);
*/
    //这三个里面的数值你可以不用改，text and grid 是老师自己写的，圆心的位置我设置的是应该正好可以看到，你也可以自己改


}
