/*
#include "../main/util.h"
#include <linux/input.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <poll.h>

// change to toggle debug statements on and off
#define debug debug_off

struct BackendEGL
{
	EGLDisplay eglDisplay;
	EGLConfig config;
	EGLContext windowContext;
	EGLSurface windowSurface;
	
	BackendEGL()
	{
		
	}
	
	~BackendEGL()
	{
		warning("~BackendEGL not implemented");
	}
	
	void swapBuffer()
	{
		eglSwapBuffers(eglDisplay, windowSurface);
	}
};

unique_ptr<Backend> Backend::makeEGL(V2i dim)
{
	return make_unique<BackendEGL>(dim);
}
*/
