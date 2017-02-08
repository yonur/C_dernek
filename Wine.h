/*

The Wine class has a string class object member (see Chapter 4) that holds the



name of a wine and a Pair object (as discussed in this chapter) of valarray<int>



objects (as discussed in this chapter).The first member of each Pair object holds



the vintage years, and the second member holds the numbers of bottles owned for



the corresponding particular vintage year. For example, the first valarray object of



the Pair object might hold the years 1988, 1992, and 1996, and the second



valarray object might hold the bottle counts 24, 48, and 144. It may be convenient



for Wine to have an int member that stores the number of years.Also some



typedefs might be useful to simplify the coding:



typedef std::valarray<int> ArrayInt;



typedef Pair<ArrayInt, ArrayInt> PairArray;



Thus, the PairArray type represents type Pair<std::valarray<int>, std::valarray<int> >.



Implement the Wine class by using containment.The class



should have a default constructor and at least the following constructors:



// initialize label to l, number of years to y,



// vintage years to yr[], bottles to bot[]



Wine(const char * l, int y, const int yr[], const int bot[]);



// initialize label to l, number of years to y,



// create array objects of length y



Wine(const char * l, int y);



The Wine class should have a method GetBottles() that, given a Wine object with



y years, prompts the user to enter the corresponding number of vintage years and



bottle counts.A method Label() should return a reference to the wine name.A



method sum() should return the total number of bottles in the second



valarray<int> object in the Pair object.



The program should prompt the user to enter a wine name, the number of elements



of the array, and the year and bottle count information for each array element.



The program should use this data to construct a Wine object and then display



the information stored in the object. For guidance, here’s a sample test program:

*/

#pragma once

#include <iostream>

#include <valarray>

#include <string>

typedef std::valarray<int> ArrayInt;

typedef Pair<ArrayInt, ArrayInt> PairArray;

template <class T1, class T2>
class Pair

{

private:

	T1 a;

	T2 b;

public:

	T1 & first();

	T2 & second();

	T1 first() const { return a; }

	T2 second() const { return b; }

	Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { }

	Pair() {}

};



class Wine

{

private:

	std::string label;

	int num_of_years;

	PairArray my_wines;

	ArrayInt vint_year;

	ArrayInt num_bottles;

public:

	Wine() : label("empty"), my_wines() {};

	~Wine();

	Wine(const char * l, int y) : label(l) {

		my_wines[y];

		for (int i = 0; i < y; i++)
		{
			my_wines[i].first() = 0;
			my_wines[i].second() = 0;
		}

	};

	Wine(const char * l, int y, const int yr[], const int bot[]) :label(l), num_of_years(y) {

		my_wines[y];

		for (int i = 0; i < y; i++)
		{
			my_wines[i].first() = yr[i];
			my_wines[i].second() = bot[i];
		}
	};

	std::string & Label();

	int sum();



	//friends

	friend std::istream &operator >> (std::istream & is, Wine & stu);

	friend std::istream & getline(std::istream & is, Wine & stu);

	friend std::ostream & operator << (std::ostream &os, const Wine & stu);



};


