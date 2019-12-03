#ifndef __FILE_CHOOSER_H
#define __FILE_CHOOSER_H

#include<gtkmm.h>

class Filechooser: public Gtk::Window{

  public:
	Filechooser();
	virtual ~Filechooser();

  protected:
	void on_button_file_clicked();
	void on_button_folder_clicked();
	Gtk::ButtonBox button_box;
	Gtk::Button file_button, folder_button;

};

#endif
