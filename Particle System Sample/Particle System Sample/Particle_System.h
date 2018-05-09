// Particle_System.h : Header for the windows application.
// Generative System: Particle System
// Used in Games: FPS, RPG, Platformers, MOBA
// Author: Shweta Patil
// Copyright: Shweta Patil © 2018

#pragma once
#include "Particle.h"

#define NUM_PARTICLES 50
extern sf::Texture tex;

class ParticleSystem
{
	private:
		Particle particle[NUM_PARTICLES];		//single particle
		int maxparticle = 10;					//maximum number of particles in a single system
		int maxlifetime = 20;					//maximum lifetime of each particle
		Particle emitter;						//emitter for the particles in the system

	public:
		void setemitter(sf::Vector2f pos);
		void update(float dt);
		void resetparticle(int i);
		int getmaxparticle();
		int getmaxlifetime();
		void setlifetime(int i);
		void setmaxparticle(int i);
		void settexture(sf::Texture *tex);
		sf::CircleShape getemittershape();
		sf::CircleShape getparticleshape(int i);
		Particle& getemitter();
		Particle& getparticle(int i);
};

