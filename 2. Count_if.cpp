#include "PW4.h"

#include <unordered_map>

/*---   Предварительное   ---*/

// Реализация std::unordered_map
typedef std::unordered_map<std::string, int> Players;

// Переменная для сравнения
char Type;

// Предикат: Количество команд
auto check_CommandType = [](const Players::value_type& elem)
{
	return (elem.first.find(Type) != std::string::npos);
};

// Предикат: Рейтинг выше 7
auto check_Rating = [](const Players::value_type& elem)
{
	return elem.second > 7;
};
/* -------------------------------------------- */



int main2()
{
	// Команды игроков
	char commandType[] = { 'A', 'B', 'C', 'D' };

	// Инициализация и заполнение std::unordered_map -- Игроки с рандомным рейтингом от 0 до 9
	Players pawns;
	for (int i = 1; i <= 20; i++)
	{
		pawns.insert(Players::value_type(std::to_string(i) + '_' + commandType[rand() % 4], rand() % 10));
	}

	std::cout << "Вывод всех игроков (std::unordered_map):" << std::endl;
	for (Players::iterator itL = pawns.begin(); itL != pawns.end(); ++itL)
	{
		std::cout << std::setw(6) << itL->first + ':' << itL->second << '\n';
	}
	std::cout << std::endl;



	// Количество игроков в каждой команде
	int countA, countB, countC, countD;
	std::cout << "Вывод количества игроков:" << std::endl;

	Type = commandType[0];
	countA = count_if(pawns.begin(), pawns.end(), check_CommandType);
	Type = commandType[1];
	countB = count_if(pawns.begin(), pawns.end(), check_CommandType);
	Type = commandType[2];
	countC = count_if(pawns.begin(), pawns.end(), check_CommandType);
	Type = commandType[3];
	countD = count_if(pawns.begin(), pawns.end(), check_CommandType);

	// Вывод в консоль
	std::cout
		<< "Команда A: " << countA << '\n'
		<< "Команда B: " << countB << '\n'
		<< "Команда C: " << countC << '\n'
		<< "Команда D: " << countD << '\n'
		<< std::endl;

	// Количество игроков с рейтингом выше 7
	int countRating;
	countRating = count_if(pawns.begin(), pawns.end(), check_Rating);

	// Вывод в консоль
	std::cout
		<< "Количество игроков с рейтингом выше 7: " << countRating << '\n'
		<< std::endl;

	return 0;
}