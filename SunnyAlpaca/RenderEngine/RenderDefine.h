#pragma once

enum CullOption
{
	CullBack = 0,
	CullFront = 1,
	CullOff = 2
};

enum ZTestOption
{
	ZTestLEqual = 0,
	ZTestLess = 1,
	ZTestEqual = 2,
	ZTestGEqual = 3,
	ZTestGreater = 4,
	ZTestAlways = 5
};

enum ZWriteOption
{
	ZWriteOn = 0,
	ZWriteOff = 1,
};

static const char* mainTexture = "_MainTex";
static const char* viewMatrix = "viewMat";
static const char* projMatrix = "projMat";
static const char* modelMatrix = "modelMat";
