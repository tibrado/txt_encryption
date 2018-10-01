// +++++++++++++++++++++++
// add creation text file 
// +++++++++++++++++++++++


#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#ifndef CRYPTION_H
#define CRYPTION_H
class CRYPTION {
private:
	const int X = 126, N = 32; 
	int S; 

	std::string M, K; 

	//bool D; 

	char e(char, char);
	char d(char, char);

	std::string c(bool); 

public:
	CRYPTION(std::string, std::string); 
	CRYPTION(std::string, std::string, int); 
	~CRYPTION(); 

	std::string decrypt();
	std::string encrypt();
	 
};
#endif

#ifndef CFILE_H
#define CFILE_H
class CFILE {
private:
	const char* _fn; 
	const char* _key; 

	std::string _id; 

	std::ifstream _in; 
	std::ofstream _out; 

	std::string _data; 

	std::string e_d(bool); 

	std::string g_d(const char*); 

public:

	/*open file 
	 read file
	 delete file 
	 decode file 
	 if true -> create new 
	 if false -> create same
	 */ 

	CFILE(const char*, const char*);
	~CFILE(); 

	bool encrypt_file(); 
	bool decrypt_file(); 

};
#endif



