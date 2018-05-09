// Particle.h : Header for the windows application.
// Generative System: Particle System
// Used in Games: FPS, RPG, Platformers, MOBA
// Author: Shweta Patil
// Copyright: Shweta Patil © 2018

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <cstring>
#include <cmath>
#include <iostream>

extern sf::Texture tex;

class Particle
{
	private:
		sf::CircleShape simplepoint;
		sf::Vector2f velocity;				//velocity of the particle
		sf::Vector2f gravity;				//gravity of the particle
		sf::Vector2f position;				//position of the particle
		sf::Vector2f origin;				//origin of the particle
		sf::Vector2f radius;				//radius of the particle
		int lifetime;						//lifetime of the particle

	public:
		void update(float dt);
		sf::Vector2f getposition();
		void setposition(sf::Vector2f position);
		sf::Vector2f getorigin();
		void setorigin(sf::Vector2f origin);
		float getradius();
		void setradius(float radius);
		int getlifetime();
		void setlifetime(int lifetime);
		sf::Vector2f getvelocity();
		void setvelocity(sf::Vector2f velocity);
		sf::Vector2f getgravity();
		void setgravity(sf::Vector2f gravity);
		void setfillcolor(sf::Color color);
		void settexture(sf::Texture *tex);
		sf::CircleShape getshape();
};
