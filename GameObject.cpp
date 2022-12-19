#include "GameObject.hpp"

void GameObject::as_info() const {
	logging::info(1, as_string().c_str());
}

gt::STRING GameObject::as_string() const {
	logging::warn(1, "Not defined. Return empty gt::STRING.");
	return "";
}

gt::UINT GameObject::as_size() const {
	return sizeof *this;
}
