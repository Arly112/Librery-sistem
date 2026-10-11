#include <iostream>
#include "Reader.h"
#include "Book.h"
#include "Librery.h"
#include <string>
#include <fstream>


void Librery::cout_all_book()
{
	if (book.size() == 0)
	{
		std::cout << std::endl;
		std::cout << "Librery haven't books!!";
		std::cout << std::endl;
		return;
	}
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
	b.ID_Reader = 0;
	book.push_back(b);
}

void Librery::delete_book()
{
	int ID;
	bool del=false;
	std::cout << "The ID of the book do you want to delete: ";
	std::cin >> ID;
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].ID == ID && book[i].open==true)
		{
			book.erase(book.begin() + i);
			std::cout << "Book in ID " << ID << " delete!";
			del = true;
			return;
		}
	}
	if (!del)
	{
		std::cout << "Book not delete!!";
		return;
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
		std::cout << "Write name finded book:" << std::endl;
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
				return;
			}
		}
	}
	else if (vab == 2)
	{
		int ID;
		std::cin.ignore(1000, '\n');
		std::cout << "Write ID finded book:" << std::endl;
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
				return;
			}
		}
	}
}

void Librery::cout_all_reader()
{
	if (reader.size() == 0)
	{
		std::cout << "Librery haven't readers!!" << std::endl;
		return;
	}
	for (auto r : reader)
	{
		std::cout<<std::endl;
		std::cout << "ID: " << r.ID << std::endl;
		std::cout << "Name: " << r.Name << std::endl;
		std::cout << "Surname: " << r.Surname << std::endl;
		std::cout << "How match this reader take book: " << r.Count_reading_book << std::endl;
		std::cout << std::endl;
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
		bool delet=false;
		std::cin.ignore(1000, '\n');
		std::cout << "Write Name and Surname deleted reader:" << std::endl;
		std::getline(std::cin, Name);
		std::getline(std::cin, Surname);
		for (int i = 0; i < reader.size(); i++)
		{
			if (reader[i].Name == Name && reader[i].Surname== Surname&&reader[i].Count_reading_book==0)
			{
				reader.erase(reader.begin() + i);
				delet = true;
				return;
			}
			
		}
		if(!delet)
		{
			std::cout << std::endl;
			std::cout << "Librery not have this reader in BaseData or this reader have not returned books" << std::endl;
		}
	}
	else if (vab == 2)
	{
		int ID;
		bool delet = false;
		std::cin.ignore(1000, '\n');
		std::cout << "Write ID deleted reader:" << std::endl;
		std::cin >> ID;
		for (int i = 0; i < reader.size(); i++)
		{
			if (reader[i].ID == ID&&reader[i].Count_reading_book==0)
			{
				reader.erase(reader.begin() + i);
				delet = true;
				return;
			}
			
		}
		if(!delet)
		{
			std::cout << std::endl;
			std::cout << "Librery not have this reader in BaseData or this reader have not returned books" << std::endl;
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
		bool find = false;
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
				find = true;
			}

		}
		if (!find)
		{
			std::cout << std::endl;
			std::cout << "Librery not have this reader in BaseData" << std::endl;
		}

	}
	else if (vab == 2)
	{
		int ID;
		bool find = false;
		std::cin.ignore(1000, '\n');
		std::cout << "Write finded reader:" << std::endl;
		std::cin >> ID;
		for (int i = 0; i < reader.size(); i++)
		{
			if (reader[i].ID==ID)
			{
				std::cout << std::endl;
				std::cout << "ID: " << reader[i].ID << std::endl;
				std::cout << "Name: " << reader[i].Name << std::endl;
				std::cout << "Surname: " << reader[i].Surname << std::endl;
				std::cout << "How match this reader take book: " << reader[i].Count_reading_book << std::endl;
				std::cout << std::endl;
				find = true;
			}
		}

		if (!find)
		{
			std::cout << std::endl;
			std::cout << "Librery not have this reader in BaseData" << std::endl;
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
		book[book_i].ID_Reader = reader[reader_i].ID;
		reader[reader_i].Count_reading_book++;
	}
}

