#include "util.h"
#include "../opengl/Texture.h"
#include "../opengl/RectRenderer.h"
#include "../common.h"
#include <GL/gl.h>

struct
{
	struct egl egl;
}
data;

const struct egl * init_egl_view(const struct gbm *gbm)
{
	int ret = init_egl(&data.egl, gbm);
	ASSERT_ELSE(ret == 0, return nullptr);
	glViewport(0, 0, gbm->width, gbm->height);
	Texture texture;
	texture.loadFromImage("assets/hedgehog.jpg");
	RectRenderer rectRenderer;
	//rectRenderer.draw(texture, V2d(0, 0), V2d(1, 1));
	return &data.egl;
}


