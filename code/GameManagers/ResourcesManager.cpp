#include "ResourcesManager.h"

ResourcesManager ::ResourcesManager ()
{
  _path = "./assets/";
  _texturePath = "img/";
  _fontPath = "font/";
  _soundPath = "music/";
}

ResourcesManager ::~ResourcesManager ()
{
  for(auto it : _mapTexture){
    if(it.second != nullptr) delete it.second;
  }
  _mapTexture.clear();

  for(auto it : _mapSoundBuffer){
    if(it.second != nullptr) delete it.second;
  }
  _mapSoundBuffer.clear();

  for(auto it : _mapFont){
    if(it.second != nullptr) delete it.second;
  }
  _mapFont.clear();
}

// Texture Resources

void ResourcesManager :: addTexture(string name){
  Texture* texture = new Texture();
  texture->loadFromFile(_path + _texturePath + name + ".png");

  auto it = _mapTexture.find(name);
  if(it != _mapTexture.end()) return;
  _mapTexture.insert(pair<string,Texture*>(name , texture));
}
void ResourcesManager :: removeTexture(string name){
  auto it = _mapTexture.find(name);
  if(it == _mapTexture.end()) return;
  if(it->second != nullptr) delete it ->second;
  _mapTexture.erase(it);
}
Texture* ResourcesManager :: getTexture(string name){
  auto it = _mapTexture.find(name);
  if(it != _mapTexture.end()) return it->second;

  Texture* texture = new Texture();
  texture->loadFromFile(_path + _texturePath + name + ".png");
  _mapTexture.insert(pair<string,Texture*>(name , texture));
  return texture;
}

// SoundBuffer Resources

void ResourcesManager :: addSoundBuffer(string name){
  SoundBuffer* sound = new SoundBuffer();
  sound->loadFromFile(_path + _soundPath + name + ".wav");

  auto it = _mapSoundBuffer.find(name);
  if(it != _mapSoundBuffer.end()) return;
  _mapSoundBuffer.insert(pair<string,SoundBuffer*>(name , sound));
}
void ResourcesManager :: removeSoundBuffer(string name){
  auto it = _mapSoundBuffer.find(name);
  if(it == _mapSoundBuffer.end()) return;
  if(it->second != nullptr) delete it ->second;
  _mapSoundBuffer.erase(it);
}
SoundBuffer* ResourcesManager :: getSoundBuffer(string name){
  auto it = _mapSoundBuffer.find(name);
  if(it != _mapSoundBuffer.end()) return it->second;

  SoundBuffer* sound = new SoundBuffer();
  sound->loadFromFile(_path + _soundPath + name + ".wav");
  _mapSoundBuffer.insert(pair<string,SoundBuffer*>(name , sound));
  return sound;
}

// Font Resources

void ResourcesManager :: addFont(string name){
  Font* font = new Font();
  font->loadFromFile(_path + _fontPath + name + ".TTF");

  auto it = _mapFont.find(name);
  if(it != _mapFont.end()) return;
  _mapFont.insert(pair<string,Font*>(name , font));
}
void ResourcesManager :: removeFont(string name){
  auto it = _mapFont.find(name);
  if(it == _mapFont.end()) return;
  if(it->second != nullptr) delete it ->second;
  _mapFont.erase(it);
}
Font* ResourcesManager :: getFont(string name){
  auto it = _mapFont.find(name);
  if(it != _mapFont.end()) return it->second;

  Font* font = new Font();
  font->loadFromFile(_path + _fontPath + name + ".TTF");
  _mapFont.insert(pair<string,Font*>(name , font));
  return font;
}