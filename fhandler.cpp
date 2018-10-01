#include "cryption.h"

CFILE::CFILE(const char* file_name, const char* key) {

	_id = "NULL"; 
	_key = key; 
	_fn = file_name; 

	std::string content = g_d(file_name); 

	try
	{
		if (content == "NULL")
			throw "Unable to open File."; 

		_data += content;

		// delete after reading file 
		if (std::remove(file_name) != 0)
			throw "Unable to delete File."; 
	}
	catch (const char* e) {	std::cerr << e; }
}

CFILE::~CFILE() {
	// if file was not decrypted add count 
	// if file was not encrypted add count 
	// if file count is greater than 3 scrable
	// and delete file 
}


// private functions 
std::string CFILE::g_d(const char* n) {
	std::FILE *fp; 
	errno_t err = fopen_s(&fp, n, "rb");

	if (err == 0) {
		std::string c;
		std::fseek(fp, 0, SEEK_END);
		c.resize(std::ftell(fp));
		std::rewind(fp);
		std::fread(&c[0], 1, c.size(), fp);
		std::fclose(fp);
		
		return c; 
	}
	return "NULL"; 
}

std::string CFILE::e_d(bool _e_d = true) { 
	std::string data_; 

	

	if (_e_d) { 
		_id = std::to_string(time(0));

		data_ += "*" + _id + "*";
		data_ += _data; 
		data_ += "*" + _id + "*";

		CRYPTION fe(data_, _key);

		data_ = fe.encrypt(); 
	}
	else { 
		
		CRYPTION fe(_data, _key);

		data_ = fe.decrypt(); 
	}

	return data_; 
}

// public functions
bool CFILE::encrypt_file(){
	_out.open(_fn);  // etemp.txt to file_name

	if (!_out.is_open()) { return false; }
	else { 	_out << e_d();  }

	_out.close(); 
	return true; 
}

bool CFILE::decrypt_file(){
	_out.open(_fn);

	if (!_out.is_open()) { return false; }
	else { 
		std::string c_id; 
		c_id = e_d(false);


		if (c_id.substr(0, 1) == "*") {
			// ++++++++++++++++++++++++++++++++++++++++++++++
			// change in futrure. Can only handle 10 digits 
			// ++++++++++++++++++++++++++++++++++++++++++++++
			if (c_id.substr(1, 10) == c_id.substr(c_id.length() - 11, 10)) {
				int a = c_id.size();
				
				c_id.erase(0, 12); 
				c_id.erase(c_id.length() - 12, 12); 

				_out << c_id; 

				_out.close();
				return true; 
			}
			else {
				_out << c_id;
				_out.close();
				return false; 
			}
		}
		else {
			_out << _data;
			_out.close();
			return false;
		}
	}
}