#include "PW4.h"

// Выбор демонстрации по умолчанию
int DefaultSelection = 3;
// Количество демонстраций
int MaxSelection = 3;

bool MainSelection(int& sel)
{
	switch (sel)
	{
	case 1:
		main1();
		break;

	case 2:
		main2();
		break;

	case 3:
		main3();
		break;

	default:
		std::cout << "Некорректный ввод. Выбор по умолчанию : "
			<< DefaultSelection
			<< '\n'
			<< std::endl;;
		return true;
		break;
	}

	return false;
}

int main()
{
	// Локализация
	setlocale(LC_ALL, "Russian");
	// <iomanip>: Выравнивание по левому краю
	std::cout << std::setiosflags(std::ios::left);
	// Использовать текущее время в качестве начального значения для генератора псевдослучайных чисел
	srand(time(0));

	std::cout << "Пример использования алгоритмов:\n"
		<< std::setw(12) << "1. find" << "для  std::map\n"
		<< std::setw(12) << "2. count_if" << "для  std::unordered_map\n"
		<< std::setw(12) << "3. for_each" << "для  std::set\n"
		<< '\n';

	std::cout << "Выбирите тестируемый алгоритм: ";
	int Selection;
	std::cin >> Selection;
	std::cout << std::endl;

	DefaultSelection = ((DefaultSelection - 1) % MaxSelection) + 1;

	if (MainSelection(Selection))
		MainSelection(DefaultSelection);

	return 0;
}