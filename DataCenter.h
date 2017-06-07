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

#pragma once
#include <fstream>
#include"BinaryTree.hpp"
#include"DynamicArr.hpp"


class DataCenter
{
	private:
		struct Data
		{
			int32_t value;
			char* text;
			int32_t tsize;
			Data() :text(nullptr) {};
			Data(int, char*, int);
			Data(const Data& other);
			Data& operator=(const Data& other);
			~Data();

			bool operator<(const Data&)const;
			bool operator>=(const Data& d)const;
			bool operator==(const Data&)const;

		private:
			void copy(const Data&);
		};
		friend std::ostream& operator<<(std::ostream& os, const Data& element);

		BinaryTree<Data> dataTree;

	public:
		DataCenter(const std::string& filename)
		{
			DynamicArr<Data> dataSet;
			createDataSet(filename,dataSet);
			sortArr(dataSet);
			dataTree.createPBT(dataSet);

		}
		~DataCenter() {};
		DataCenter(const DataCenter&) = delete;
		DataCenter& operator=(const DataCenter&) = delete;

	private:
		void createDataSet(const std::string&,DynamicArr<Data>&);
		void sortArr(DynamicArr<Data>&);

		public:
			void add(int key, char* data, int dsize);
			void remove(int key, char* data, int dsize);
			void removeall(int key, char* data, int dsize);
			void search(int key, char* data, int dsize);
			void Print() const { dataTree.Print(); }
			void setCommand(char*, size_t, char*, size_t, int32_t);
};

