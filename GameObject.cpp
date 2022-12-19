#include "GameObject.h"

void GameObject::__as_info() const {
	logging::info(1, __as_string().c_str());
}

gt::STRING GameObject::__as_string() const {
	logging::warn(1, "Not defined. Return empty gt::STRING.");
	return "";
}

gt::UINT GameObject::__size() const {
	return sizeof *this;
}
