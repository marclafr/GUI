#ifndef __UI_BUTTON_H__
#define __UI_BUTTON_H__

#include "UI_Image.h"
#include "UI_Text.h"

class UI_Button : public UI_Element
{
private:
	UI_Image* img_idle;
	UI_Image* img_mouse_on_top;
	UI_Image* img_clicking;
	UI_Text* text;
};

#endif //__UI_BUTTON_H__