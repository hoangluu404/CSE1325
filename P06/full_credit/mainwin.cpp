#include "mainwin.h"
#include "entrydialog.h"
#include <string>
Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) : _store{&store} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////
	set_default_size(640,480);
	set_title("Some kind of Sweets shop");
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

	//ADD ORDER SUBMENU
	Gtk::MenuItem* item_orders = Gtk::manage(new Gtk::MenuItem("_Orders",true));
	menubar->append(*item_orders);
	Gtk::Menu *orders_menu = Gtk::manage(new Gtk::Menu());
	item_orders->set_submenu(*orders_menu);

	Gtk::MenuItem* item_add_order = Gtk::manage(new Gtk::MenuItem("_Add Order", true));
	item_add_order->signal_activate().connect([this]{this->on_place_order_click();});
	orders_menu->append(*item_add_order);

	Gtk::MenuItem* item_list_orders = Gtk::manage(new Gtk::MenuItem("_List Orders", true));
	item_list_orders->signal_activate().connect([this]{this->on_list_orders_click();});
	orders_menu->append(*item_list_orders);	



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
	//NEW STORE BUTTON
	Gtk::ToolButton *new_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
	new_button->set_tooltip_markup("add new store");
	new_button->signal_clicked().connect([this]{this->on_new_store_click();});
	toolbar->append(*new_button);
	//QUIT BUTTON
	Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
	quit_button->set_tooltip_markup("quit");
	quit_button->signal_clicked().connect([this]{this->on_quit_click();});
	toolbar->append(*quit_button);
	//ADD SWEET BUTTON
	Gtk::ToolButton *new_sweet_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
	new_sweet_button->set_tooltip_markup("add extra sweetness");
	new_sweet_button->signal_clicked().connect([this]{this->on_add_sweet_click();});
	toolbar->append(*new_sweet_button);
	//LIST SWEETS BUTTON
	Gtk::ToolButton *list_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
	list_button->set_tooltip_markup("list sweets");
	list_button->signal_clicked().connect([this]{this->on_list_sweets_click();});
	toolbar->append(*list_button);
	//PLACE ORDER BUTTON
	Gtk::ToolButton *place_order_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
	place_order_button->set_tooltip_markup("place an order");
	place_order_button->signal_clicked().connect([this]{this->on_place_order_click();});
	toolbar->append(*place_order_button);
	//LIST ORDERS BUTTON
	Gtk::ToolButton *list_orders_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
	list_orders_button->set_tooltip_markup("list orders");
	list_orders_button->signal_clicked().connect([this]{this->on_list_orders_click();});
	toolbar->append(*list_orders_button);




	


    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders
//	Gtk::Label* data = Gtk::manage(new Gtk::Label("JUST A LABEL"));
//	vbox->add(*data);

 	data = Gtk::manage(new Gtk::Label());
	data->set_hexpand(true);
	data->set_vexpand(true);
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
	free(_store);
	_store = new Store();
	#ifdef __SENSITIVITY1
	    reset_sensitivity();
	#endif
	    data->set_text("");
	#ifdef __STATUSBAR
	    msg->set_text("New Mav's Ultimate Sweet Shop created");
	#endif
	Gtk::MessageDialog dialog(*this,"added new store");
	dialog.run();
	}
/*
	void Mainwin::on_add_sweet_click(){
	EntryDialog name{*this, "name of sweet: "};
	name.run();
	EntryDialog price{*this, "price of sweet: "};
	price.run();
}
*/

void Mainwin::on_add_sweet_click() {
    std::string name = "";
    double price = -1;
	#ifndef __SWEETSADDDLG
	    EntryDialog dialog{*this, "Name of new sweet?"};
	    dialog.run();
	    name = dialog.get_text();
	    if(name.size() == 0) {
	#ifdef __STATUSBAR
	        msg->set_text("New sweet cancelled");
	#endif
	        return;
	    }

	    std::string prompt = "Price?";
	    while (price < 0) {
	        EntryDialog dialog{*this, prompt};
	        dialog.run();
	        try {
	            price = std::stod(dialog.get_text());
	        } catch(std::exception e) {
 	           prompt = "Invalid Price! Price?";
	            price = -1;
	        }
	    }
  	#else
	    Gtk::Dialog *dialog = new Gtk::Dialog{"Create a Sweet", *this};
	    // Name
	    Gtk::HBox b_name;
	    Gtk::Label l_name{"Name:"};
	    l_name.set_width_chars(15);
	    b_name.pack_start(l_name, Gtk::PACK_SHRINK);
	    Gtk::Entry e_name;
	    e_name.set_max_length(50);
	    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);
	    // Price
	    Gtk::HBox b_price;
	    Gtk::Label l_price{"Price:"};
	    l_price.set_width_chars(15);
	    b_price.pack_start(l_price, Gtk::PACK_SHRINK);
 	    Gtk::Entry e_price;
 	    e_price.set_max_length(50);
	    b_price.pack_start(e_price, Gtk::PACK_SHRINK);
	    dialog->get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);
	    // Show dialog
	    dialog->add_button("Cancel", 0);
	    dialog->add_button("Create", 1);
	    dialog->show_all();
	    int result; // of the dialog (1 = OK)
	    bool fail = true;  // set to true if any data is invalid
	    while (fail) {
	        fail = false;  // optimist!
	        result = dialog->run();
	        if (result != 1) {
	#ifdef __STATUSBAR
	            msg->set_text("New sweet cancelled");
	#endif
	            delete dialog;
	            return;}
	       try {
	            price = std::stod(e_price.get_text());
 	       } catch(std::exception e) {
 	           e_price.set_text("### Invalid ###");
 	           fail = true;
	        }
	        name = e_name.get_text();
  	        if (name.size() == 0) {
 	           e_name.set_text("### Invalid ###");
 	           fail = true;
	        }
	    }
	    delete dialog;
	#endif
	    Sweet sweet{name, price};
	    _store->add(sweet);
	    on_list_sweets_click();
	#ifdef __STATUSBAR
	    msg->set_text("Added " + sweet.name());
	#endif
	
	#ifdef __SENSITIVITY1
	    reset_sensitivity();
	#endif
}
	void Mainwin::on_list_sweets_click(){
	//	Gtk::MessageDialog dialog(*this,"listing sweets");
	//	dialog.run();
	    if (_store->num_sweets() == 0) {
        data->set_markup("<span size='large' weight='bold'>No sweets have been defined yet</span>");
	#ifdef __STATUSBAR
 	       msg->set_text("");
	#endif
 	       return;
	    }
	    // The string manipulation way
	    std::string s = "<span size='large' weight='bold'>";
	    for(int i=0; i<_store->num_sweets(); ++i) 
	        s += _store->sweet(i).name() + "  $" + std::to_string(_store->sweet(i).price()) + "\n";
	    s += "</span>";
	    data->set_markup(s);
	#ifdef __STATUSBAR
	    msg->set_text("");
	#endif
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
	    menuitem_list_sweets->set_sensitive(_store->num_sweets() > 0);
	#ifdef __TOOLBAR
	    list_sweets_button->set_sensitive(_store->num_sweets() > 0);
	#endif
	}


// /////////////////
// U T I L I T I E S
// /////////////////


