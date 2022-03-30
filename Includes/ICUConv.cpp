/*
    YACardEmu
    ----------------
    Copyright (C) 2022 wutno (https://github.com/GXTX)


    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "ICUConv.h"

ICUConv::ICUConv()
{
	// TODO: Check error
	ucnv = ucnv_open("Windows-31J", &err);
}

ICUConv::~ICUConv()
{
	ucnv_close(ucnv);
}

bool ICUConv::convertAndPrint(std::vector<uint8_t> &in)
{
#if 0
	std::string incoming(in.begin(), in.end());

	char16_t buffer[255];

	// TODO: Check error
	ucnv_toUChars(ucnv, buffer, 255, incoming.c_str(), incoming.size(), &err);

	std::u16string u16(buffer);

	std::vector<std::u16string> lineMessage{};
	lineMessage.resize(15);

	int line = 0;
	for (const char16_t c : u16) {
		if (c == 0x11 || c == 0x14) // FIXME: We need to make certain things happen with control chars
			continue;

		lineMessage.at(line).append(&c);

		if (c == 0x0D)
		line++;
	}

	TTF_Init();
	TTF_Font *font = TTF_OpenFont("unifont_jp.ttf", 42);
	SDL_Color color = {0x0, 0x0, 0x0, 0xFF};
	SDL_Surface *cardImage = IMG_Load("2.png");

	int virt = 100;

	for (const std::u16string &t : lineMessage) {
		if (t.empty() || t.at(0) == 0x0D)
			continue;

		SDL_Surface *textSurf = TTF_RenderUNICODE_Blended_Wrapped(font, (const uint16_t *)t.c_str(), color, 1024);

		SDL_Rect location = {100, virt, 0, 0};

		SDL_BlitSurface(textSurf, NULL, cardImage, &location);
		SDL_FreeSurface(textSurf);

		virt += 45;
	}

	IMG_SavePNG(cardImage, "file.png");

	SDL_FreeSurface(cardImage);
	TTF_Quit();
#endif

	return true;
}