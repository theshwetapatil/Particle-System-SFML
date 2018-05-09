// Particle.cpp : Class for the windows application.
// Generative System: Particle System
// Used in Games: FPS, RPG, Platformers, MOBA
// Author: Shweta Patil
// Copyright: Shweta Patil © 2018

#pragma once
#include "Particle.h"

extern sf::Texture tex;

void Particle::update(float dt)
{
	velocity += gravity * dt;

	position += velocity * dt;

	simplepoint.setPosition(position);
}

sf::Vector2f Particle::getposition()
{
	return simplepoint.getPosition();
}

void Particle::setposition(sf::Vector2f position)
{
	simplepoint.setPosition(position);
	this->position = position;
}

sf::Vector2f Particle::getorigin()
{
	return simplepoint.getOrigin();
}

void Particle::setorigin(sf::Vector2f origin)
{
	simplepoint.setOrigin(origin);
}

float Particle::getradius()
{
	return simplepoint.getRadius();
}

void Particle::setradius(float radius)
{
	simplepoint.setRadius(radius);
}

int Particle::getlifetime()
{
	return this->lifetime;
}

void Particle::setlifetime(int lifetime)
{
	this->lifetime = lifetime;
}

sf::Vector2f Particle::getvelocity()
{
	return velocity;
}

void Particle::setvelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

sf::Vector2f Particle::getgravity()
{
	return gravity;
}

void Particle::setgravity(sf::Vector2f gravity)
{
	this->gravity = gravity;
}

void Particle::setfillcolor(sf::Color color)
{
	simplepoint.setFillColor(color);
}

void Particle::settexture(sf::Texture *tex)
{
	if (!((*tex).loadFromFile("spark.png")))
		simplepoint.setFillColor(sf::Color::Green);
	else
		simplepoint.setTexture(tex);
}

sf::CircleShape Particle::getshape()
{
	return simplepoint;
}