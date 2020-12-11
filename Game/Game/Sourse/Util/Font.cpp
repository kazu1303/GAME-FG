#include "Font.h"

int Font::pixelM;
int Font::pixelM64;

void Font::LoadFont()
{
	pixelM = LoadFontDataToHandle("Font/PixelMplus.dft", 0);
	pixelM64 = LoadFontDataToHandle("Font/PixelMplus_64.dft", 0);
}
