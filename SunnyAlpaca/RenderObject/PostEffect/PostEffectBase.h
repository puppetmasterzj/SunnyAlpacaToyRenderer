#pragma once
#include "../RenderObject.h"

class PostEffectBase : public RenderObject
{
public:
	PostEffectBase();
	virtual ~PostEffectBase();

	virtual void DoRender();
};

