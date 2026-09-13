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
		std::cout << r.ID << std::endl;
		std::cout << r.Name << std::endl;
		std::cout << r.Surname << std::endl;
		std::cout << r.Count_reading_book << std::endl;
		std::cout<<std::endl;


		if (reader.size() == 0)
		{
			std::cout<<"Librery haven't readers!!" << std::endl;
		}
	}
}

void Librery::new_reader()
{
	 
}