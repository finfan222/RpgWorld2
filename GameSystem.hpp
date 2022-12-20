#ifndef GAME_SYS_HPP
#define GAME_SYS_HPP

// need for boost logging
#ifdef	_WIN32
#define _WIN32_WINNT   0x0601
#endif

#include <SDKDDKVer.h>

// System imports
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <math.h>
#include <cstdlib>
#include <chrono>
#include <ctime> 
#include <map>
#include <vector>
#include <type_traits>
#include <list>
#include <cstdarg>
#include <WinSock2.h>
#include <iomanip>
#include <codecvt>
#include <cstddef>
#include <bitset>
#include <algorithm>
#include <string_view>
#include <source_location>

// Boost imports
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/container/list.hpp>
#include <boost/optional.hpp>
#include <boost/filesystem.hpp>
#include <boost/stacktrace.hpp>
#include <boost/log/trivial.hpp>

// SFML imports
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

// Im Gui imports
#include "imgui.h"
#include "imgui-SFML.h"

using namespace std;

/////////////////////// Game types
namespace gt {
	// Basic
	using SHORT = int16_t;
	using INT = int32_t;
	using LONG = int64_t;
	using USHORT = uint16_t;
	using UINT = uint32_t;
	using ULONG = uint64_t;
	using DOUBLE = double_t;
	using FLOAT = float_t;
	using CSTRING = const char*;
	using CHAR = char;
	using BYTE = std::byte;
	using BOOL = bool;
	using CBOOL = bool*;

	// Network
	using PACKET = sf::Packet;

	// ImGui
	using IM_VEC2 = ImVec2;
	using IM_VEC4 = ImVec4;

	// SFML
	using VECTOR_2F = sf::Vector2f;
	using VECTOR_2I = sf::Vector2i;
	using VECTOR_2U = sf::Vector2u;
	using GAME_RENDER_SCENE = sf::RenderWindow;
	using GAME_VIDEO_MODE = sf::VideoMode;
	using GAME_VIEW_PORT = sf::View;
	using MUSIC_STAT = sf::Music::Status;
	using SOUND_STAT = sf::Sound::Status;
	using TEXTURE = sf::Texture;
	using SPRITE = sf::Sprite;

	class STRING : public string {
	public:
		using string::string; // findout: непонятно что это и как работает, но работает

		vector<STRING> split(STRING delim);
		const gt::BOOL contains(STRING value, gt::BOOL ignoreCase = true);
		const gt::BOOL endsWith(STRING value, gt::BOOL ignoreCase = true);
		const gt::BOOL startsWith(STRING value, gt::BOOL ignoreCase = true);
		const gt::BOOL equals(STRING findout, gt::BOOL ignoreCase = true);
		void replace(STRING from, STRING to);
		STRING& toLower();
		STRING& toUpper();
		gt::DOUBLE toDouble();
		gt::INT toInt();
		gt::FLOAT toFloat();
		gt::SHORT toShort();
		gt::LONG toLong();
	};
}

/////////////////////// Constant expressions
namespace consts {
	constexpr gt::CSTRING GAME_NAME1 = "My New Game";
	constexpr gt::CSTRING PNG_EXT1 = ".png";
	constexpr gt::CSTRING OGG_EXT1 = ".ogg";
	constexpr gt::CSTRING WAV_EXT1 = ".wav";
	constexpr gt::UINT RESOULTION[5][2] =
	{
		{640,480},
		{800,600},
		{1024,768},
		{1600,900},
		{1920,1080}
	};

	constexpr gt::UINT INVENTORY_WIDTH = 288;
	constexpr gt::UINT INVENTORY_HEIGHT = 320;
	constexpr gt::UINT INVENTORY_ITEM_SIZE = 32;
	constexpr gt::UINT INVENTORY_COLUMNS = (INVENTORY_WIDTH / INVENTORY_ITEM_SIZE - 2);
	constexpr gt::UINT INVENTORY_ROWS = (INVENTORY_HEIGHT / INVENTORY_ITEM_SIZE);
}

