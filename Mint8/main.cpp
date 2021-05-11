
#include "mint8.h"

mint8 chip8;

int main(int argc, char **argv)
{
	//setupGraphics();
	//setupInput();

	//Init system
	chip8.initialize();
	chip8.read_file("");

	for(;;)
	{
		//chip8.emulateCycle();

		//if(chip8.draw_flag)
			//Drawing Goes Here

		// Set Keys here
	}
}