#include "mainwin.h"

int main (int argc, char *argv[]) {
  // Your main function code goes here!
	auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.example");
	
	Mainwin win;
	return app->run(win);
}