/////////////////////// Logging project
namespace logging {
	enum class LogLevel {
		INFO,
		WARN,
		ERR
	};
	/*Принтует текст с нужным уровнем логирования*/
	void print(LogLevel level = LogLevel::INFO, gt::UINT cnt = 0, ...);
	/*Принтует текст с INFO логированием*/
	void info(gt::UINT cnt = 0, ...);
	/*Принтует текст с ERROR логированием*/
	void err(gt::UINT cnt = 0, ...);
	/*Принтует текст с WARN логированием*/
	void warn(gt::UINT cnt = 0, ...);
}

/////////////////////// UI optimize works
namespace ui {
	/*
	Кнопка с внутренней default игровой-механикой: звук щелчка. Возвращает gt::BOOL.
	*/
	gt::BOOL button(gt::CSTRING title, ImVec2& size);

	/////////////////////// ImGui WINDOW FLAG
	namespace wnd {
		constexpr gt::UINT None = ImGuiWindowFlags_None;
		/*Отключает скроллбары сам UI (но прокрутка мышью или програмным путём до сих пор возможна)*/
		constexpr gt::UINT Unscroll = ImGuiWindowFlags_NoScrollbar;
		/*Отключает возможность передвигать окошко*/
		constexpr gt::UINT Unmove = ImGuiWindowFlags_NoMove;
		/*Не имеет title в окошке*/
		constexpr gt::UINT Untitle = ImGuiWindowFlags_NoTitleBar;
		/*Нельзя ресайзить (изменять размер)*/
		constexpr gt::UINT Unresize = ImGuiWindowFlags_NoResize;
		/*Нельзя сворачивать окошко*/
		constexpr gt::UINT Uncollapse = ImGuiWindowFlags_NoCollapse;
		/*Запрещает кроллить окно за счёт мышки*/
		constexpr gt::UINT UnscrollWithMouse = ImGuiWindowFlags_NoScrollWithMouse;
		/*Всегда автоматически ресайзить*/
		constexpr gt::UINT AutoResize = ImGuiWindowFlags_AlwaysAutoResize;
		/*Отключить бэкграунд в окошке*/
		constexpr gt::UINT Unbackground = ImGuiWindowFlags_NoBackground;
		/*Не сохранять текущие координаты и размеры окна (расположение и прочее)*/
		constexpr gt::UINT Unsaveable = ImGuiWindowFlags_NoSavedSettings;
		/*Отключить ловлю мыши, тест зависания с пропуском.*/
		constexpr gt::UINT NoMouseInputs = ImGuiWindowFlags_NoMouseInputs;
		/*Включает menubar в окошке.*/
		constexpr gt::UINT MenuBar = ImGuiWindowFlags_MenuBar;
		/*Включает горизонтальный скроллбар.*/
		constexpr gt::UINT HorizontalScrollbar = ImGuiWindowFlags_HorizontalScrollbar;
		/*Не фокусироваться на окне (не выставлят ьв топ окошек) в случае появления/открытия.*/
		constexpr gt::UINT NoFocusOnAppearing = ImGuiWindowFlags_NoFocusOnAppearing;
		/*Отключить вывод окна на передний план при наведении фокуса (например, при нажатии на него или программном назначении ему фокуса)*/
		constexpr gt::UINT NoBringToFrontOnFocus = ImGuiWindowFlags_NoBringToFrontOnFocus;
		/*Всегда показывать вертикальную полосу прокрутки (даже если ContentSize.y < Size.y)*/
		constexpr gt::UINT AlwaysVerticalScrollbar = ImGuiWindowFlags_AlwaysVerticalScrollbar;
		/*Всегда показывать горизонтальную полосу прокрутки (даже если ContentSize.y < Size.y)*/
		constexpr gt::UINT AlwaysHorizontalScrollbar = ImGuiWindowFlags_AlwaysHorizontalScrollbar;
		/*Убедитесь, что дочерние окна без рамки используют style.WindowPadding (по умолчанию игнорируется для дочерних окон без рамки, так как это удобнее)*/
		constexpr gt::UINT AlwaysUseWindowPadding = ImGuiWindowFlags_AlwaysUseWindowPadding;
		/*Нет навигации с помощью геймпада/клавиатуры в окне*/
		constexpr gt::UINT NoNavInputs = ImGuiWindowFlags_NoNavInputs;
		/*Не фокусируется на этом окне при навигации с помощью геймпада/клавиатуры (например, пропускается с помощью CTRL+TAB)*/
		constexpr gt::UINT NoNavFocus = ImGuiWindowFlags_NoNavFocus;
		/*Поставьте точку рядом с заголовком. При использовании в контексте вкладки/стыковки вкладка выбирается при нажатии X + закрытие не предполагается (будет ждать, пока пользователь прекратит отправку вкладки). В противном случае предполагается закрытие при нажатии X, поэтому, если вы продолжите отправку, вкладка может снова появиться в конце панели вкладок.*/
		constexpr gt::UINT UnsavedDocument = ImGuiWindowFlags_UnsavedDocument;
		/*ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus*/
		constexpr gt::UINT NoNav = ImGuiWindowFlags_NoNav;
		/*ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse*/
		constexpr gt::UINT NoDecoration = ImGuiWindowFlags_NoDecoration;
		/*ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus*/
		constexpr gt::UINT NoInputs = ImGuiWindowFlags_NoInputs;
	}

