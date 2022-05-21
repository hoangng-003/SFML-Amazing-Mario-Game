#pragma once

#include "Singleton.h"
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../GameConfig.h"
#include "../GameObjects/GameButton.h"

#define DATA ResourcesManager :: GetInstance()
#define GSM GameStateMachine::GetInstance()

using namespace std;
using namespace sf;

class ResourcesManager : public CSingleton<ResourcesManager>
{
private:
  map<string, Texture*> _mapTexture;
  map<string, Font*> _mapFont;
  map<string, SoundBuffer*> _mapSoundBuffer;


  string _path;
  string _texturePath;
  string _fontPath;
  string _soundPath;

public:
  ResourcesManager ();
  ~ResourcesManager ();

  void addTexture(string name);
  void removeTexture(string name);
  Texture* getTexture(string name);

  void addFont(string name);
  void removeFont(string name);
  Font* getFont(string name);

  void addSoundBuffer(string name);
  void removeSoundBuffer(string name);
  SoundBuffer* getSoundBuffer(string name);
};
