#include "stdafx.h"
#include "RectFunctions.h"

void RectFunctions::translate(RECT * object, int x, int y)
{
	object->left += x;
	object->top += y;
	object->right += x;
	object->bottom += y;
	
}

void RectFunctions::scale(RECT * object, float scale)
{
	object->left *= scale;
	object->top *= scale;
	object->right *= scale;
	object->bottom *= scale;
}

void RectFunctions::copy(RECT * copyFrom, RECT * copyTo)
{
	copyTo->left = copyFrom->left;
	copyTo->top = copyFrom->top;
	copyTo->right = copyFrom->right;
	copyTo->bottom = copyFrom->bottom;
}