	/////////////////////// ImGui TABLE FLAG
	namespace table {
		constexpr gt::UINT None = ImGuiTableFlags_None;
		/*Отрисовка всех границ*/
		constexpr gt::UINT Bordered = ImGuiTableFlags_Borders;
		/*Включает размерность колонок*/
		constexpr gt::UINT Resizable = ImGuiTableFlags_Resizable;
		/*Включает переопределение колонок (нужно чтобы был включен TableSetupColumns + TableHeadersRow*/
		constexpr gt::UINT Reorderable = ImGuiTableFlags_Reorderable;
		/*Позволяет скрывать/показывать колонки*/
		constexpr gt::UINT Hideable = ImGuiTableFlags_Hideable;
		/*Включить сортировку. Вызовите TableGetSortSpecs(), чтобы получить спецификации сортировки. См. также ImGuiTableFlags_SortMulti и ImGuiTableFlags_SortTristate.*/
		constexpr gt::UINT Sortable = ImGuiTableFlags_Sortable;
		/*Отключите сохранение порядка столбцов, ширины и параметров сортировки в файле .ini.*/
		constexpr gt::UINT NoSavedSettings = ImGuiTableFlags_NoSavedSettings;
		/*Щелкните правой кнопкой мыши тело/содержимое столбцов, чтобы отобразить контекстное меню таблицы. По умолчанию он доступен в TableHeadersRow().*/
		constexpr gt::UINT ContextMenuInBody = ImGuiTableFlags_ContextMenuInBody;
		/*Устанавливает каждый цвет RowBg с помощью ImGuiCol_TableRowBg или ImGuiCol_TableRowBgAlt (эквивалент вызова TableSetBgColor с ImGuiTableBgFlags_RowBg0 для каждой строки вручную)*/
		constexpr gt::UINT RowBg = ImGuiTableFlags_RowBg;
		/*Рисует горизонтальные границы между рядами.*/
		constexpr gt::UINT BordersInnerH = ImGuiTableFlags_BordersInnerH;
		/*Рисует горизонтальные границы сверху и снизу.*/
		constexpr gt::UINT BordersOuterH = ImGuiTableFlags_BordersOuterH;
		/*Рисует вертикальные границы между столбцами.*/
		constexpr gt::UINT BordersInnerV = ImGuiTableFlags_BordersInnerV;
		/*Рисует вертикальные границы слева и справа.*/
		constexpr gt::UINT BordersOuterV = ImGuiTableFlags_BordersOuterV;
		constexpr gt::UINT BordersH = ImGuiTableFlags_BordersInnerH | ImGuiTableFlags_BordersOuterH;
		constexpr gt::UINT BordersV = ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_BordersOuterV;
		constexpr gt::UINT BordersInner = ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_BordersInnerH;
		constexpr gt::UINT BordersOuter = ImGuiTableFlags_BordersOuterV | ImGuiTableFlags_BordersOuterH;
		constexpr gt::UINT Borders = ImGuiTableFlags_BordersInner | ImGuiTableFlags_BordersOuter;
		constexpr gt::UINT NoBordersInBody = ImGuiTableFlags_NoBordersInBody;
		constexpr gt::UINT NoBordersInBodyUntilResize = ImGuiTableFlags_NoBordersInBodyUntilResize;
		constexpr gt::UINT SizingFixedFit = ImGuiTableFlags_SizingFixedFit;
		constexpr gt::UINT SizingFixedSame = ImGuiTableFlags_SizingFixedSame;
		constexpr gt::UINT SizingStretchProp = ImGuiTableFlags_SizingStretchProp;
		constexpr gt::UINT SizingStretchSame = ImGuiTableFlags_SizingStretchSame;
		constexpr gt::UINT NoHostExtendX = ImGuiTableFlags_NoHostExtendX;
		constexpr gt::UINT NoHostExtendY = ImGuiTableFlags_NoHostExtendY;
		constexpr gt::UINT NoKeepColumnsVisible = ImGuiTableFlags_NoKeepColumnsVisible;
		constexpr gt::UINT PreciseWidths = ImGuiTableFlags_PreciseWidths;
		constexpr gt::UINT NoClip = ImGuiTableFlags_NoClip;
		constexpr gt::UINT PadOuterX = ImGuiTableFlags_PadOuterX;
		constexpr gt::UINT NoPadOuterX = ImGuiTableFlags_NoPadOuterX;
		constexpr gt::UINT NoPadInnerX = ImGuiTableFlags_NoPadInnerX;
		constexpr gt::UINT ScrollX = ImGuiTableFlags_ScrollX;
		constexpr gt::UINT ScrollY = ImGuiTableFlags_ScrollY;
		constexpr gt::UINT SortMulti = ImGuiTableFlags_SortMulti;
		constexpr gt::UINT SortTristate = ImGuiTableFlags_SortTristate;
	}

