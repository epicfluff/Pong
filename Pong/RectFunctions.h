#pragma once

class RectFunctions
{
public:
	RectFunctions(void);
	~RectFunctions(void);

	static void translate(RECT * rect, int xTranslation, int yTranslation);
	static void scale(RECT * object, float scale);
	static void copy(RECT * copyFrom, RECT * copyTo);
};



