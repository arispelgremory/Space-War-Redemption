#include "AudioManager.h"
#include <iostream>
using namespace std;

void AudioManager::InitializeAudio()
{
	result = FMOD::System_Create(&system);
	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
}

void AudioManager::PlayHitSound()
{
	result = system->playSound(hitSound, 0, false, &hitChannel);
	float freq;
	hitChannel->getFrequency(&freq);
	std::cout << freq << std::endl;
	hitChannel->setFrequency(40000);
	hitChannel->setVolume(1);
	hitChannel->setPitch(1.5);
}

void AudioManager::PlayEngineSound() 
{
	result = system->playSound(engineSound, 0, false, &engineChannel);
	engineChannel->setVolume(1);

}

void AudioManager::PlayCrashSound()
{
	result = system->playSound(crashSound, 0, false, &crashChannel);
	crashChannel->setVolume(1);

}

void AudioManager::PlayBGM()
{
	result = system->playSound(bGM, 0, false, &bGMChannel);
	bGMChannel->setVolume(1);
	bGMChannel->setPitch(0.5);
}

void AudioManager::ManipulateEngineSound(D3DXVECTOR2 acceleration)
{
	if (acceleration == D3DXVECTOR2(0, 0))
	{
		result = engineChannel->setPaused(true);
	}
	else
	{
		result = engineChannel->setPaused(false);
	}
}

void AudioManager::LoadSounds()
{
	result = system->createSound("Assets/Audio/spaceship_collision.wav", FMOD_CREATESAMPLE, 0, &hitSound);
	if (result != FMOD_OK) {
		cout << "collision sound failed" << endl;
	}
	result = hitSound->setMode(FMOD_LOOP_OFF);

	result = system->createSound("Assets/Audio/spaceship_engine.wav", FMOD_CREATESAMPLE, 0, &engineSound);
	if (result != FMOD_OK) {
		cout << "engine sound failed" << endl;
	}
	result = engineSound->setMode(FMOD_LOOP_OFF);

	result = system->createSound("Assets/Audio/spaceship_crash.wav", FMOD_CREATESAMPLE, 0, &crashSound);
	if (result != FMOD_OK) {
		cout << "crash sound failed" << endl;
	}
	result = crashSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("Assets/Audio/heart-of-the-universe.aiff", FMOD_DEFAULT, 0, &bGM);
	if (result != FMOD_OK) {
		cout << "bgm failed" << endl;
	}
	result = bGM->setMode(FMOD_LOOP_NORMAL);
}

void AudioManager::UpdateSound()
{
	result = system->update();
}

AudioManager::AudioManager()
{
}

AudioManager::~AudioManager()
{
}
