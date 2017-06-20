#include "j1App.h"
#include "j1Render.h"
#include "UI_Image.h"

UI_Image::UI_Image(iPoint pos, SDL_Rect atlas_rect) : UI_Element(pos, atlas_rect)
{
}

UI_Image::~UI_Image()
{
}

bool UI_Image::Draw(SDL_Texture* atlas)
{
	App->render->Blit(atlas, pos.x, pos.y, &atlas_rect);
	return true;
}
