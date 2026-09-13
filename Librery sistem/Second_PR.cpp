#include <iostream>
#include <windows.h>
#include"Librery.h"

void Librery_menu()
{
	std::cout << std::endl;
	std::cout << "Что хотите выбрать?" << std::endl;
	std::cout << "1. Показать все книги" << std::endl;
	std::cout << "2. Добавить книгу" << std::endl;
	std::cout << "3. Удалить книгу" << std::endl;
	std::cout << "4. Найти книгу" << std::endl;
	std::cout << "5. Показать всех читателей" << std::endl;
	std::cout << "6. Добавить читателя" << std::endl;
	std::cout << "7. Удалить читателя" << std::endl;
	std::cout << "8. Найти читателя" << std::endl;
	std::cout << "9. Выдать книгу" << std::endl;
	std::cout << "10. Вернуть книгу" << std::endl;
	std::cout << "11. Показать выданные книги" << std::endl;
	std::cout << "12. Сохранить данные" << std::endl;
	std::cout << "13. Загрузить данные" << std::endl;
	std::cout << "0. Выход" << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::setlocale(LC_ALL, "ru");
	Librery l;
	int choice;
	choice = -1;
	while (choice != 0)
	{
		Librery_menu();
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			l.cout_all_book();
			break;
		case 2: l.new_book();
			break;
		case 3: l.delete_book();
			break;
		case 4: l.find_book();
			break;
		default:
			break;
		}

	}
}