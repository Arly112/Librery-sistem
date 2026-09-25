#include <iostream>
#include "Reader.h"
#include "Book.h"
#include "Librery.h"
#include "string"


void Librery::cout_all_book()
{
	for (auto w : book)
	{
			std::cout<< std::endl;
			std::cout << "ID: " << w.ID<<std::endl;
			std::cout << "Name: " << w.Name << std::endl;
			std::cout << "Author: " << w.Author << std::endl;
			std::cout << "Year publish: " << w.Year_publish << std::endl;

			if (w.open)
			{
				std::cout << "Availability: Available ";
			}
			
			else if (!w.open)
			{
				std::cout << "Availability: Not Available ";
			}
		std::cout << std::endl;
	}

	if (book.size() == 0)
	{
		std::cout << std::endl;
		std::cout << "Librery haven't books!!";
		std::cout << std::endl;
	}
}

void Librery::new_book()
{

	Book b;	

	std::cout << "What name the book? " << std::endl;
	std::cin.ignore(1000, '\n');
	std::getline(std::cin,b.Name);
	std::cout << "What author this book? " << std::endl;
	std::getline(std::cin, b.Author);
	std::cout << "What did year publish this book?" << std::endl;
	std::cin >> b.Year_publish;
	b.ID = next_id_Book;
	next_id_Book++;
	b.open = true;
	book.push_back(b);
}

void Librery::delete_book()
{
	int ID;
	std::cout << "The ID of the book do you want to delete: ";
	std::cin >> ID;
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].ID == ID)
		{
			book.erase(book.begin() + i);
		}
	}
}

void Librery::find_book()
{
	int vab;
	
	std::cout << "You wanted find by 1.Name or by 2.ID"<<std::endl;
	std::cin >> vab;
	if (vab == 1)
	{
		std::string Name;
		std::cin.ignore(1000, '\n');
		std::cout << "Write finded book:" << std::endl;
		std::getline(std::cin, Name);
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].Name == Name)
			{
				std::cout << std::endl;
				std::cout << "ID: " << book[i].ID << std::endl;
				std::cout << "Name: " << book[i].Name << std::endl;
				std::cout << "Author: " << book[i].Author << std::endl;
				std::cout << "Year publish: " << book[i].Year_publish << std::endl;
				
				if (book[i].open)
				{
					std::cout << "Availability: Available ";
				}

				else if (!book[i].open)
				{
					std::cout << "Availability: Not Available ";
				}
				std::cout << std::endl;
			}
		}
	}
	else if (vab == 2)
	{
		int ID;
		std::cin.ignore(1000, '\n');
		std::cout << "Write finded book:" << std::endl;
		std::cin >> ID;
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].ID == ID)
			{
				std::cout << std::endl;
				std::cout << "ID: " << book[i].ID << std::endl;
				std::cout << "Name: " << book[i].Name << std::endl;
				std::cout << "Author: " << book[i].Author << std::endl;
				std::cout << "Year publish: " << book[i].Year_publish << std::endl;

				if (book[i].open)
				{
					std::cout << "Availability: Available ";
				}

				else if (!book[i].open)
				{
					std::cout << "Availability: Not Available ";
				}
				std::cout << std::endl;
			}
		}
	}
}

void Librery::cout_all_reader()
{
	for (auto r : reader)
	{
		std::cout<<std::endl;
		std::cout << "ID: " << r.ID << std::endl;
		std::cout << "Name: " << r.Name << std::endl;
		std::cout << "Surname: " << r.Surname << std::endl;
		std::cout << "How match this reader take book: " << r.Count_reading_book << std::endl;
		std::cout<<std::endl;


		if (reader.size() == 0)
		{
			std::cout<<"Librery haven't readers!!" << std::endl;
		}
	}
}

void Librery::new_reader()
{
	Reader r;
	std::cout << std::endl;
	std::cout<<"Name new Reader: " << std::endl;
	std::cin.ignore(1000, '\n');
	std::getline(std::cin, r.Name);
	std::cout << "Surname new Reader: " << std::endl;
	std::getline(std::cin, r.Surname);
	r.ID = next_id_Reader;
	next_id_Reader++;
	r.Count_reading_book = 0;
	reader.push_back(r);
}

