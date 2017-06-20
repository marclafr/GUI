#ifndef __UI_IMAGE_H__
#define __UI_IMAGE_H__

#include "j1Gui.h"

class UI_Image : public UI_Element
{
public:
	UI_Image(iPoint pos, SDL_Rect atlas_rect);
	~UI_Image();
private:
	bool Draw(SDL_Texture* atlas);

};

#endif //__UI_IMAGE_H__