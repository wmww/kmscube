#include "util.h"
#include "../opengl/Texture.h"
#include "../opengl/RectRenderer.h"
#include "../common.h"
#include <GL/gl.h>

// change to toggle debug statements on and off
#define debug debug_on

struct
{
	struct egl egl;
	Texture texture;
	shared_ptr<RectRenderer> rectRenderer;
}
data;

void draw(unsigned i)
{
	debug(FUNC + " called");
	ASSERT(data.texture.isValid());
	ASSERT(data.rectRenderer);
	data.rectRenderer->draw(data.texture, V2d(0, 0), V2d(1, 1));
}

const struct egl * init_egl_view(const struct gbm *gbm)
{
	int ret = init_egl(&data.egl, gbm);
	ASSERT_ELSE(ret == 0, return nullptr);
	glViewport(0, 0, gbm->width, gbm->height);
	data.texture.loadFromImage("assets/hedgehog.jpg");
	data.rectRenderer = make_shared<RectRenderer>();
	data.egl.draw = draw;
	return &data.egl;
}


