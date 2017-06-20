#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"

//UI_ELEMENTS
#include "UI_AppearingLabel.h"
#include "UI_Button.h"
#include "UI_HPBar.h"
#include "UI_Image.h"
#include "UI_Label.h"
#include "UI_Text.h"
//----------

j1Gui::j1Gui() : j1Module()
{
	name.assign("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.c_str());

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	for (int i = 0; i < ui_elements.size(); i++)
		ui_elements[i]->Draw(atlas);

	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	return true;
}

UI_Image * j1Gui::CreateImage(iPoint pos, SDL_Rect atlas_rect)
{
	UI_Image* ret = nullptr;
	ret = new UI_Image(pos, atlas_rect);
	ui_elements.push_back(ret);
	return ret;
}

// const getter for atlas
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

// class Gui ---------------------------------------------------

UI_Element::UI_Element(iPoint pos, SDL_Rect atlas_rect) : pos(pos), atlas_rect(atlas_rect)
{
}

UI_Element::~UI_Element()
{
}

bool UI_Element::Update()
{
	return true;
}

bool UI_Element::Draw(SDL_Texture* atlas)
{
	return true;
}
