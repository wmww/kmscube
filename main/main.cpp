#include <unistd.h>
#include <iostream>
 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../opengl/Texture.h"
#include "../opengl/RectRenderer.h"
#include "../Backend.h"

// change to toggle debug statements on and off
#define debug debug_off

unique_ptr<Backend> Backend::instance;

int main (int argc, char ** argv)
{
	debug("setting up backend");
	Backend::setup();
	ASSERT_ELSE(Backend::instance, exit(1));
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glewInit();
	
	auto texture = Texture();
	texture.loadFromImage("assets/hedgehog.jpg");
	RectRenderer renderer;
	
	debug("starting main loop");
	while (Backend::instance)
	{
		renderer.draw(texture, V2d(0, 0), V2d(1, 1));
		Backend::instance->swapBuffer();
		sleepForSeconds(0.01667);
		Backend::instance->checkEvents();
	}
	
	debug("exiting");
}