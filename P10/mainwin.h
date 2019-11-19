#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "shelter.h"

const std::string APP_TITLE{"Mavs Animal Shelter Software"};
const std::string APP_NAME{"edu.uta.cse1325.mass.v0_1_0"};
const std::string VERSION{"0.1.0"};

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_quit_click();              // Exit the application
        void on_new_animal_click();        // Create a new animal
        void on_list_animals_click();      // List all animals
        void on_new_client_click();	  //Create a new client
	void on_list_clients_click();	//List clients
	void on_adopt_animal_click(); //adopt animal
	void on_list_adopted_click();//list adopted animals
        void status(std::string s);        // Set the status message

	void on_new_shelter_click();
	void on_save_click();
	void on_save_as_click();
	void on_load_click();
	void on_open_click();
	void on_about_click();




    private:
        Shelter *shelter;                  // Current animal shelter
        Gtk::Label *data;                  // Display of sticks on game board
        Gtk::Label *msg;                   // Status message display
};
#endif 