void Librery::delete_reader()
{
	int vab;
	std::cout << std::endl;
	std::cout << "You wanted delete by 1.Name and Surname , or by 2.ID" << std::endl;
	std::cin >> vab;
	if (vab == 1)
	{
		std::string Name,Surname;
		std::cin.ignore(1000, '\n');
		std::cout << "Write Name and Surname deleted reader:" << std::endl;
		std::getline(std::cin, Name);
		std::getline(std::cin, Surname);
		for (int i = 0; i < reader.size(); i++)
		{
			if (reader[i].Name == Name && reader[i].Surname== Surname&&reader[i].Count_reading_book==0)
			{
				reader.erase(reader.begin() + i);
			}
			else
			{
				std::cout << std::endl;
				std::cout << "Librery not have this reader in BaseData or this reader have not returned books" << std::endl;
			}
		}
	}
	else if (vab == 2)
	{
		int ID;
		std::cin.ignore(1000, '\n');
		std::cout << "Write ID deleted reader:" << std::endl;
		std::cin >> ID;
		for (int i = 0; i < reader.size(); i++)
		{
			if (reader[i].ID == ID&&reader[i].Count_reading_book==0)
			{
				reader.erase(reader.begin() + i);
			}
			else
			{
				std::cout << std::endl;
				std::cout << "Librery not have this reader in BaseData or this reader have not returned books" << std::endl;
			}
		}
	}
}

void Librery::find_reader()
{
	int vab;

	std::cout << "You wanted find by 1.Name and Surname or by 2.ID" << std::endl;
	std::cin >> vab;
	if (vab == 1)
	{
		std::string Name, Surname;
		std::cin.ignore(1000, '\n');
		std::cout << "Write Name and Surname find reader:" << std::endl;
		std::getline(std::cin, Name);
		std::getline(std::cin, Surname);
		for (int i = 0; i < reader.size(); i++)
		{
			if (reader[i].Name == Name && reader[i].Surname == Surname)
			{
				std::cout << std::endl;
				std::cout << "ID: " << reader[i].ID << std::endl;
				std::cout << "Name: " << reader[i].Name << std::endl;
				std::cout << "Surname: " << reader[i].Surname << std::endl;
				std::cout << "How match this reader take book: " << reader[i].Count_reading_book << std::endl;
				std::cout << std::endl;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "Librery not have this reader in BaseData" << std::endl;
			}
		}
	}
	else if (vab == 2)
	{
		int ID;
		std::cin.ignore(1000, '\n');
		std::cout << "Write finded reader:" << std::endl;
		std::cin >> ID;
		for (int i = 0; i < reader.size(); i++)
		{
			if (reader[i].ID)
			{
				std::cout << std::endl;
				std::cout << "ID: " << reader[i].ID << std::endl;
				std::cout << "Name: " << reader[i].Name << std::endl;
				std::cout << "Surname: " << reader[i].Surname << std::endl;
				std::cout << "How match this reader take book: " << reader[i].Count_reading_book << std::endl;
				std::cout << std::endl;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "Librery not have this reader in BaseData" << std::endl;
			}
			
		}
	}
}

void Librery::give_book()
{
	int ID_b, ID_r,book_i,reader_i;

	std::cout << "Write ID issued book: " << std::endl;
	std::cin >> ID_b;
	std::cout << "Write ID of the book recipient: " << std::endl;
	std::cin >> ID_r;
	book_i = -1;
	reader_i = -1;
	for (int i=0;i<book.size();i++)
	{
		if (ID_b==book[i].ID&&book[i].open==true)
		{
			book_i = i;
			break;
		}
	}
	for (int i = 0; i < reader.size(); i++)
	{
		if (ID_r == reader[i].ID&&reader[i].Count_reading_book<3)
		{
			reader_i = i;
			break;
		}
	}
	if (reader_i != -1 && book_i != -1)
	{
		book[book_i].open = false;
		reader[reader_i].Count_reading_book++;
	}
}

void Librery::get_book()
{
	int ID_b, ID_r;

	std::cout<< std::endl;
	std::cout << "Write ID geting book: " << std::endl;
	std::cin >> ID_b;
	std::cout<< std::endl;
	std::cout << "Write ID geting reader: " << std::endl;
	std::cin >> ID_r;
	for (int i = 0; i < reader.size(); i++)
	{
		if (ID_r == reader[i].ID&&ID_b==book[i].ID&&book[i].open==false)
		{
			reader[i].Count_reading_book--;
			book[i].open = true;
		}
	}
}