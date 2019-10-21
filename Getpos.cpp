#include<iostream>
#include<Windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的，我是背下来的 
using namespace std;
void click() {
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	Sleep(10);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}
int main(){
	POINT p;
	while(1) {
		HDC hdc = GetDC(NULL);
		GetCursorPos(&p);
//		cout<<p.x<<" "<<p.y<<endl;
		COLORREF pixel = GetPixel(hdc, p.x, p.y);
		int r = GetRValue(pixel);
		int g = GetGValue(pixel); 
		int b = GetBValue(pixel);
		cout<<p.x<<" "<<p.y<<" "<<r<<" "<<g<<" "<<b<<endl;
		::ReleaseDC(NULL, hdc); //释放屏幕DC
		Sleep(1000);
	}
	
	return 0;
}
