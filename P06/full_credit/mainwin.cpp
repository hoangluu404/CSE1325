#include "mainwin.h"
#include "entrydialog.h"
#include <string>
Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) : _store{&store} {

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

	Gtk::MenuItem* item_new = Gtk::manage(new Gtk::MenuItem("_New Store", true));
	item_new->signal_activate().connect([this]{this->on_new_store_click();});
	file_menu->append(*item_new);

	Gtk::MenuItem* item_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	item_quit->signal_activate().connect([this]{this->on_quit_click();});
	file_menu->append(*item_quit);

	//SWEETS SUBMENU
	Gtk::MenuItem* item_sweets = Gtk::manage(new Gtk::MenuItem("_Sweets",true));
	menubar->append(*item_sweets);
	Gtk::Menu *sweet_menu = Gtk::manage(new Gtk::Menu());
	item_sweets->set_submenu(*sweet_menu);

	Gtk::MenuItem* item_add_sweet = Gtk::manage(new Gtk::MenuItem("_Add Sweet", true));
	item_add_sweet->signal_activate().connect([this]{this->on_add_sweet_click();});
	sweet_menu->append(*item_add_sweet);

	Gtk::MenuItem* item_list_sweets = Gtk::manage(new Gtk::MenuItem("_List Sweets", true));
	item_list_sweets->signal_activate().connect([this]{this->on_list_sweets_click();});
	sweet_menu->append(*item_list_sweets);	

	//HELP SUBMENU
	Gtk::MenuItem* item_help = Gtk::manage(new Gtk::MenuItem("_Help",true));
	menubar->append(*item_help);
	Gtk::Menu *help_menu = Gtk::manage(new Gtk::Menu());
	item_help->set_submenu(*help_menu);

	Gtk::MenuItem* item_about = Gtk::manage(new Gtk::MenuItem("_About", true));
	item_about->signal_activate().connect([this]{this->on_about_click();});
	help_menu->append(*item_about);	

	



	
	


    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box just below the menu (bonus level)
	Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
	vbox->add(*toolbar);

	Gtk::ToolButton *new_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
	new_button->set_tooltip_markup("add new store");
	new_button->signal_clicked().connect([this]{this->on_new_store_click();});
	toolbar->append(*new_button);

	Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
	quit_button->set_tooltip_markup("quit");
	quit_button->signal_clicked().connect([this]{this->on_quit_click();});
	toolbar->append(*quit_button);

	Gtk::ToolButton *new_sweet_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
	new_sweet_button->set_tooltip_markup("add extra sweetness");
	new_sweet_button->signal_clicked().connect([this]{this->on_add_sweet_click();});
	toolbar->append(*new_sweet_button);

	Gtk::ToolButton *list_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
	list_button->set_tooltip_markup("list sweets");
	list_button->signal_clicked().connect([this]{this->on_list_sweets_click();});
	toolbar->append(*list_button);






	


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
	void Mainwin::on_new_store_click(){
	_store = new Store();
	Gtk::MessageDialog dialog(*this,"added new store");
	dialog.run();
	}

	void Mainwin::on_add_sweet_click(){
	EntryDialog name{*this, "name of sweet: "};
	name.run();
	EntryDialog price{*this, "price of sweet: "};
	price.run();
	std::string::size_type size;
	double item_price = std::stod(price.get_text(),&size);
	Gtk::MessageDialog dialog(*this,name.get_text() + " is " + price.get_text());
	dialog.run();
	Sweet sweet(name.get_text(),item_price);
	_store->add(sweet);
	}

	void Mainwin::on_list_sweets_click(){
	Gtk::MessageDialog dialog(*this,"listing sweets");
	dialog.run();
	}

	void Mainwin::on_place_order_click(){
	Gtk::MessageDialog dialog(*this,"place order");
	dialog.run();
	}

	void Mainwin::on_list_orders_click(){
	Gtk::MessageDialog dialog(*this,"listing orders");
	dialog.run();
	}

	void Mainwin::on_about_click(){
	Glib::ustring st = R"(<span size='24000' weight='bold'>Sweetness</span>
<span size='large'>Hoang Luu: 1000969998</span>
<span size='small'>Professor RICE: CSE1325 P05</span>
<span size='small'>icons are included in gtkmm libary</span>)";
	Gtk::MessageDialog dialog(*this, st, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
	dialog.run();
	}

	void Mainwin::on_quit_click(){	
	Gtk::MessageDialog dialog(*this,"EXIT");
	dialog.run();
	std::exit(0);	}


	void Mainwin::reset_sensitivity(){

	}


// /////////////////
// U T I L I T I E S
// /////////////////


