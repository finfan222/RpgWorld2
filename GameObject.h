#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "GameSys.h"

class GameObject {
public:
	/*Выводит информацию в виде логирования где принтуется __as_string*/
	virtual void __as_info() const;
	/*Представляет игровой объект в виде gt::STRING*/
	virtual gt::STRING __as_string() const;
	/*Размерность игрового объекта*/
	virtual gt::UINT __size() const;
};

#endif
