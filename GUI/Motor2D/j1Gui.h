#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "SDL\include\SDL.h"
#include <vector>
#include "j1Module.h"
#include "p2Point.h"

#define CURSOR_WIDTH 2

	 //----------------||------------------||----------------\\
	//----------------||         UI         ||----------------\\
   //----------------||______________________||----------------\\

class UI_Image;
class UI_Text;
class UI_Label;
class UI_Button;
class UI_AppearingLabel;
class UI_HPBar;

class UI_Element
{
protected:
	UI_Element(iPoint pos, SDL_Rect atlas_rect);
	~UI_Element();

	iPoint pos;
	SDL_Rect atlas_rect;

public:
	virtual bool Update();
	virtual bool Draw(SDL_Texture* atlas);
	//bool HandleInput()?????
};

// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// Gui creation functions
	UI_Image* CreateImage(iPoint pos, SDL_Rect atlas_rect);
	//-----------------------

	const SDL_Texture* GetAtlas() const;

private:

	SDL_Texture* atlas;
	std::string atlas_file_name;

	std::vector<UI_Element*> ui_elements;

};

//	\\----------------||______________________||----------------//
//	  \\----------------||__________________||----------------//
//		\\----------------||--------------||----------------//

#endif // __j1GUI_H__