#include "Font.h"

int Font::pixelM16;
int Font::pixelM32;
int Font::pixelM64;
int Font::pixelM96;
int Font::pixelM128;

void Font::LoadFont()
{
	pixelM16 = LoadFontDataToHandle("Font/PixelMplus_16.dft", 0);
	pixelM32 = LoadFontDataToHandle("Font/PixelMplus_32.dft", 0);
	pixelM64 = LoadFontDataToHandle("Font/PixelMplus_64.dft", 0);
	pixelM96 = LoadFontDataToHandle("Font/PixelMplus_96.dft", 0);
	pixelM128 = LoadFontDataToHandle("Font/PixelMplus_128.dft", 0);
}
