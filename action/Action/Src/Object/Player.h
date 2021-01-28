
#ifndef PLAYER_H
#define PLAYER_H

#include "../Function/Camera.h"
#include "../Stage/Stage.h"

class Player
{
private:
	static const int TexMax = 22;
	float m_PosX;
	float m_PosY;
	float m_PrevPosX;
	float m_PrevPosY;
	float m_MoveSpeed;
	float m_JumpVelosity;
	int m_Tex;

	bool m_IsFloatingAir;

public:
	Player();
	~Player();

	void Update(Stage stage);
	void Draw(Camera camera);

	void SetPos(float x_, float y_);
	void SetMoveSpeed(float speed_);
	void SetJumpVelocity(float velocity_);

	float GetPosX()			const { return m_PosX; }
	float GetPosY()			const { return m_PosY; }
	float GetMoveSpeed()	const { return m_MoveSpeed; }
	float GetJumpVelocity() const { return m_JumpVelosity; }

	void InitTexture();
	void ReleaseTexture();

	void AdjustToMapChipEdgePosition(EdgeType contact_edge_, int contact_pos_);
};

#endif // !PLAYER_H
