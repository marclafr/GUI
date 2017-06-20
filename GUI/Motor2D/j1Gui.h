#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include <vector>

#define CURSOR_WIDTH 2

	 //----------------||------------------||----------------\\
	//----------------||         UI         ||----------------\\
   //----------------||______________________||----------------\\

class UI_Element
{
protected:
	iPoint pos;
	SDL_Rect atlas_rect;
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

	// TODO 2: Create the factory methods
	// Gui creation functions

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