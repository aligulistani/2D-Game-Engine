#include<game-engine/main.h>

SpriteSheetCollection::SpriteSheetCollection(const char* path_to_dir) {
	for(const auto& entry : std::filesystem::directory_iterator(path_to_dir)){
		this->num_of_spritesheets += 1;

		//this->spritesheets.push_back(Sprite(entry.path().string().c_str(),NULL, entry.path().filename().string().c_str()));
	};
};

Sprite* SpriteSheetCollection::grabSprite(const char* identifer) {
	for (int i = 0; i < this->spritesheets.size(); i++) {
		if (this->spritesheets[i].identifer == identifer) {
			return &this->spritesheets[i];
		}
	}
	return NULL;
}