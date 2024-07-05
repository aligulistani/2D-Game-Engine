#pragma once
#include<vector>
#include<game-engine/Sprite.h>
struct SpriteSheetCollection
{
	
	SpriteSheetCollection(const char* path_to_dir);
	int num_of_spritesheets;
	std::vector<Sprite> spritesheets;
	Sprite* grabSprite(const char* identifer);
};

