// Mint8.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "config.h"

class mint8
{
public:
	mint8();
	void read_file(char const* file_name);
private:
	uint8_t reg_[16]{};
	uint8_t mem_[4096]{};
	uint16_t index_{};
	uint16_t program_count_{};
	uint8_t delay_timer_{};
	uint8_t sound_timer_{};
	uint8_t buttons_[16]{};
	uint32_t display_[64 * 32]{};
	uint16_t op_code_;
};