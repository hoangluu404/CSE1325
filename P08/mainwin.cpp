#include "mainwin.h"
#include "entrydialog.h"
#include <string>
Mainwin::Mainwin() : Mainwin{*(new Shelter)} { }
Mainwin::Mainwin(Shelter& shelter): _shelter{&shelter}  {

    // /////////////////
    // G U I   S E T U P
    // /////////////////
	set_default_size(400,100);
	set_title("Main win");
    // Set up a vertical box to hold the main window elements
	Gtk::Box* vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0));
	add(*vbox);

    // ///////
    // M E N U
    // Add and configure a menu bar as the top item in the vertical box
 	Gtk::MenuBar* menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK,0);


	//FILE SUBMENU
	Gtk::MenuItem* item_file = Gtk::manage(new Gtk::MenuItem("_File",true));
	menubar->append(*item_file);
	Gtk::Menu *file_menu = Gtk::manage(new Gtk::Menu());
	item_file->set_submenu(*file_menu);

//	Gtk::MenuItem* item_new = Gtk::manage(new Gtk::MenuItem("_New Store", true));
//	item_new->signal_activate().connect([this]{this->on_new_store_click();});
//	file_menu->append(*item_new);

	Gtk::MenuItem* item_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	item_quit->signal_activate().connect([this]{this->on_quit_click();});
	file_menu->append(*item_quit);

	//ANIMAL SUBMENU
	Gtk::MenuItem* item_animal = Gtk::manage(new Gtk::MenuItem("_Animal",true));
	menubar->append(*item_animal);
	Gtk::Menu *animal_menu = Gtk::manage(new Gtk::Menu());
	item_animal->set_submenu(*animal_menu);

	Gtk::MenuItem* item_new_animal = Gtk::manage(new Gtk::MenuItem("_Add Animal", true));
	item_new_animal->signal_activate().connect([this]{this->on_new_animal_click();});
	animal_menu->append(*item_new_animal);

	Gtk::MenuItem* item_list_animals = Gtk::manage(new Gtk::MenuItem("_List Animals", true));
	item_list_animals->signal_activate().connect([this]{this->on_list_animals_click();});
	animal_menu->append(*item_list_animals);	

	//HELP SUBMENU
	Gtk::MenuItem* item_help = Gtk::manage(new Gtk::MenuItem("_Help",true));
	menubar->append(*item_help);
	Gtk::Menu *help_menu = Gtk::manage(new Gtk::Menu());
	item_help->set_submenu(*help_menu);

//	Gtk::MenuItem* item_about = Gtk::manage(new Gtk::MenuItem("_About", true));
//	item_about->signal_activate().connect([this]{this->on_about_click();});
//	help_menu->append(*item_about);	

	


	
	


    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box just below the menu (bonus level)
	Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
	vbox->add(*toolbar);

	Gtk::ToolButton *new_animal_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
	new_animal_button->set_tooltip_markup("add new animal");
	new_animal_button->signal_clicked().connect([this]{this->on_new_animal_click();});
	toolbar->append(*new_animal_button);

	Gtk::ToolButton *list_animals_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
	list_animals_button->set_tooltip_markup("list animals");
	list_animals_button->signal_clicked().connect([this]{this->on_list_animals_click();});
	toolbar->append(*list_animals_button);

	Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
	quit_button->set_tooltip_markup("quit");
	quit_button->signal_clicked().connect([this]{this->on_quit_click();});
	toolbar->append(*quit_button);






	


    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders
	Gtk::Label* data = Gtk::manage(new Gtk::Label("JUST A LABEL"));
	vbox->add(*data);

	


    // ///////////////////////////////////    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages
	Gtk::Label* status = Gtk::manage(new Gtk::Label("status bar"));
	Gtk::Label* status2 = Gtk::manage(new Gtk::Label("-------------------------------"));
	status->set_hexpand(true);
	status2->set_hexpand(true);
	vbox->add(*status2);
	vbox->add(*status);
    // Make the vertical box and everything in it visible
	vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////
	void Mainwin::on_new_animal_click(){
	Gtk::MessageDialog dialog(*this,"adding new animal");
	dialog.run();
	}

	void Mainwin::on_list_animals_click(){
	Gtk::MessageDialog dialog(*this,"listing animals");
	dialog.run();
	}

	void Mainwin::on_quit_click(){	std::exit(0);	}


// /////////////////
// U T I L I T I E S
// /////////////////


