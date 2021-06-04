
#ifndef DIFINITION_H
#define DIFINITION_H

static const int WindowWidth = 1024;
static const int WindowHeight = 512;
static const int WindowHalfWidth = WindowWidth / 2;
static const int WindowHalfHeight = WindowHeight / 2;

static const int MapChipSize = 32;

static const int MaxMapWidth = (WindowWidth / MapChipSize) * 2;
static const int MaxMapHeight = WindowHeight / MapChipSize;

static const int FieldWidth = MapChipSize * MaxMapWidth;
static const int FieldHeight = MapChipSize * MaxMapHeight;

static const int g_Gravity = 1;

enum class ObjectType
{
	Ground,
	Wall,
	Goal,
};

enum class EdgeType
{
	Left,
	Right,
	Top,
	Bottom,

	Max,
	Invalid = -1,
};

#endif // !DIFINITION_H
