#ifndef MAINWIN_H
#define MAINWIN_H
#include<iostream>
#include <gtkmm.h>
#include "shelter.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        Mainwin(Shelter& shelter);
        virtual ~Mainwin();

    private:
        Shelter* _shelter;
	Gtk::MenuItem* menuitem_add_sweet;
	Gtk::MenuItem* menuitem_list_sweets;
	Gtk::MenuItem* menuitem_place_order;
	Gtk::MenuItem* menuitem_list_orders;


	Gtk::ToolButton* new_animal_button;
	Gtk::ToolButton* list_animals_button;
	Gtk::ToolButton* quit_button;

	Gtk::Label* data;
	Gtk::Label* msg;

    protected:
	void on_new_animal_click();
	void on_list_animals_click();
	void on_quit_click();

    // Lots more Mainwin members are needed!
    // (You ARE permitted to change the above as well if you like.)
};
#endif 

