#include "stdafx.h"
#include "PongView.h"
#include "DeviceContextManager.h"


PongView::PongView(void)
{
}


PongView::~PongView(void)
{
}

void PongView::paint(bool primary, RECT * playerOne, RECT * playerTwo, RECT * ball, int playerOneScore, int playerTwoScore)
{
	extern DeviceContextManager dcManager;

	RECT rect;
	GetClientRect(dcManager.hwnd, &rect);

	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	RECT windowArea = {width*0.01, height*0.2, width - width*0.01, height - height*0.01};
	RECT scoreBoardArea = {width*0.01, height*0.01, width - width*0.01, windowArea.top - height*0.01};

	FillRect(dcManager.back_hdc, &rect, (HBRUSH) GetStockObject(BLACK_BRUSH));
	paintScoreBoard(&scoreBoardArea, playerOneScore, playerTwoScore);
	paintPlayAreaInRect(playerOne, playerTwo, ball, &windowArea);

	if(primary)
		BitBlt(dcManager.front_hdc, 0, 0, width, height, dcManager.back_hdc, 0, 0, SRCCOPY);
}


void PongView::paintPlayAreaInRect(RECT * playerOne, RECT * playerTwo, RECT * ball, RECT * gameAreaView)
{	
	extern DeviceContextManager dcManager;
	extern RECT gameArea;
	RECT gameAreaCopy;
	RectFunctions::copy(&gameArea, &gameAreaCopy);
	
	int width = gameAreaView->right - gameAreaView->left;
	int height = gameAreaView->bottom - gameAreaView->top;

	float scaleFactor = (float)width/(float)gameArea.right;

	RectFunctions::scale(playerOne, scaleFactor);
	RectFunctions::scale(playerTwo, scaleFactor);
	RectFunctions::scale(ball, scaleFactor);
	RectFunctions::scale(&gameAreaCopy, scaleFactor);

	RectFunctions::translate(playerOne, gameAreaView->left, gameAreaView->top);
	RectFunctions::translate(playerTwo, gameAreaView->left, gameAreaView->top);
	RectFunctions::translate(ball, gameAreaView->left, gameAreaView->top);
	RectFunctions::translate(&gameAreaCopy, gameAreaView->left, gameAreaView->top);

	HPEN whitePen = CreatePen(PS_SOLID, 1, RGB(255,255,255));
	HPEN oldPen = (HPEN)SelectObject(dcManager.back_hdc, whitePen);

	//FillRect(dcManager.back_hdc, &gameAreaCopy, (HBRUSH) GetStockObject(BLACK_BRUSH));
	MoveToEx(dcManager.back_hdc, gameAreaCopy.left, gameAreaCopy.top, NULL);
	LineTo(dcManager.back_hdc, gameAreaCopy.right, gameAreaCopy.top);
	LineTo(dcManager.back_hdc, gameAreaCopy.right, gameAreaCopy.bottom);
	LineTo(dcManager.back_hdc, gameAreaCopy.left, gameAreaCopy.bottom);
	LineTo(dcManager.back_hdc, gameAreaCopy.left, gameAreaCopy.top);
	
	//RECT ballBlur = {ball->left - (ball->right - ball->left)/8, ball->top, ball->right + (ball->right - ball->left)/8, ball->bottom};
	//FillRect(dcManager.back_hdc, &ballBlur, CreateSolidBrush(RGB(127,127,127)) );
	FillRect(dcManager.back_hdc, ball, (HBRUSH)GetStockObject(WHITE_BRUSH));

	FillRect(dcManager.back_hdc, playerOne, (HBRUSH)GetStockObject(WHITE_BRUSH));
	FillRect(dcManager.back_hdc, playerTwo, (HBRUSH)GetStockObject(WHITE_BRUSH));
	
	SelectObject(dcManager.back_hdc, oldPen);
	DeleteObject(whitePen);
	//BitBlt(dcManager.front_hdc, gameAreaView->top, gameAreaView->left, width, height, dcManager.back_hdc, 0, 0, SRCCOPY);
}

void PongView::paintScoreBoard(RECT * scoreBoardArea, int playerOneScore, int playerTwoScore)
{
	extern DeviceContextManager dcManager;

	SetTextColor(dcManager.back_hdc, RGB(255,255,255));
	SetBkColor(dcManager.back_hdc, RGB(0,0,0));

	int width = scoreBoardArea->right - scoreBoardArea->left;
	int height = scoreBoardArea->bottom - scoreBoardArea->top;

	RECT textArea1 = {scoreBoardArea->left + width* 0.02, height/2 - 10, width/2 - width*0.02, height/2 + 10};
	RECT textArea2 = {width/2 + width* 0.02, height/2 - 10, scoreBoardArea->right - width*0.02, height/2 + 10};

	TCHAR score1[27];
	TCHAR score2[27];

	_stprintf_s(score1, sizeof(score1)/sizeof(TCHAR), _T( "Player 1 Score: %d "), playerOneScore);
	_stprintf_s(score2, sizeof(score2)/sizeof(TCHAR), _T( "Player 2 Score: %d "), playerTwoScore);
	
	DrawText(dcManager.back_hdc, score1, -1, &textArea1, DT_CENTER);
	DrawText(dcManager.back_hdc, score2, -1, &textArea2, DT_CENTER);

}