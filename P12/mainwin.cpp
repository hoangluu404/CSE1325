#include "mainwin.h"
#include "dog.h"
#include "cat.h"
#include "rabbit.h"
#include "client.h"
#include <sstream>

Mainwin::Mainwin() : shelter{new Shelter{"Mavs Animal Shelter"}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 600);
    set_title(APP_TITLE);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         NEW SHELTER
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_new_shelter = Gtk::manage(new Gtk::MenuItem("_New Shelter", true));
    menuitem_new_shelter->signal_activate().connect([this] {this->on_new_shelter_click();});
    filemenu->append(*menuitem_new_shelter);

    //         SAVE
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    //         SAVE AS
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_saveas = Gtk::manage(new Gtk::MenuItem("_Save as", true));
    menuitem_saveas->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_saveas);

    //         LOAD
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load", true));
    menuitem_load->signal_activate().connect([this] {this->on_load_click();});
    filemenu->append(*menuitem_load);

    //         OPEN FILE
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open ->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open );

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     A N I M A L
    // Create an Animal menu and add to the menu bar
    Gtk::MenuItem *menuitem_animal = Gtk::manage(new Gtk::MenuItem("_Animal", true));
    menubar->append(*menuitem_animal);
    Gtk::Menu *animalmenu = Gtk::manage(new Gtk::Menu());
    menuitem_animal->set_submenu(*animalmenu);

    //           N E W
    // Append New to the Animal menu
    Gtk::MenuItem *menuitem_newanimal = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_newanimal->signal_activate().connect([this] {this->on_new_animal_click();});
    animalmenu->append(*menuitem_newanimal);

    //           L I S T
    // Append List to the Animal menu
    Gtk::MenuItem *menuitem_listanimal = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_listanimal->signal_activate().connect([this] {this->on_list_animals_click();});
    animalmenu->append(*menuitem_listanimal);

    //           LIST ADOPT
    // List Clients to main display
    Gtk::MenuItem *menuitem_listadopted_animal = Gtk::manage(new Gtk::MenuItem("_List Adopted", true));
    menuitem_listadopted_animal->signal_activate().connect([this] {this->on_list_adopted_click();});
    animalmenu->append(*menuitem_listadopted_animal);


    //     C L I E N T
    // Create a Client menu and add to the menu bar
    Gtk::MenuItem *menuitem_client = Gtk::manage(new Gtk::MenuItem("_Client", true));
    menubar->append(*menuitem_client);
    Gtk::Menu *clientmenu = Gtk::manage(new Gtk::Menu());
    menuitem_client->set_submenu(*clientmenu);

    //           N E W
    // Append New to the Client menu
    Gtk::MenuItem *menuitem_newclient = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_newclient->signal_activate().connect([this] {this->on_new_client_click();});
    clientmenu->append(*menuitem_newclient);

    //           LIST
    // List Clients to main display
    Gtk::MenuItem *menuitem_listclients = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_listclients->signal_activate().connect([this] {this->on_list_clients_click();});
    clientmenu->append(*menuitem_listclients);

    //           ADOPT
    // Append New to the Client menu
    Gtk::MenuItem *menuitem_adopt = Gtk::manage(new Gtk::MenuItem("_Adopt", true));
    menuitem_adopt->signal_activate().connect([this] {this->on_adopt_animal_click();});
    clientmenu->append(*menuitem_adopt);

    //           LIST ADOPT
    // List Clients to main display
    Gtk::MenuItem *menuitem_listadopted = Gtk::manage(new Gtk::MenuItem("_List Adopted", true));
    menuitem_listadopted->signal_activate().connect([this] {this->on_list_adopted_click();});
    clientmenu->append(*menuitem_listadopted);

    //     HELP
    // Create a Client menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           ABOUT
    // Append New to the Client menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    toolbar->override_background_color(Gdk::RGBA{"gray"});
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

	Gtk::ToolButton *new_animal_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
	new_animal_button->set_tooltip_markup("new animal");
	new_animal_button->signal_clicked().connect([this]{this->on_new_animal_click();});
	toolbar->append(*new_animal_button);

	Gtk::ToolButton *list_animals_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SELECT_ALL));
	list_animals_button->set_tooltip_markup("list animals");
	list_animals_button->signal_clicked().connect([this]{this->on_list_animals_click();});
	toolbar->append(*list_animals_button);

	Gtk::ToolButton *new_client_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
	new_client_button->set_tooltip_markup("new client");
	new_client_button->signal_clicked().connect([this]{this->on_new_client_click();});
	toolbar->append(*new_client_button);

	Gtk::ToolButton *list_clients_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SELECT_ALL));
	list_clients_button->set_tooltip_markup("list clients");
	list_clients_button->signal_clicked().connect([this]{this->on_list_clients_click();});
	toolbar->append(*list_clients_button);

	Gtk::ToolButton *adopt_animal_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::FIND_AND_REPLACE));
	adopt_animal_button->set_tooltip_markup("adopt animal");
	adopt_animal_button->signal_clicked().connect([this]{this->on_adopt_animal_click();});
	toolbar->append(*adopt_animal_button);

	Gtk::ToolButton *list_adopted_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SELECT_ALL));
	list_adopted_button->set_tooltip_markup("list adopted");
	list_adopted_button->signal_clicked().connect([this]{this->on_list_adopted_click();});
	toolbar->append(*list_adopted_button);

	Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::CLOSE));
	quit_button->set_tooltip_markup("quit");
	quit_button->signal_clicked().connect([this]{this->on_quit_click();});
	toolbar->append(*quit_button);

    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the remaining data
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->pack_start(*data, Gtk::PACK_EXPAND_WIDGET, 0);

    // ///////////////////////////////////
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for program messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    msg->override_background_color(Gdk::RGBA{"gray"});
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_new_animal_click() {
    Gtk::Dialog dialog{"NEW", *this};
    Gtk::Grid grid;
    Gtk::Label l_type{"Type"};
    Gtk::ComboBoxText type;
    type.append("Dog");
    type.append("Cat");
    type.append("Rabbit");
    type.set_active(0);
    grid.attach(l_type,0,0,1,1);
    grid.attach(type,1,0,2,1);
    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 1, 1, 1);
    grid.attach(e_name, 1, 1, 2, 1);
    Gtk::Label l_breed{"Breed"};
    Gtk::ComboBoxText dog_breed;
    for(auto b : dog_breeds) dog_breed.append(to_string(b));
    dog_breed.set_active(0);
    grid.attach(l_breed,0,2,1,1);
    grid.attach(dog_breed, 1, 2, 2, 1);
    Gtk::ComboBoxText cat_breed;
    for(auto b : cat_breeds) cat_breed.append(to_string(b));
    cat_breed.set_active(0);
    grid.attach(cat_breed, 1, 2, 2, 1);
    Gtk::ComboBoxText rabbit_breed;
    for(auto b : rabbit_breeds) rabbit_breed.append(to_string(b));
    rabbit_breed.set_active(0);
    grid.attach(rabbit_breed, 1, 2, 2, 1);
    Gtk::Label l_gender{"Gender"};
    Gtk::ComboBoxText c_gender;
    c_gender.append("Female");
    c_gender.append("Male");
    c_gender.set_active(0);
    grid.attach(l_gender, 0, 3, 1, 1);
    grid.attach(c_gender, 1, 3, 2, 1);
    Gtk::Label l_age{"Age"};
    Gtk::SpinButton s_age;
    s_age.set_range(0,99);
    s_age.set_increments(1,5);
    s_age.set_value(5);
    grid.attach(l_age, 0, 4, 1, 1);
    grid.attach(s_age, 1, 4, 2, 1);
    dialog.get_content_area()->add(grid);
    dialog.add_button("Add Animal", 1);
    dialog.add_button("Cancel", 0);
    dialog.show_all();
	l_name.hide();
	e_name.hide();
	l_breed.hide();
	dog_breed.hide();
	cat_breed.hide();
	rabbit_breed.hide();
	l_gender.hide();
	c_gender.hide();
	l_age.hide();
	s_age.hide();
    while(dialog.run()) {
      if(type.get_active_row_number()==0){
	dialog.show_all();
	type.hide();
	l_type.hide();
	cat_breed.hide();
	rabbit_breed.hide();
        if(e_name.get_text().size() == 0) {e_name.set_text("Dog Name"); continue;}
        Animal* animal = new Dog{dog_breeds[dog_breed.get_active_row_number()], 
                                 e_name.get_text(),
                                 (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                                 static_cast<int>(s_age.get_value())};shelter->add_animal(*animal);
	std::ostringstream oss;
        oss << "Added Dog" << *animal;
        status(oss.str());
	}
      if(type.get_active_row_number()==1){
	dialog.show_all();
	type.hide();
	l_type.hide();
	dog_breed.hide();
	rabbit_breed.hide();
        if(e_name.get_text().size() == 0) {e_name.set_text("Cat Name"); continue;}
        Animal* animal = new Cat{cat_breeds[cat_breed.get_active_row_number()], 
                                 e_name.get_text(),
                                 (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                                 static_cast<int>(s_age.get_value())};shelter->add_animal(*animal);
	std::ostringstream oss;
        oss << "Added Cat" << *animal;
        status(oss.str());
	}
      if(type.get_active_row_number()==2){
	dialog.show_all();
	type.hide();
	l_type.hide();
	cat_breed.hide();
	dog_breed.hide();
        if(e_name.get_text().size() == 0) {e_name.set_text("Rabbit Name"); continue;}
        Animal* animal = new Rabbit{rabbit_breeds[rabbit_breed.get_active_row_number()], 
                                 e_name.get_text(),
                                 (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                                 static_cast<int>(s_age.get_value())};shelter->add_animal(*animal);
        std::ostringstream oss;
        oss << "Added Rabbit" << *animal;
        status(oss.str());
	}
        break;
    }
 on_list_animals_click();
}

void Mainwin::on_list_animals_click() {
if(shelter->num_animals()){
    std::ostringstream oss;
    for(int i=0; i<shelter->num_animals(); ++i)
        oss << shelter->animal(i) << '\n'; 
    data->set_text(oss.str());
    status("");
}
else{
std::ostringstream oss;    
    oss <<"NO ANIMALS FOUND";
    data->set_text(oss.str());
    status("");
}
}      // List all animals
void Mainwin::on_new_client_click() {
    Gtk::Dialog dialog{"NEW", *this};
    Gtk::Grid grid;
    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);
    Gtk::Label l_phone{"Phone"};
    Gtk::Entry e_phone;
    grid.attach(l_phone, 0, 1, 1, 1);
    grid.attach(e_phone, 1, 1, 2, 1);
    Gtk::Label l_email{"Email"};
    Gtk::Entry e_email;
    grid.attach(l_email, 0, 2, 1, 1);
    grid.attach(e_email, 1, 2, 2, 1);
    dialog.get_content_area()->add(grid);
    dialog.add_button("Add Client", 1);
    dialog.add_button("Cancel", 0);
    dialog.show_all();
    if(dialog.run()) {
        if (e_name.get_text().size() == 0) {
	 	std::ostringstream oss;    
   	 	oss <<"NOT ENOUGH INFORMATION";
   	 	data->set_text(oss.str());
   	 	status("");
		return;
	}
        if (e_phone.get_text().size() == 0) {
	 	std::ostringstream oss;    
   	 	oss <<"NOT ENOUGH INFORMATION";
   	 	data->set_text(oss.str());
   	 	status("");
		return;
	}
        if (e_email.get_text().size() == 0) {
	 	std::ostringstream oss;    
   	 	oss <<"NOT ENOUGH INFORMATION";
   	 	data->set_text(oss.str());
   	 	status("");
		return;
	}
        shelter->add_client(*(new Client{e_name.get_text(), e_phone.get_text(), e_email.get_text()}));
    }

on_list_clients_click();
}
void Mainwin::on_list_clients_click(){
if(shelter->num_clients()>0){
std::ostringstream oss;
    for(int i=0; i<shelter->num_clients(); ++i)
        oss << shelter->client(i) << '\n'; 
    data->set_text(oss.str());
    status("");
}else{
std::ostringstream oss;    
    oss <<"NO CLIENTS FOUND";
    data->set_text(oss.str());
    status("");
}
}

void Mainwin::on_adopt_animal_click(){
      Gtk::Dialog dialog{"ADOPTION", *this};

    Gtk::Grid grid;

if(shelter->num_clients()>0 && shelter->num_animals()>0){
    Gtk::Label l_clients{"Client"};
    Gtk::ComboBoxText c_clients;
	for(int i=0;i<shelter->num_clients();i++){
		c_clients.append(shelter->client_name(shelter->client(i)));
	}
    c_clients.set_active(0);
    grid.attach(l_clients, 0, 3, 1, 1);
    grid.attach(c_clients, 1, 3, 2, 1);
    Gtk::Label l_animals{"Animal"};
    Gtk::ComboBoxText c_animals;
	for(int i=0;i<shelter->num_animals();i++){
		c_animals.append(shelter->animal_name(shelter->animal(i)));	}
    c_animals.set_active(0);
    grid.attach(l_animals, 0, 4, 1, 1);
    grid.attach(c_animals, 1, 4, 2, 1);
    dialog.get_content_area()->add(grid);
    dialog.add_button("Adopt", 1);
    dialog.add_button("Cancel", 0);
    dialog.show_all(); 
    if(dialog.run()) {
	std::ostringstream oss;
        oss <<"ANIMAL ADOPTED";
    	data->set_text(oss.str());
  	status("");
	shelter->adopt(shelter->client(c_clients.get_active_row_number()),  shelter->animal(c_animals.get_active_row_number()));
	shelter->delete_animal(c_animals.get_active_row_number());
    }else{
	std::ostringstream oss;
        oss <<"ADOPTION CANCELLED";
    	data->set_text(oss.str());
  	status("");
	}
}else if(shelter->num_animals()<=0 && shelter->num_clients()<=0){
std::ostringstream oss;    
    oss <<"NO CLIENTS AND ANIMALS FOUND";
    data->set_text(oss.str());
    status("");
}
else if(shelter->num_clients()<=0){
std::ostringstream oss;    
    oss <<"NO CLIENTS FOUND";
    data->set_text(oss.str());
    status("");
}
else if(shelter->num_animals()<=0){
std::ostringstream oss;    
    oss <<"NO ANIMALS FOUND";
    data->set_text(oss.str());
    status("");
}
}

void Mainwin::on_list_adopted_click(){
     Gtk::Dialog dialog{"SELECT CLIENT", *this};
    Gtk::Grid grid;
if(shelter->num_clients()>0){
    Gtk::Label l_clients{"Client"};
    Gtk::ComboBoxText c_clients;
	for(int i=0;i<shelter->num_clients();i++){
		c_clients.append(shelter->client_name(shelter->client(i)));
	}
    c_clients.set_active(0);
    grid.attach(l_clients, 0, 3, 1, 1);
    grid.attach(c_clients, 1, 3, 2, 1);
    dialog.get_content_area()->add(grid);
    dialog.add_button("Show", 1);
    dialog.add_button("Cancel", 0);
    dialog.show_all();
    if(dialog.run()) {
	std::ostringstream oss;
        oss <<"CLIENT: " <<    shelter->client_name(shelter->client(c_clients.get_active_row_number())) <<"\n";
	for(int i=0   ; i   <   shelter->client(c_clients.get_active_row_number()).num_adopted()    ;i++){
		oss<< (i+1) << ". " << shelter->client(c_clients.get_active_row_number()).animal(i) <<"\n" ;
	}
    	data->set_text(oss.str());
  	status("");
	if(shelter->client(c_clients.get_active_row_number()).num_adopted()<=0){

	  std::ostringstream oss;
  	  oss <<"THIS CLIENT HAS NOT ADOPTED ANY ANIMALS";
 	  data->set_text(oss.str());
  	  status("");
	}
    }
}
else if(shelter->num_clients()<=0){
std::ostringstream oss;
    
    oss <<"NO CLIENTS FOUND";
    data->set_text(oss.str());
    status("");
}
}

	void Mainwin::on_new_shelter_click(){
		free(shelter);
		shelter = new Shelter("SHELTER");
		std::ostringstream oss;
  	 	oss <<"NEW SHELTER CREATED";
 	  	data->set_text(oss.str());
  	 	status("");

	}
	void Mainwin::on_save_click(){
		shelter->save();
		std::ostringstream oss;
  	 	oss <<"SHELTER SAVED";
 	  	data->set_text(oss.str());
  	 	status("");
  	  	status("default.mass");		

	}
	void Mainwin::on_save_as_click(){}

	void Mainwin::on_load_click(){
		free(shelter);
		shelter={new Shelter{shelter->load()}};
		std::ostringstream oss;
  	 	oss <<"LOADED SHELTER";
 	  	data->set_text(oss.str());
  	 	status("");
  	 	status("default.mass");
	}

	void Mainwin::on_open_click(){}

	void Mainwin::on_about_click(){}

// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::status(std::string s) {
    msg->set_text(s);
}
