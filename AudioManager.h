#pragma once
#include "fmod.hpp"
class AudioManager
{
public:
	FMOD::System* system; //virtual sound card
	FMOD::Sound * hitSound, * engineSound, * crashSound, * bGM; //sound -> store sound files
	FMOD::Channel* hitChannel = 0, * engineChannel = 0, * crashChannel = 0, * bGMChannel = 0; //must send sound through a channel -> change volume

	FMOD_RESULT result;
	void* extradriverdata = 0;

	void InitializeAudio();
	void PlayHitSound();
	void PlayEngineSound();
	void PlayCrashSound();
	void PlayBGM();
	void ManipulateEngineSound(D3DXVECTOR2 acceleration)
	void LoadSounds();
	void UpdateSound();

	AudioManager();
	~AudioManager();




};

