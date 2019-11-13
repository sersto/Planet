/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
               https://www.onlinegdb.com/online_c++_compiler

*******************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

//Объявление и инициализация константы (число планет)
const int PLANETS_IN_SOLAR_SYSTEM = 9;
//Объявление структуры PlanetInfo
struct PlanetInfo
{
    string name;
    int diameter;
    bool haslife;
    int moons;
};
//Создание 9-ти структур по числу планет (чтобы не вводить с клавиатуры)
//Сведения взяты из Википедии, актуальны на 2019 год
PlanetInfo Info1 {"Меркурий", 4878, 0, 0};
PlanetInfo Info2 {"Венера", 12104, 0, 0};
PlanetInfo Info3 {"Земля", 12742, 1, 1};
PlanetInfo Info4 {"Марс", 6787, 0, 2};
PlanetInfo Info5 {"Юпитер", 142800, 0, 79};
PlanetInfo Info6 {"Сатурн", 120500, 0, 82};
PlanetInfo Info7 {"Уран", 51100, 0, 27};
PlanetInfo Info8 {"Нептун", 49200, 0, 14};
PlanetInfo Info9 {"Плутон", 2376, 0, 5};

class Planet
{
public:

    Planet() {} //Конструктор
    ~Planet() {} //Деструктор
    PlanetInfo Info; //Структура - поле данных класса
    //Функция заполняет переданный ей по ссылке массив реальными сведениями о планетах 
    void Init(Planet P[]) {
	    P[0].Info = Info1;
	    P[1].Info = Info2;
	    P[2].Info = Info3;
	    P[3].Info = Info4;
	    P[4].Info = Info5;
	    P[5].Info = Info6;
	    P[6].Info = Info7;
	    P[7].Info = Info8;
	    P[8].Info = Info9;
    }
    //Функция получает сведения об одной планете и присваивает их полям структуры PlanetInfo класса Planet
    void GetPlanet(string n, int d, bool l, int m) {
        Info.name = n;
        Info.diameter = d;
        Info.haslife = l;
        Info.moons = m;
    }
    //Функция Print без аргументов. 
    //Вывод на печать полей структуры PlanetInfo (запись о планете). 
    void Print() {
        cout << "name = " << Info.name << ", diameter = " << Info.diameter << ", haslife = " << Info.haslife << ", moons = " << Info.moons << endl ;
    }
    //Функция Print (перегружена) с аргументом имя массива
    //Вывод на печать записей о всех планетах сразу.
    void Print(Planet P[]) {
        cout << "Array of Planets" << endl ;
	for ( int counter = 0; counter < PLANETS_IN_SOLAR_SYSTEM; counter++) {
        cout << "name = " << P[counter].Info.name << ", diameter = " << P[counter].Info.diameter ;
        cout << ", haslife = " << P[counter].Info.haslife << ", moons = " << P[counter].Info.moons << endl ;
	}
    }

    //Функция Sort с аргументом имя массива
    //Сортировка записей массива объектов класса Planet по диаметру планет методом пузырька.
    void Sort(Planet P[]) {
	Planet TMP;
	cout << "Сортировка по диаметру" << endl ;
        //Метод пузырька
	for ( int i = PLANETS_IN_SOLAR_SYSTEM-1; i >= 0; i--) {
		for ( int j = 0; j < i; j++) {
		if ( P[j].Info.diameter > P[j + 1].Info.diameter ){ 
			TMP = P[j];
			P[j] = P[j+1];
			P[j+1] = TMP;
		}
	    }
	}
    }

};// завершено определение класса Planet

    //Создание массива объектов класса Planet
    Planet SOLAR_SYSTEM[PLANETS_IN_SOLAR_SYSTEM ];

    //Функция сравнения для сортировки 
    //третий аргумент в стандартной функции C++ "sort"

    //"compare_name" - для сортировки "планеты" по алфавиту
    bool compare_name (Planet a, Planet b) {
        return (a.Info.name < b.Info.name); }
    //"compare_diameter" - для сортировки "планеты" по возрастанию диаметра
    bool compare_diameter (Planet a, Planet b) {
        return (a.Info.diameter < b.Info.diameter); }
    //"compare_haslife" - для сортировки "планеты" по наличию жизни
    bool compare_haslife (Planet a, Planet b) {
        return (a.Info.haslife < b.Info.haslife); }
    //"compare_moons" - для сортировки "планеты" по числу спутников
    bool compare_moons (Planet a, Planet b) {
        return (a.Info.moons < b.Info.moons); }

int main()
{
    //Ввод с клавиатуры сведений о планетах
    for ( int counter = 0; counter < PLANETS_IN_SOLAR_SYSTEM; counter++ ) {
	    string name;
	    int diameter;
	    bool haslife;
	    int moons;

	    //ВВОД С КЛАВИАТУРЫ ЗАКОМЕНТАРЕН на время отладки других функций

	    //cout << "Введите через пробел: Название планеты, Диаметр планеты, Есть ли жизнь (0 или 1), Число спутников   ";
	    //cin >> name >> diameter >> haslife >> moons;
	    //SOLAR_SYSTEM[counter].GetPlanet(name, diameter, haslife, moons);
    }

    //Вывод на печать записи о планетах по одной. Функция Print без аргументов. 
    for ( int counter = 0; counter < PLANETS_IN_SOLAR_SYSTEM; counter++ ) {
    SOLAR_SYSTEM[counter].Print();
    }
	//Инициализация массива объектов класса Planet данными о реальных планетах
	SOLAR_SYSTEM[0].Init(SOLAR_SYSTEM);
	//Вывод на печать записей о всех планетах сразу. Функция Print с аргументом имя массива
	SOLAR_SYSTEM[0].Print(SOLAR_SYSTEM);

	//Сортировка массива объектов класса Planet функцией-членом класса
	//SOLAR_SYSTEM[0].Sort(SOLAR_SYSTEM);
	
	//Сортировка по алфавиту массива объектов класса Planet стандартной функцией C++ "sort"
	sort (SOLAR_SYSTEM, SOLAR_SYSTEM + PLANETS_IN_SOLAR_SYSTEM, compare_name);
        cout << endl << "Сортировка по алфавиту ";
	//Вывод на печать отсортированного массива записей о всех планетах сразу 
	SOLAR_SYSTEM[0].Print(SOLAR_SYSTEM);

	//Сортировка по диаметру массива объектов класса Planet стандартной функцией C++ "sort" 
	sort (SOLAR_SYSTEM, SOLAR_SYSTEM + PLANETS_IN_SOLAR_SYSTEM, compare_diameter);
	//Вывод на печать
        cout << endl << "Сортировка по диаметру ";
	SOLAR_SYSTEM[0].Print(SOLAR_SYSTEM);

	//Сортировка по наличию жизни массива объектов класса Planet стандартной функцией C++ "sort"
	sort (SOLAR_SYSTEM, SOLAR_SYSTEM + PLANETS_IN_SOLAR_SYSTEM, compare_haslife);
        cout << endl << "Сортировка по наличию жизни ";
	//Вывод на печать
	SOLAR_SYSTEM[0].Print(SOLAR_SYSTEM);

	//Сортировка по числу спутников массива объектов класса Planet стандартной функцией C++ "sort"
	sort (SOLAR_SYSTEM, SOLAR_SYSTEM + PLANETS_IN_SOLAR_SYSTEM, compare_moons);
        cout << endl << "Сортировка по числу спутников ";
	//Вывод на печать
	SOLAR_SYSTEM[0].Print(SOLAR_SYSTEM);

    	//cout<<"Здравствуй мир";
    return 0;
}

