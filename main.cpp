/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Milka Valkanova
* @idnumber 45155
* @task 1
* @compiler VC
*
*/
#include "BinaryTree.hpp"
#include "DataCenter.h"

size_t mylen(char*);

int main(int argc,char** argv)
{
	if (argc < 2)
	{
		std::cout << "Error\n";
		return 0;
	}
	else
	{
	DataCenter d(argv[1]);
	//	DataCenter d("Test.bin");
	char* command = nullptr;
	char* text = nullptr;

	int32_t value;
	while (!std::cin.eof())
	{
		if (command)delete[]command;
		if (text)delete[]text;
		command = new char[100];
		text = new char[100];
		d.Print(); std::cout << std::endl;
		std::cin >> command;
		std::cin >> value;
		std::cin >> text;
		if (std::cin.eof())
		{
			return 0;
		}
		d.setCommand(command, mylen(command), text, mylen(text), value);
	 }
  }

	return 0;
}

size_t mylen(char* word)
{
	int i = 0;
	while (word[i] != '\0')
	{
		i++;
	}
	return i;
}


