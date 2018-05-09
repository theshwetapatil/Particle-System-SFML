// Particle_System.cpp : Class for the windows application.
// Generative System: Particle System
// Used in Games: FPS, RPG, Platformers, MOBA
// Author: Shweta Patil
// Copyright: Shweta Patil © 2018

#pragma once
#include "Particle_System.h"

extern sf::Texture tex;

void ParticleSystem::setemitter(sf::Vector2f pos)
{
	emitter.setposition(pos);
}

void ParticleSystem::update(float dt)
{
	std::cout << "In particlesystem update!";

	for (int i = 0; i < maxparticle; i++)
	{
		particle[i].setlifetime(particle[i].getlifetime() - 1);

		if (particle[i].getlifetime() < 0)
		{
			resetparticle(i);
		}

		particle[i].update(dt);

		float ratio = particle[i].getlifetime() / maxlifetime;
		sf::Uint8 coloralpha = particle[i].getshape().getFillColor().a;
		sf::Uint8 colorr = particle[i].getshape().getFillColor().r;
		sf::Uint8 colorg = particle[i].getshape().getFillColor().g;
		sf::Uint8 colorb = particle[i].getshape().getFillColor().b;
		coloralpha = coloralpha * ratio * 255;
		particle[i].getshape().setFillColor(sf::Color(colorr, colorg, colorb, coloralpha));
	}
}

void ParticleSystem::resetparticle(int i)
{
	float angle = (std::rand() % 360) * 3.14f / 180.f;
	float speed = (std::rand() % 50) + 50.f;
	particle[i].setvelocity(sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed));
	particle[i].setlifetime(((std::rand() % 2000) + 1000));
	particle[i].setposition(emitter.getposition());			//reset the paticle to starting point
}

int ParticleSystem::getmaxlifetime()
{
	return maxlifetime;
}

int ParticleSystem::getmaxparticle()
{
	return maxparticle;
}

void ParticleSystem::setlifetime(int i)
{
	for (int j = 0; j < maxparticle; j++)
		particle[j].setlifetime(i);
}

void ParticleSystem::setmaxparticle(int i)
{
	if (i >= 0 && i < NUM_PARTICLES) {
		maxparticle = i;
	}
}

void ParticleSystem::settexture(sf::Texture *tex)
{
	for (int i = 0; i < maxparticle; i++)
	{
		if (!((*tex).loadFromFile("spark.png")))
			particle[i].setfillcolor(sf::Color::Yellow);
		else
			particle[i].settexture(tex);
	}
}



sf::CircleShape ParticleSystem::getemittershape()
{
	return emitter.getshape();
}

sf::CircleShape ParticleSystem::getparticleshape(int i)
{
	return particle[i].getshape();
}

Particle& ParticleSystem::getemitter()
{
	return emitter;
}

Particle& ParticleSystem::getparticle(int i)
{
	return particle[i];
}