	/////////////////////// ImGui INPUT TEXT FLAG
	namespace input {
		constexpr gt::UINT None = ImGuiInputTextFlags_None;
		/*Можно вводить 0-9.+-*/
		constexpr gt::UINT Decimal = ImGuiInputTextFlags_CharsDecimal;
		/*Можно вводить 0123456789ABCDEFabcdef*/
		constexpr gt::UINT Hexadecimal = ImGuiInputTextFlags_CharsHexadecimal;
		/*Превращает нижний регистр в верхний (всё что введено)*/
		constexpr gt::UINT Uppercase = ImGuiInputTextFlags_CharsUppercase;
		/*Не позволяет ставить пробелы, табуляции и т.д.*/
		constexpr gt::UINT NoBlank = ImGuiInputTextFlags_CharsNoBlank;
		/*При вводе - автоматически выделяется весь текст*/
		constexpr gt::UINT AutoSelectAll = ImGuiInputTextFlags_AutoSelectAll;
		/*Обработка enter включена*/
		constexpr gt::UINT EnterReturnsTrue = ImGuiInputTextFlags_EnterReturnsTrue;
		/*Вызывает авто-комплит текста?*/
		constexpr gt::UINT CallbackCompletion = ImGuiInputTextFlags_CallbackCompletion;
		/*Стрелки вверх и вниз - позволяют ходить по истории ввода (ранее введённый текст)*/
		constexpr gt::UINT CallbackHistory = ImGuiInputTextFlags_CallbackHistory;
		/*Коллбэк при каждом инпуте (вводе символа)*/
		constexpr gt::UINT CallbackAlways = ImGuiInputTextFlags_CallbackAlways;
		constexpr gt::UINT CallbackCharFilter = ImGuiInputTextFlags_CallbackCharFilter;
		/*Нажатие tab вводит в inputText '\t'*/
		constexpr gt::UINT AllowTabInput = ImGuiInputTextFlags_AllowTabInput;
		/*Для мультилайнов: позволяет нажатием enter переходить на след. строку*/
		constexpr gt::UINT CtrlEnterForNewLine = ImGuiInputTextFlags_CtrlEnterForNewLine;
		/*Запрещает курсору прокручиваться горизонтально (влево/вправо)*/
		constexpr gt::UINT NoHorizontalScroll = ImGuiInputTextFlags_NoHorizontalScroll;
		/*Перезапись текущего текста: работает как insert?*/
		constexpr gt::UINT AlwaysOverwrite = ImGuiInputTextFlags_AlwaysOverwrite;
		/*Только чтение. Редактировать текст внутри поля - невозможно.*/
		constexpr gt::UINT ReadOnly = ImGuiInputTextFlags_ReadOnly;
		/*При вводе символов в поле, вместо их отображения будет: "*******"*/
		constexpr gt::UINT Password = ImGuiInputTextFlags_Password;
		/*Запрещает Ctrl+V, Ctrl+C для поля (т.е. ничего не вставим туда из буфера и не скопируем оттуда в буфер)*/
		constexpr gt::UINT NoUndoRedo = ImGuiInputTextFlags_NoUndoRedo;
		/*Позволяет вводить 0123456789.+-*\/eE*/
		constexpr gt::UINT CharsScientific = ImGuiInputTextFlags_CharsScientific;
		/*Resize поля: // Callback on buffer capacity changes request (beyond 'buf_size' parameter value),
		allowing the string to grow. Notify when the string wants to be resized (for string types which hold a cache of their Size).
		You will be provided a new BufSize in the callback and NEED to honor it. (see misc/cpp/imgui_stdlib.h for an example of using this)*/
		constexpr gt::UINT CallbackResize = ImGuiInputTextFlags_CallbackResize;
		/*Колбэк во время textEditing: Callback on any edit (note that InputText() already returns true on edit,
		the callback is useful mainly to manipulate the underlying buffer while focus is active)*/
		constexpr gt::UINT CallbackEdit = ImGuiInputTextFlags_CallbackEdit;
		/*ESC очищает всё inputText поле*/
		constexpr gt::UINT EscapeClearsAll = ImGuiInputTextFlags_EscapeClearsAll;
		/*Шаблон для inputText: пароль*/
		constexpr gt::UINT TemplatePassword = NoHorizontalScroll | NoUndoRedo | Password | NoBlank | EnterReturnsTrue | EscapeClearsAll;
		/*Шаблон для inputText: любой текст*/
		constexpr gt::UINT TemplateText = EnterReturnsTrue | EscapeClearsAll;
	}

