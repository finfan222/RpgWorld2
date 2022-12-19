#include "GameSystem.hpp"

void logging::print(LogLevel level, gt::UINT cnt, ...) {
	const source_location loc = source_location::current();
	const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	va_list args;
	va_start(args, cnt);
	gt::STRING str = "";
	for (int i = 0; i < cnt; i++) {
		const char* var = va_arg(args, const char*);
		str.append(var);
	}
	va_end(args);

	switch (level) {
		case logging::LogLevel::INFO:
			BOOST_LOG_TRIVIAL(info) << loc.file_name() << "::"
				<< loc.function_name() << "::("
				<< loc.line() << ":" << loc.column() << "): "
				<< str;
			break;
		case logging::LogLevel::WARN:
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
			BOOST_LOG_TRIVIAL(warning) << loc.file_name() << "::"
				<< loc.function_name() << "::("
				<< loc.line() << ":" << loc.column() << "): "
				<< str;
			SetConsoleTextAttribute(console, 7);
			break;
		case logging::LogLevel::ERR:
			SetConsoleTextAttribute(console, 12);
			BOOST_LOG_TRIVIAL(error) << loc.file_name() << "::"
				<< loc.function_name() << "::("
				<< loc.line() << ":" << loc.column() << "): "
				<< str;
			SetConsoleTextAttribute(console, 7);
			break;
		default:
			throw new exception("Unahndled log level type.");
	};
}

void logging::info(gt::UINT cnt, ...) {
	const source_location loc = source_location::current();
	const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	va_list args;
	va_start(args, cnt);
	gt::STRING str = "";
	for (int i = 0; i < cnt; i++) {
		const char* var = va_arg(args, const char*);
		str.append(var);
	}
	va_end(args);

	BOOST_LOG_TRIVIAL(info) << loc.file_name() << "::"
		<< loc.function_name() << "::("
		<< loc.line() << ":" << loc.column() << "): "
		<< str;
}

void logging::err(gt::UINT cnt, ...) {
	const source_location loc = source_location::current();
	const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	va_list args;
	va_start(args, cnt);
	gt::STRING str = "";
	for (int i = 0; i < cnt; i++) {
		const char* var = va_arg(args, const char*);
		str.append(var);
	}
	va_end(args);

	SetConsoleTextAttribute(console, 12);
	BOOST_LOG_TRIVIAL(error) << loc.file_name() << "::"
		<< loc.function_name() << "::("
		<< loc.line() << ":" << loc.column() << "): "
		<< str;
	SetConsoleTextAttribute(console, 7);
}

void logging::warn(gt::UINT cnt, ...) {
	const source_location loc = source_location::current();
	const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	va_list args;
	va_start(args, cnt);
	gt::STRING str = "";
	for (int i = 0; i < cnt; i++) {
		const char* var = va_arg(args, const char*);
		str.append(var);
	}
	va_end(args);

	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
	BOOST_LOG_TRIVIAL(error) << loc.file_name() << "::"
		<< loc.function_name() << "::("
		<< loc.line() << ":" << loc.column() << "): "
		<< str;
	SetConsoleTextAttribute(console, 7);
}

vector<gt::STRING> gt::STRING::split(STRING delim) {
	vector<STRING> temp;
	return boost::split(temp, *this, boost::is_any_of(delim));
}

const gt::BOOL gt::STRING::contains(STRING value, gt::BOOL ignoreCase) {
	gt::STRING temp = gt::STRING(*this);
	if (ignoreCase) {
		temp.toLower();
		value.toLower();
	}
	return temp.find(value) != string::npos;
}

const gt::BOOL gt::STRING::endsWith(STRING value, gt::BOOL ignoreCase) {
	gt::STRING temp = gt::STRING(*this);
	if (ignoreCase) {
		temp.toLower();
		value.toLower();
	}
	return boost::ends_with(temp, value);
}

const gt::BOOL gt::STRING::startsWith(STRING value, gt::BOOL ignoreCase) {
	gt::STRING temp = gt::STRING(*this);
	if (ignoreCase) {
		temp.toLower();
		value.toLower();
	}
	return boost::starts_with(temp, value);
}

const gt::BOOL gt::STRING::equals(STRING findout, gt::BOOL ignoreCase) {
	gt::STRING temp = gt::STRING(*this);
	if (ignoreCase) {
		temp.toLower();
		findout.toLower();
	}
	return boost::equals(temp, findout);
}

void gt::STRING::replace(STRING from, STRING to) {
	boost::replace_all(*this, from, to);
}

gt::STRING& gt::STRING::toLower() {
	boost::algorithm::to_lower(*this);
	return *this;
}

gt::STRING& gt::STRING::toUpper() {
	boost::algorithm::to_upper(*this);
	return *this;
}

gt::DOUBLE gt::STRING::toDouble() {
	return boost::lexical_cast<gt::DOUBLE>(*this);
}

gt::INT gt::STRING::toInt() {
	return boost::lexical_cast<gt::INT>(*this);
}

gt::FLOAT gt::STRING::toFloat() {
	return boost::lexical_cast<gt::FLOAT>(*this);
}

gt::SHORT gt::STRING::toShort() {
	return boost::lexical_cast<gt::SHORT>(*this);
}

gt::LONG gt::STRING::toLong() {
	return boost::lexical_cast<gt::LONG>(*this);
}

gt::BOOL ui::button(gt::CSTRING title, ImVec2& size) {
	// todo: playe button click sound
	return ImGui::Button(title, size);
}