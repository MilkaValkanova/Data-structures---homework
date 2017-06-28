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
#include"DataCenter.h"

//help funktions
bool equalStr(char* str1, size_t s1, char* str2, size_t s2);



DataCenter::Data::Data(int v, char* t, int s) :value(v), tsize(s)
{
	text = new char[tsize+1];
	for (int32_t i = 0; i < tsize; i++)
	{
		this->text[i] = t[i];
	}
	this->text[tsize] = '\0';
}

DataCenter::Data::Data(const Data& other)
{
	copy(other);
}

DataCenter::Data&  DataCenter::Data::operator=(const Data& other)
{
	if (this != &other)
	{
		delete[]text;
		copy(other);
	}
	return *this;
}

DataCenter::Data::~Data()
{
	delete[]text;
	//text = nullptr;
}

void DataCenter::Data::copy(const Data& other)
{
	this->value = other.value;
	this->tsize = other.tsize;
	text = new char[tsize+1];
	for (int32_t i = 0; i < tsize; i++)
	{
		this->text[i] = other.text[i];
	}
	this->text[tsize] = '\0';
}

bool DataCenter::Data::operator<(const Data& other)const
{
	return this->value < other.value;
}

bool DataCenter::Data:: operator>=(const Data& d)const
{
	return !(*this < d);
}

 bool DataCenter::Data::operator==(const Data& other)const
{
	if (this->tsize != other.tsize || this->value != other.value)
	{
		return false;
	}
	
	for (int32_t i = 0; i < tsize; i++)
		if (this->text[i] != other.text[i])
		{
			return false;
		}
	return true;
}

 std::ostream& operator<<(std::ostream& os, const DataCenter::Data& element)
 {
	 os << element.value << "   ";
	 for (int32_t i = 0; i < element.tsize; i++)
	 {
		 os << element.text[i];
	 }
	 os << "\n";
	 return os;

 }

 const int SIZE = 4;//size of int32 
 void DataCenter::createDataSet(const std::string& filename,DynamicArr<Data>&dataSet)
{
	int tmpVal;
	int tmpSize;		
	char* tmpText = nullptr;
	std::ifstream file(filename, std::ios::in | std::ios::binary);
	while (file)
	{
		file.read((char*)&tmpVal, SIZE);
		file.read((char*)&tmpSize, SIZE);

		delete[] tmpText;
		tmpText = new char[tmpSize + 1];
		file.read(tmpText, tmpSize);
		tmpText[tmpSize] = '\0';

		Data newEl(tmpVal, tmpText, tmpSize);
		if(file) 
		{
			dataSet.addEl(newEl);
		}
	}
	file.close();
	return;
}

void DataCenter::sortArr(DynamicArr<Data>&dataSet)
{
size_t size = dataSet.getsize();
for (size_t i = 0; i < size-1; i++)
	{
		for (size_t j = i+1; j < size; j++)
		{
			if (dataSet[j] < dataSet[i])
			{
				Data tmp = dataSet[j];
				dataSet[j] = dataSet[i];
				dataSet[i] = tmp;
			}
		}
	}
}

void  DataCenter::add(int key, char* data, int dsize)
{
	Data element(key, data, dsize);
	dataTree.insert(element);
}

void  DataCenter::remove(int key, char* data, int dsize)
{
	Data element(key, data, dsize);
	if (dataTree.search(element))
	{
		dataTree.remove(element);
		std::cout << "true\n";
		return;
	}
	std::cout << "false\n";
	return;
}
void  DataCenter::removeall(int key, char* data, int dsize)
{
	Data element(key, data, dsize);
	int cnt = 0;
	while (dataTree.search(element))
	{ 
			dataTree.remove(element);
			cnt++;
	}
	std::cout << cnt<<"\n";
	return;
}
void DataCenter:: search(int key, char* data, int dsize)
{
	Data element(key, data, dsize);
	if (dataTree.search(element))
	{
		std::cout << "true\n";
		return;
	} 
	std::cout << "false\n";
}

void DataCenter::setCommand(char* com, size_t sc, char* text, size_t st, int32_t val)
{
	if (equalStr(com, sc, "add", 3) == true)
	{
		add(val, text, st);
	}
	else if (equalStr(com, sc, "remove", 6) == true)
	{
		remove(val, text, st);
	}
	else if (equalStr(com, sc, "removeall", 9) == true)
	{
		removeall(val, text, st);
	}
	else if (equalStr(com, sc, "search", 6) == true)
	{
		search(val, text, st);
	}
	else return;
}

//help funktions
bool equalStr(char* str1, size_t s1, char* str2, size_t s2)
{
	if (s1 != s2) return false;
	for (size_t i = 0; i < s1; i++)
	{
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}



