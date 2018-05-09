// main.cpp : Defines the entry point for the windows application.
// Generative System: Particle System
// Used in Games: FPS, RPG, Platformers, MOBA
// Author: Shweta Patil
// Copyright: Shweta Patil © 2018
#pragma once
#include "Particle_System.h"

sf::Texture tex;
sf::RenderWindow window(sf::VideoMode(800, 600), "Particle Effect!");

Particle particle;
ParticleSystem particles;
ParticleSystem particles2;

void update_state(float dt)
{
	particle.update(dt);
	particles.update(dt);
	particles2.update(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		particles.setmaxparticle(particles.getmaxparticle() + 1);
}

void render_frame()
{
	window.clear();

	window.draw(particle.getshape());
	for (int i = 1; i < particles.getmaxparticle(); i++)
		window.draw(particles.getparticleshape(i));
	window.draw(particles.getparticleshape(0));
	window.draw(particles.getemittershape());

	window.draw(particles2.getemitter().getshape());
	for (int i = 0; i < particles2.getmaxparticle(); i++)
		window.draw(particles2.getparticleshape(i));
}

int main()
{
	//Initialize emitter location
	particles.getemitter().setradius(1.f);
	particles.getemitter().setorigin(sf::Vector2f(10, 10));
	particles.getemitter().setposition(sf::Vector2f(500, 300));
	particles.getemitter().setfillcolor(sf::Color::Red);

	//Initialize particles in particle system
	for (int i = 0; i < NUM_PARTICLES; i++)
	{
		particles.getparticle(i).setradius(1.f);
		particles.getparticle(i).setorigin(particles.getemitter().getorigin());
		particles.getparticle(i).setposition(particles.getemitter().getposition());
		particles.getparticle(i).setlifetime(100);
		particles.getparticle(i).setvelocity(sf::Vector2f((float)2*i, 0.0));
		particles.getparticle(i).setgravity(sf::Vector2f(0.0, 50.));
		particles.getparticle(i).setfillcolor(sf::Color::Green);
	}

	//Initialize emitter for second particle system
	particles2.getemitter().setradius(50.f);
	particles2.getemitter().setorigin(sf::Vector2f(10, 10));
	particles2.getemitter().setposition(sf::Vector2f(150, 300));
	particles2.getemitter().settexture(&tex);

	//Initialize particles in second particle system
	for (int i = 0; i < particles2.getmaxparticle(); i++)
	{
		particles2.getparticle(i).setradius(50.f);
		particles2.getparticle(i).setorigin(particles2.getemitter().getorigin());
		particles2.getparticle(i).setposition(particles2.getemitter().getposition());
		particles2.getparticle(i).setlifetime(100);
		particles2.getparticle(i).setgravity(sf::Vector2f(0.0, 100.));
		particles2.getparticle(i).setvelocity(sf::Vector2f((float)-i*2, 0.0));
		particles2.getparticle(i).settexture(&tex);
	}

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float dt = clock.restart().asSeconds();

		window.clear();

		// Draw all particles in first system
		window.draw(particles.getemitter().getshape());
		for (int i = 0; i < particles.getmaxparticle(); i++) {
			window.draw(particles.getparticleshape(i));
		}

		window.draw(particles2.getemitter().getshape());
		for (int i = 0; i < particles2.getmaxparticle(); i++) {
			window.draw(particles2.getparticleshape(i));
		}

		update_state(dt);
		render_frame();
		window.display();
	}

	return 0;
}