void Librery::get_book()
{
	int ID_b, ID_r;
	bool get=false;
	std::cout<< std::endl;
	std::cout << "Write ID geting book: " << std::endl;
	std::cin >> ID_b;
	std::cout<< std::endl;
	std::cout << "Write ID geting reader: " << std::endl;
	std::cin >> ID_r;
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].ID == ID_b)
		{
			if (ID_r == book[i].ID_Reader && book[i].open == false)
			{
				for (int j = 0; j < reader.size(); j++)
				{
					if (reader[j].ID == ID_r)
					{
						book[i].open = true;
						reader[j].Count_reading_book--;
						book[i].ID_Reader = 0;
						get = true;
						return;
					}
				}
			}
		}
	}
	if (!get)
	{

		std::cout << "\nThis book not get\n";
	}
}

void Librery::cout_all_issued_book()
{
	for (int i = 0; i < book.size(); i++)
	{
		if (!book[i].open)
		{
			std::cout << std::endl;
			std::cout << "ID: " << book[i].ID << std::endl;
			std::cout << "Name: " << book[i].Name << std::endl;
			std::cout << "Author: " << book[i].Author << std::endl;
			std::cout << "Year publish: " << book[i].Year_publish << std::endl;
			for (int f = 0; f < reader.size(); f++)
			{
				if (book[i].ID_Reader == reader[f].ID)
				{
					std::cout << "Reader this book" << book[i].ID << std::endl;
					std::cout << "Name: " << reader[f].Name << std::endl;
					std::cout << "Surname: " << reader[f].Surname << std::endl;
					std::cout << "How match this reader take book: " << reader[f].Count_reading_book << std::endl;
					std::cout << std::endl;
				}
			}
			std::cout << std::endl;
		}
	}
}

void Librery::save_data()
{
	std::ofstream save_b;
	size_t bk;
	bk = book.size();
	save_b.open("Save_b.txt");
	save_b << next_id_Book << std::endl;
	save_b << bk <<std::endl;
	for (size_t i = 0; i < bk; i++)
	{

		save_b << book[i].ID << std::endl
			<< book[i].Name << std::endl
			<< book[i].Author << std::endl
			<< book[i].Year_publish << std::endl
			<< book[i].open << std::endl
			<< book[i].ID_Reader << std::endl;
	}
	save_b.close();

	std::ofstream save_r;
	size_t rd;
	rd = reader.size();
	save_r.open("Save_r.txt");
	save_r << next_id_Reader << std::endl;
	save_r << rd <<std::endl;
	for (size_t i = 0; i < rd; i++)
	{
		save_r << reader[i].ID << std::endl
			<< reader[i].Name << std::endl
			<< reader[i].Surname << std::endl
			<< reader[i].Count_reading_book << std::endl;
	}
	save_r.close();

}

void Librery::load_data()
{
	
	size_t c=0,c1=0;
	std::ifstream Load_B;
	Load_B.open("Save_b.txt");
	if (Load_B.is_open())
	{
		book.clear();
		reader.clear();
	}
	else
	{
		std::cout << "Not is load";
		return;
	}
	Load_B >> next_id_Book;
	Load_B >> c;
	for (size_t i = 0; i < c; i++)
	{
		Book b;
		Load_B >> b.ID;
		Load_B.ignore(1000, '\n');
		std::getline(Load_B, b.Name);
		std::getline(Load_B, b.Author);
		Load_B >> b.Year_publish >> b.open>>b.ID_Reader;
		book.push_back(b);
	}
	Load_B.close();

	std::ifstream Load_R;
	Load_R.open("Save_r.txt");
	Load_R >> next_id_Reader;
	Load_R >> c1;
	for (size_t i = 0; i < c1; i++)
	{
		Reader r;
		Load_R >> r.ID;
		Load_R.ignore(1000, '\n');
		std::getline(Load_R, r.Name);
		std::getline(Load_R, r.Surname);
		Load_R >> r.Count_reading_book;
		reader.push_back(r);
	}
	Load_R.close();
}