#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "GameSystem.hpp"

class GameObject {
public:
	/*������� ���������� � ���� ����������� ��� ���������� __as_string*/
	virtual void as_info() const;
	/*������������ ������� ������ � ���� gt::STRING*/
	virtual gt::STRING as_string() const;
	/*����������� �������� �������*/
	virtual gt::UINT as_size() const;
};

#endif
