#pragma once
#include "stdafx.h"
#include "RectFunctions.h"

class DeviceContextManager
{


public:
	HWND hwnd;
	PAINTSTRUCT ps;
	HDC front_hdc;
	HDC back_hdc;
	HBITMAP back_bitmap;
	HBITMAP old_bitmap;
	RECT windowSize;

	DeviceContextManager(void)
	{
		windowSize.right = 0;
		windowSize.bottom = 0;
	}

	void setHDC(HDC hdc, HWND h_wnd, PAINTSTRUCT paintstruct)
	{
		RECT newWindowSize;
		GetClientRect(h_wnd, &newWindowSize);
		if(hdc != front_hdc || newWindowSize.right != windowSize.right || newWindowSize.bottom != windowSize.bottom)
		{
			
			front_hdc = hdc;
			hwnd = h_wnd;
			ps = paintstruct;
			deallocBackBuffer();
			allocBackBuffer();
			RectFunctions::copy(&newWindowSize, &windowSize);
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