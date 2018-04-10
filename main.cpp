//Author: Yifan Ding & Tande Chen
//cite: Work together .drawcircle .text and .grid belong to Tande Chen others belong to Yifan Ding

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
using namespace std;
class Postscript {

private:
    ofstream file;
	char strokeColor[256];
	char fillColor[256];
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
        float red, green, blue;
        char buffer[256];
        red = r / 255.0;
        green = g / 255.0;
        blue= b / 255.0;
        sprintf(buffer, "%.2f %.2f %.2f setrgbcolor\n", red, green, blue);
        strcpy(strokeColor, buffer);
    }
	
	void drawCircle(float x, float y, float r){
	    file << x << ' ' << y <<' ' << r << " 0 360 arc\n" << "closepath gsave stroke\n";
        file << '\n';
    }
    
    void text(float x, float y, const char* s){
        unsigned int len = strlen(s);
        char Buf[256 + len];
        int size = sprintf(Buf, "/Times-Roman findfont 12 scalefont setfont newpath %.2f %.2f moveto (%s) %sshow\n", x, y, s, strokeColor);
        file.write(Buf, size);
		//file << "Times-Roman findfont 12 scalefont setfont newpath " << x << " " << y << " " << "moveto " << s << "gsave stroke\n"<< "show\n";
		file << '\n';
		
    }
    
    void grid(float x1, float interval_x, float x2, float y1, float interval_y, float y2){
        char Buf1[256];
        char Buf2[256];
        char Buf3[256];
        char Buf4[256];
        
        int bins_x = int((x2 - x1) / interval_x);
        int bins_y =int((y2 - y1) / interval_y);
        
        int size1 = sprintf(Buf1, "/vline {%.2f %.2f moveto %.2f %.2f lineto stroke} def\n", x1, y1, x1, y2);
        file.write(Buf1, size1);
        int size2 = sprintf(Buf2, "gsave\nvline\n%d {%.2f 0 translate vline} repeat\ngrestore\n", bins_x, interval_x);
        file.write(Buf2, size2);
        
        int size3 = sprintf(Buf3, "/hline {%.2f %.2f moveto %.2f %.2f lineto stroke} def\n", x1, y1, x2, y1);
        file.write(Buf3, size3);
        int size4 = sprintf(Buf4, "gsave\nhline\n%d {0 %.2f translate hline} repeat\ngrestore\n", bins_y, interval_y);
        file.write(Buf4, size4);
    }
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
    p.drawCircle(200,400,100); // x y 0 360 r arc stroke
    p.text(100,100, "testing！ HW from Yifan Ding and Tande Chen"); // look it up  setfont  (ABC) show
    p.grid(300, 50, 500, 400, 50, 700);
	

}