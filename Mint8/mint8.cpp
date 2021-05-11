// Mint8.cpp : Defines the entry point for the application.
//

#include "mint8.h"
#include <chrono>
#include <fstream>

using namespace std;
using namespace config;




void mint8::initialize()
{
	//Setting to 0x200 for the first instruction
	program_count_ = start_address;
	op_code_ = 0;
	index_ = 0;
	stack_pointer_ = 0;

	//Clear Arrays
	memset(screen, 0, sizeof(screen));
	memset(stack_, 0, sizeof(stack_));
	memset(reg_, 0, sizeof(reg_));
	memset(mem_, 0, sizeof(mem_));

	//Loading the Font Sets into memory
	for (unsigned int i = 0; i < font_set_size; i++)
		mem_[font_set_start_address + i] = font_set[i];

	//Resetting Timers
	delay_timer_ = 0;
	sound_timer_ = 0;
	

}

void mint8::emulate_cycle()
{
	op_code_ = mem_[program_count_] << 8 | mem_[program_count_ + 1];

	switch (op_code_ & 0x0FFF)
	{
	case 0xA000:
		index_ = op_code_ & 0x0FFF;
		program_count_ += 2;
		break;
		
	default:
		printf("opcode not found: 0x%X\n", op_code_);
	}

	//Update the Timers
	if(delay_timer_ > 0)
	{
		--delay_timer_;
	}

	if (sound_timer_ > 0)
	{
		if(sound_timer_ == 1)
		{
			printf("BEEP!\n");
			--sound_timer_;
		}
	}
}


bool mint8::read_file(char const* file_name)
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
		return true;
	}
	
	cerr << "File not found " << file_name << endl;
	return false;

}
