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