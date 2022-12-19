#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "GameSys.h"

class GameObject {
public:
	/*������� ���������� � ���� ����������� ��� ���������� __as_string*/
	virtual void __as_info() const;
	/*������������ ������� ������ � ���� gt::STRING*/
	virtual gt::STRING __as_string() const;
	/*����������� �������� �������*/
	virtual gt::UINT __size() const;
};

#endif
