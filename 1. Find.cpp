#include "PW4.h"

#include <map>

/*---   Предварительное   ---*/

// Реализация std::map
typedef std::map<std::string, int> Pressure;

// Рандом в диапазоне [min, max]
const int Random(const int& min, const int& max)
{
	if (min <= max)
		return min + rand() % (max + 1 - min); // диапазон [min, max]
	else
		return 0;
};
/* -------------------------------------------- */



int main1()
{
	// Инициализация и заполнение std::map -- Давление в балонах
	Pressure cylinders;
	for (int i = 1; i <= 5; i++)
	{
		cylinders.insert(Pressure::value_type("Красный_" + std::to_string(i), Random(1, 3)));
	}
	for (int i = 1; i <= 2; i++)
	{
		cylinders.insert(Pressure::value_type("Синий_" + std::to_string(i), Random(1, 3)));
	}
	for (int i = 1; i <= 3; i++)
	{
		cylinders.insert(Pressure::value_type("Зелёный_" + std::to_string(i), Random(1, 3)));
	}


	std::cout << "Вывод всех названий баллонов и их давление (std::map):" << std::endl;
	for (Pressure::iterator itL = cylinders.begin(); itL != cylinders.end(); ++itL)
	{
		std::cout << std::setw(11) << itL->first + ':' << itL->second << '\n';
	}
	std::cout << std::endl;



	/*---   Предисловие   ---*/
	std::cout
		<< std::setw(15) << "На пределе:"
		<< std::setw(15) << "Цел ли синий:"
		<< std::setw(15) << "Все ли целы:"
		<< " { ";
	for (Pressure::iterator itL = cylinders.begin(); itL != cylinders.end(); ++itL)
	{
		std::cout << itL->first[0] << ' ';
	}
	std::cout << '}' << std::endl;
	/* -------------------------------------------- */



	/*---   Предикаты   ---*/
	// Проверка: На пределе
	auto cheсk_all_of = [](const Pressure::value_type& elem)
	{
		return elem.second > 3;
	};

	// Проверка: Цел ли хоть один Синий
	auto cheсk_any_of = [](const Pressure::value_type& elem)
	{
		if (elem.first.find("Синий") != std::string::npos)
		{
			return elem.second > 0;
		}
		return false;
	};

	// Проверка: Все ли целы
	auto cheсk_none_of = [](const Pressure::value_type& elem)
	{
		return elem.second == 0;
	};
	/* -------------------------------------------- */


	// Цикл проверок
	bool bCycle = true;
	while (bCycle)
	{
		/*---   all_of   ---*/
		// Проверка: На пределе
		if (std::all_of(cylinders.begin(), cylinders.end(), cheсk_all_of))
			std::cout << std::setw(15) << "Все";
		else
			std::cout << std::setw(15) << "Не все";
		/* -------------------------------------------- */



		/*---   any_of   ---*/
		// Проверка: Цел ли хоть один Синий
		if (std::any_of(cylinders.begin(), cylinders.end(), cheсk_any_of))
			std::cout << std::setw(15) << "Минимум один";
		else
			std::cout << std::setw(15) << "Все лопнули";
		/* -------------------------------------------- */



		/*---   none_of   ---*/
		// Проверка: Все ли целы
		if (std::none_of(cylinders.begin(), cylinders.end(), cheсk_none_of))
			std::cout << std::setw(15) << "Все";
		else
			std::cout << std::setw(15) << "Не все";
		/* -------------------------------------------- */



		// Если все НЕ целы, то последнй цикл отображения
		if (std::all_of(cylinders.begin(), cylinders.end(), cheсk_none_of))
			bCycle = false;

		// Вывод значений каждого элемента
		std::cout << " { ";
		for (Pressure::iterator itL = cylinders.begin(); itL != cylinders.end(); ++itL)
		{
			std::cout << itL->second << ' ';

			if (itL->second < 7 && itL->second != 0)
				++itL->second;
			else
				itL->second = 0;
		}
		std::cout << '}';
		/* -------------------------------------------- */

		std::cout << std::endl;
	}

	return 0;
}