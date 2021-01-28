
#include "Stage.h"
#include "DxLib.h"

Stage::Stage()
{
	InitTex();
}

Stage::~Stage()
{
}

void Stage::InitTex()
{
}

void Stage::ReleaseTex()
{
}

void Stage::Clamp(int* value, int min, int max)
{
	if (*value < min)
	{
		*value = min;
	}
	else if (*value > max)
	{
		*value = max;
	}
}

void Stage::GetContactParameter(EdgeType edge_, int chip_id_x_, int chip_id_y_, EdgeType& contact_edge_, int& contact_pos_)
{
	int ChipPosX = chip_id_x_ * MapChipSize;
	int ChipPosY = chip_id_y_ * MapChipSize;

	switch (edge_)
	{
	case EdgeType::Left:
		contact_edge_ = EdgeType::Right;
		contact_pos_ = ChipPosX + MapChipSize;
		break;
	case EdgeType::Right:
		contact_edge_ = EdgeType::Left;
		contact_pos_ = ChipPosX;
		break;
	case EdgeType::Top:
		contact_edge_ = EdgeType::Bottom;
		contact_pos_ = ChipPosY + MapChipSize;
		break;
	case EdgeType::Bottom:
		contact_edge_ = EdgeType::Top;
		contact_pos_ = ChipPosY;
		break;
	}
}

bool Stage::CheckHit(int left_, int top_, int right_, int bottom_, int vector_x_, int vector_y_, EdgeType& contact_egde_, int contact_edge_pos_)
{
	int RectLeft = left_;
	int RectTop = top_;
	int RectBottom = bottom_;
	int RectRight = right_;

	RectLeft += vector_x_;
	RectTop += vector_y_;
	RectBottom += vector_y_;
	RectRight += vector_x_;

	RectRight -= 1;
	RectBottom -= 1;

	int WidthRangeIDs[]
	{
		(int)(RectLeft / MapChipSize),
		(int)(RectRight / MapChipSize)
	};

	int HeightRangeIDs[]
	{
		(int)(RectTop / MapChipSize),
		(int)(RectBottom / MapChipSize)
	};

	const int MaxRangeIDs[]
	{
		MaxMapHeight - 1,
		MaxMapWidth - 1,
	};

	for (int i = 0; i < 2; i++)
	{
		Clamp(&HeightRangeIDs[i], 0, MaxRangeIDs[0]);
		Clamp(&WidthRangeIDs[i], 0, MaxRangeIDs[1]);
	}

	const int start = 0;
	const int end = 1;

	int EdgeListX[(int)EdgeType::Max][2]
	{
		{
			int(WidthRangeIDs[start]), int(WidthRangeIDs[start])
		},
		{
			int(WidthRangeIDs[end]), int(WidthRangeIDs[end])
		},
		{
			int(WidthRangeIDs[start]), int(WidthRangeIDs[end])
		},
		{
			int(WidthRangeIDs[start]), int(WidthRangeIDs[end])
		},
	};

	int EdgeListY[(int)EdgeType::Max][2]
	{
		{
			int(HeightRangeIDs[start]), int(HeightRangeIDs[end])
		},
		{
			int(HeightRangeIDs[start]), int(HeightRangeIDs[end])
		},
		{
			int(HeightRangeIDs[start]), int(HeightRangeIDs[start])
		},
		{
			int(HeightRangeIDs[end]), int(HeightRangeIDs[end])
		},
	};

	bool IsUseEdgeList[(int)EdgeType::Max]
	{
		vector_x_ < 0 ? true : false,
		vector_x_ > 0 ? true : false,
		vector_y_ < 0 ? true : false,
		vector_y_ > 0 ? true : false,
	};

	for (int i = 0; i < (int)EdgeType::Max; i++)
	{
		if (IsUseEdgeList[i] == false)
		{
			continue;
		}

		for (int y = EdgeListY[i][start]; y <= EdgeListY[i][end]; y++)
		{
			for (int x = EdgeListX[i][start]; x <= EdgeListX[i][end]; x++)
			{
				if (m_Stage[y][x] == 1)
				{
					GetContactParameter((EdgeType)i, x, y, contact_egde_, contact_edge_pos_);

					return true;
				}
			}
		}
	}

	return false;
}

void Stage::Draw(Camera camera)
{
	for (int y = 0; y < MaxMapHeight; y++)
	{
		for (int x = 0; x < MaxMapWidth; x++)
		{
			int DrawPosX = camera.ConvertPosXWorldToScreen(x * MapChipSize);
			int DrawPosY = camera.ConvertPosYWorldToScreen(y * MapChipSize);

			if (m_Stage[y][x] == (int)ObjectType::Ground)
			{
				DrawBox(DrawPosX, DrawPosY, DrawPosX + MapChipSize, DrawPosY + MapChipSize, GetColor(100, 90, 90), TRUE);
			}
			else if (m_Stage[y][x] == (int)ObjectType::Wall)
			{
				DrawBox(DrawPosX, DrawPosY, DrawPosX + MapChipSize, DrawPosY + MapChipSize, GetColor(200, 255, 200), TRUE);
			}
			else if (m_Stage[y][x] == (int)ObjectType::Goal)
			{
				DrawBox(DrawPosX, DrawPosY, DrawPosX + MapChipSize, DrawPosY + MapChipSize, GetColor(255, 230, 200), TRUE);
			}
			
		}
	}
}
