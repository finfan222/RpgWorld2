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
		using string::string; // findout: ��������� ��� ��� � ��� ��������, �� ��������

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
	/*�������� ����� � ������ ������� �����������*/
	void print(LogLevel level = LogLevel::INFO, gt::UINT cnt = 0, ...);
	/*�������� ����� � INFO ������������*/
	void info(gt::UINT cnt = 0, ...);
	/*�������� ����� � ERROR ������������*/
	void err(gt::UINT cnt = 0, ...);
	/*�������� ����� � WARN ������������*/
	void warn(gt::UINT cnt = 0, ...);
}

/////////////////////// UI optimize works
namespace ui {
	/*
	������ � ���������� default �������-���������: ���� ������. ���������� gt::BOOL.
	*/
	gt::BOOL button(gt::CSTRING title, ImVec2& size);

	/////////////////////// ImGui WINDOW FLAG
	namespace wnd {
		constexpr gt::UINT None = ImGuiWindowFlags_None;
		/*��������� ���������� ��� UI (�� ��������� ����� ��� ���������� ���� �� ��� ��� ��������)*/
		constexpr gt::UINT Unscroll = ImGuiWindowFlags_NoScrollbar;
		/*��������� ����������� ����������� ������*/
		constexpr gt::UINT Unmove = ImGuiWindowFlags_NoMove;
		/*�� ����� title � ������*/
		constexpr gt::UINT Untitle = ImGuiWindowFlags_NoTitleBar;
		/*������ ��������� (�������� ������)*/
		constexpr gt::UINT Unresize = ImGuiWindowFlags_NoResize;
		/*������ ����������� ������*/
		constexpr gt::UINT Uncollapse = ImGuiWindowFlags_NoCollapse;
		/*��������� �������� ���� �� ���� �����*/
		constexpr gt::UINT UnscrollWithMouse = ImGuiWindowFlags_NoScrollWithMouse;
		/*������ ������������� ���������*/
		constexpr gt::UINT AutoResize = ImGuiWindowFlags_AlwaysAutoResize;
		/*��������� ��������� � ������*/
		constexpr gt::UINT Unbackground = ImGuiWindowFlags_NoBackground;
		/*�� ��������� ������� ���������� � ������� ���� (������������ � ������)*/
		constexpr gt::UINT Unsaveable = ImGuiWindowFlags_NoSavedSettings;
		/*��������� ����� ����, ���� ��������� � ���������.*/
		constexpr gt::UINT NoMouseInputs = ImGuiWindowFlags_NoMouseInputs;
		/*�������� menubar � ������.*/
		constexpr gt::UINT MenuBar = ImGuiWindowFlags_MenuBar;
		/*�������� �������������� ���������.*/
		constexpr gt::UINT HorizontalScrollbar = ImGuiWindowFlags_HorizontalScrollbar;
		/*�� �������������� �� ���� (�� ��������� �� ��� ������) � ������ ���������/��������.*/
		constexpr gt::UINT NoFocusOnAppearing = ImGuiWindowFlags_NoFocusOnAppearing;
		/*��������� ����� ���� �� �������� ���� ��� ��������� ������ (��������, ��� ������� �� ���� ��� ����������� ���������� ��� ������)*/
		constexpr gt::UINT NoBringToFrontOnFocus = ImGuiWindowFlags_NoBringToFrontOnFocus;
		/*������ ���������� ������������ ������ ��������� (���� ���� ContentSize.y < Size.y)*/
		constexpr gt::UINT AlwaysVerticalScrollbar = ImGuiWindowFlags_AlwaysVerticalScrollbar;
		/*������ ���������� �������������� ������ ��������� (���� ���� ContentSize.y < Size.y)*/
		constexpr gt::UINT AlwaysHorizontalScrollbar = ImGuiWindowFlags_AlwaysHorizontalScrollbar;
		/*���������, ��� �������� ���� ��� ����� ���������� style.WindowPadding (�� ��������� ������������ ��� �������� ���� ��� �����, ��� ��� ��� �������)*/
		constexpr gt::UINT AlwaysUseWindowPadding = ImGuiWindowFlags_AlwaysUseWindowPadding;
		/*��� ��������� � ������� ��������/���������� � ����*/
		constexpr gt::UINT NoNavInputs = ImGuiWindowFlags_NoNavInputs;
		/*�� ������������ �� ���� ���� ��� ��������� � ������� ��������/���������� (��������, ������������ � ������� CTRL+TAB)*/
		constexpr gt::UINT NoNavFocus = ImGuiWindowFlags_NoNavFocus;
		/*��������� ����� ����� � ����������. ��� ������������� � ��������� �������/�������� ������� ���������� ��� ������� X + �������� �� �������������� (����� �����, ���� ������������ ��������� �������� �������). � ��������� ������ �������������� �������� ��� ������� X, �������, ���� �� ���������� ��������, ������� ����� ����� ��������� � ����� ������ �������.*/
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
		/*��������� ���� ������*/
		constexpr gt::UINT Bordered = ImGuiTableFlags_Borders;
		/*�������� ����������� �������*/
		constexpr gt::UINT Resizable = ImGuiTableFlags_Resizable;
		/*�������� ��������������� ������� (����� ����� ��� ������� TableSetupColumns + TableHeadersRow*/
		constexpr gt::UINT Reorderable = ImGuiTableFlags_Reorderable;
		/*��������� ��������/���������� �������*/
		constexpr gt::UINT Hideable = ImGuiTableFlags_Hideable;
		/*�������� ����������. �������� TableGetSortSpecs(), ����� �������� ������������ ����������. ��. ����� ImGuiTableFlags_SortMulti � ImGuiTableFlags_SortTristate.*/
		constexpr gt::UINT Sortable = ImGuiTableFlags_Sortable;
		/*��������� ���������� ������� ��������, ������ � ���������� ���������� � ����� .ini.*/
		constexpr gt::UINT NoSavedSettings = ImGuiTableFlags_NoSavedSettings;
		/*�������� ������ ������� ���� ����/���������� ��������, ����� ���������� ����������� ���� �������. �� ��������� �� �������� � TableHeadersRow().*/
		constexpr gt::UINT ContextMenuInBody = ImGuiTableFlags_ContextMenuInBody;
		/*������������� ������ ���� RowBg � ������� ImGuiCol_TableRowBg ��� ImGuiCol_TableRowBgAlt (���������� ������ TableSetBgColor � ImGuiTableBgFlags_RowBg0 ��� ������ ������ �������)*/
		constexpr gt::UINT RowBg = ImGuiTableFlags_RowBg;
		/*������ �������������� ������� ����� ������.*/
		constexpr gt::UINT BordersInnerH = ImGuiTableFlags_BordersInnerH;
		/*������ �������������� ������� ������ � �����.*/
		constexpr gt::UINT BordersOuterH = ImGuiTableFlags_BordersOuterH;
		/*������ ������������ ������� ����� ���������.*/
		constexpr gt::UINT BordersInnerV = ImGuiTableFlags_BordersInnerV;
		/*������ ������������ ������� ����� � ������.*/
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
		/*����� ������� 0-9.+-*/
		constexpr gt::UINT Decimal = ImGuiInputTextFlags_CharsDecimal;
		/*����� ������� 0123456789ABCDEFabcdef*/
		constexpr gt::UINT Hexadecimal = ImGuiInputTextFlags_CharsHexadecimal;
		/*���������� ������ ������� � ������� (�� ��� �������)*/
		constexpr gt::UINT Uppercase = ImGuiInputTextFlags_CharsUppercase;
		/*�� ��������� ������� �������, ��������� � �.�.*/
		constexpr gt::UINT NoBlank = ImGuiInputTextFlags_CharsNoBlank;
		/*��� ����� - ������������� ���������� ���� �����*/
		constexpr gt::UINT AutoSelectAll = ImGuiInputTextFlags_AutoSelectAll;
		/*��������� enter ��������*/
		constexpr gt::UINT EnterReturnsTrue = ImGuiInputTextFlags_EnterReturnsTrue;
		/*�������� ����-������� ������?*/
		constexpr gt::UINT CallbackCompletion = ImGuiInputTextFlags_CallbackCompletion;
		/*������� ����� � ���� - ��������� ������ �� ������� ����� (����� �������� �����)*/
		constexpr gt::UINT CallbackHistory = ImGuiInputTextFlags_CallbackHistory;
		/*������� ��� ������ ������ (����� �������)*/
		constexpr gt::UINT CallbackAlways = ImGuiInputTextFlags_CallbackAlways;
		constexpr gt::UINT CallbackCharFilter = ImGuiInputTextFlags_CallbackCharFilter;
		/*������� tab ������ � inputText '\t'*/
		constexpr gt::UINT AllowTabInput = ImGuiInputTextFlags_AllowTabInput;
		/*��� ������������: ��������� �������� enter ���������� �� ����. ������*/
		constexpr gt::UINT CtrlEnterForNewLine = ImGuiInputTextFlags_CtrlEnterForNewLine;
		/*��������� ������� �������������� ������������� (�����/������)*/
		constexpr gt::UINT NoHorizontalScroll = ImGuiInputTextFlags_NoHorizontalScroll;
		/*���������� �������� ������: �������� ��� insert?*/
		constexpr gt::UINT AlwaysOverwrite = ImGuiInputTextFlags_AlwaysOverwrite;
		/*������ ������. ������������� ����� ������ ���� - ����������.*/
		constexpr gt::UINT ReadOnly = ImGuiInputTextFlags_ReadOnly;
		/*��� ����� �������� � ����, ������ �� ����������� �����: "*******"*/
		constexpr gt::UINT Password = ImGuiInputTextFlags_Password;
		/*��������� Ctrl+V, Ctrl+C ��� ���� (�.�. ������ �� ������� ���� �� ������ � �� ��������� ������ � �����)*/
		constexpr gt::UINT NoUndoRedo = ImGuiInputTextFlags_NoUndoRedo;
		/*��������� ������� 0123456789.+-*\/eE*/
		constexpr gt::UINT CharsScientific = ImGuiInputTextFlags_CharsScientific;
		/*Resize ����: // Callback on buffer capacity changes request (beyond 'buf_size' parameter value),
		allowing the string to grow. Notify when the string wants to be resized (for string types which hold a cache of their Size).
		You will be provided a new BufSize in the callback and NEED to honor it. (see misc/cpp/imgui_stdlib.h for an example of using this)*/
		constexpr gt::UINT CallbackResize = ImGuiInputTextFlags_CallbackResize;
		/*������ �� ����� textEditing: Callback on any edit (note that InputText() already returns true on edit,
		the callback is useful mainly to manipulate the underlying buffer while focus is active)*/
		constexpr gt::UINT CallbackEdit = ImGuiInputTextFlags_CallbackEdit;
		/*ESC ������� �� inputText ����*/
		constexpr gt::UINT EscapeClearsAll = ImGuiInputTextFlags_EscapeClearsAll;
		/*������ ��� inputText: ������*/
		constexpr gt::UINT TemplatePassword = NoHorizontalScroll | NoUndoRedo | Password | NoBlank | EnterReturnsTrue | EscapeClearsAll;
		/*������ ��� inputText: ����� �����*/
		constexpr gt::UINT TemplateText = EnterReturnsTrue | EscapeClearsAll;
	}

	namespace ctrl {
		/*��������� ���� GUIOptions*/
		constexpr sf::Keyboard::Key ESCAPE = sf::Keyboard::Key::Escape;
		/*��������� ���� GUIInventory*/
		constexpr sf::Keyboard::Key V = sf::Keyboard::Key::V;
		/*��������� ���� GUIChat*/
		constexpr sf::Keyboard::Key ENTER = sf::Keyboard::Key::Enter;
		/*��������� ���� GUIStatus*/
		constexpr sf::Keyboard::Key C = sf::Keyboard::Key::C;
		/*��������� ���� GUIMap*/
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