	namespace ctrl {
		/*Открывает окно GUIOptions*/
		constexpr sf::Keyboard::Key ESCAPE = sf::Keyboard::Key::Escape;
		/*Открывает окно GUIInventory*/
		constexpr sf::Keyboard::Key V = sf::Keyboard::Key::V;
		/*Открывает окно GUIChat*/
		constexpr sf::Keyboard::Key ENTER = sf::Keyboard::Key::Enter;
		/*Открывает окно GUIStatus*/
		constexpr sf::Keyboard::Key C = sf::Keyboard::Key::C;
		/*Открывает окно GUIMap*/
		constexpr sf::Keyboard::Key M = sf::Keyboard::Key::M;
	}

	namespace window {
		/*No border / title bar (this flag and all others are mutually exclusive)*/
		constexpr gt::UINT None = sf::Style::None;
		/*Title bar + fixed border*/
		constexpr gt::UINT Titlebar = 1 << 0;
		/*Title bar + resizable border + maximize button*/
		constexpr gt::UINT Resize = 1 << 1;
		/*Title bar + close button*/
		constexpr gt::UINT Close = 1 << 2;
		/*Fullscreen mode (this flag and all others are mutually exclusive)*/
		constexpr gt::UINT Fullscreen = 1 << 3;
		/*Default window style represents from: Titlebar | Resize | Close*/
		constexpr gt::UINT Default = Titlebar | Resize | Close;
	}

}

/////////////////////// CLIENT SETTINGS
namespace conf {
	//////////////////////////
	/// GRAPHIC
	//////////////////////////
	enum class Resolution {
		_640,
		_800,
		_1024,
		_1600,
		_1900
	};
	static Resolution RESOLUTION = Resolution::_800;
	
	//////////////////////////
	/// AUDIO
	//////////////////////////
	static gt::UINT SOUND_VOLUME = 100;
	static gt::UINT MUSIC_VOLUME = 50;
	static gt::BOOL REPEAT_BACKGROUND_MUSIC = true;

	//////////////////////////
	/// USER
	//////////////////////////
	enum class Language {
		EN,
		RU
	};
	static Language LANGUAGE = Language::EN;
};

/////////////////////// Game system functions
template <typename E> inline constexpr auto Cast(E e) noexcept {
	return static_cast<std::underlying_type_t<E>>(e);
}

inline static const gt::UINT GetResWidth() noexcept {
	return consts::RESOULTION[Cast(conf::RESOLUTION)][0];
}

inline static const gt::UINT GetResHeight() noexcept {
	return consts::RESOULTION[Cast(conf::RESOLUTION)][1];
}
#endif