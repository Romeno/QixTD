#pragma once



class BattleObjectInfo
{
public:
	BattleObjectInfo();
	virtual ~BattleObjectInfo();

	std::string		m_objectName;
	int				m_objectId;
	std::string		m_objectPathing;
};

