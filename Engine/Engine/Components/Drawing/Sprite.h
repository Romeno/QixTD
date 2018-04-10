#pragma once
#include "Engine/Components/Drawing/SpriteBase.h"


class Sprite : public SpriteBase
{
public:
	typedef SpriteBase super;

	class Data : public SpriteBase::Data
	{
	public:
		SDL_Texture*		m_texture;

		std::string			m_path;
	};


	Sprite();
	virtual ~Sprite();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
	virtual void Render() override;

	void SetImage(const std::string& path);
	virtual void SetColor( const glm::ivec4& color ) override;

	virtual glm::drect GetVisualAABB();

	// returns drect in rPos
	virtual glm::drect GetSelectionRegion();

	Data*				m_originalData;			// � ������, ���� ��� ���������� ������� data ����� ����� � ������� ������
	Data*				m_data;
};

