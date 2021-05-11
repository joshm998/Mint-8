// Mint8.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <random>

#include "config.h"
using namespace std;

class mint8
{
public:
	void initialize();
	bool read_file(char const* file_name);
	unsigned char screen[64 * 32];
	unsigned char input[16];
	bool draw_flag;
	void emulate_cycle();
private:
	unsigned char reg_[16];
	unsigned char mem_[4096];
	unsigned short index_;
	unsigned short program_count_;
	unsigned char delay_timer_;
	unsigned char sound_timer_;
	unsigned short stack_[16];
	unsigned short op_code_;
	unsigned short stack_pointer_;
};