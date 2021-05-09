// Mint8.cpp : Defines the entry point for the application.
//

#include "mint8.h"
#include <fstream>

using namespace std;
using namespace config;


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}

mint8::mint8()
{
	//Setting to 0x200 for the first instruction
	program_count_ = start_address;

	//Loading the Font Sets into memory
	for (unsigned int i = 0; i < font_set_size; i++)
	{
		mem_[font_set_start_address + i] = font_set[i];
	}
}

void mint8::read_file(char const* file_name)
{
	ifstream rom_file;
	rom_file.open(file_name);

	if (rom_file.is_open())
	{
		for (int i = 0; i < max_rom_size; i++)
		{
			rom_file >> mem_[i];
			cout << mem_[i] << " ";
		}

		rom_file.close();
	}
	else {
		cerr << "File not found " << file_name << endl;
	}
}
