#include "stdafx.h"

class DeviceContextManager
{


public:
	HWND hwnd;
	PAINTSTRUCT ps;
	HDC front_hdc;
	HDC back_hdc;
	HBITMAP back_bitmap;
	HBITMAP old_bitmap;

	void setHDC(HDC hdc, HWND h_wnd, PAINTSTRUCT paintstruct)
	{
		if(hdc != front_hdc)
		{
			
			front_hdc = hdc;
			hwnd = h_wnd;
			ps = paintstruct;
			deallocBackBuffer();
			allocBackBuffer();
		}
	}

	void allocBackBuffer()
	{

		RECT rect;
		GetClientRect(hwnd, &rect);

		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;

		back_hdc = CreateCompatibleDC(front_hdc);
		back_bitmap = CreateCompatibleBitmap(front_hdc, width, height);
		old_bitmap = (HBITMAP)SelectObject(back_hdc, back_bitmap);

	}

	void deallocBackBuffer()
	{
		if(back_hdc)
		{
			SelectObject(back_hdc, old_bitmap);
			DeleteObject(back_bitmap);
			DeleteDC(back_hdc);
		}
	}
};