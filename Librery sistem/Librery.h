#pragma once
#include "Reader.h"
#include "Book.h"
#include <vector>
class Librery
{
private:
	std::vector<Reader>reader;
	std::vector<Book>book;
	int next_id_Book=1,next_id_Reader=1;
public:
	void cout_all_book();
	void new_book();
	void delete_book();
	void find_book();
	void cout_all_reader();
	void new_reader();
	void delete_reader();
	void find_reader();
	void give_book();
	//void get_book();
	//void cout_all_issued_book();
	//void save_data();
	//void load_data();
};