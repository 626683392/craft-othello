/*
*************************************************************************
    Craft is an othello program with relatively high AI.
    Copyright (C) 2008-2010  Patrick

    This file is part of Craft.

    Craft is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Craft is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Craft.  If not, see <http://www.gnu.org/licenses/>.

    Craft-Othello on Google Code: <http://code.google.com/p/craft-othello/>

    Patrick's E-mail: patrick880905@sina.com
    Patrick's Blog: <http://blog.sina.com.cn/patwonder>
*************************************************************************
*/

/*
********************************************************************************
								FlashWindow.cpp
		���ߣ�Patrick
		���������� FlashWindowEx �����Ķ��塣

********************************************************************************
*/

#include "stdafx.h"
#include "FlashWindow.h"
#include <Windows.h>

namespace Othello {
	bool FlashWindowEx(System::IntPtr hwnd, System::UInt32 flags, 
			System::UInt32 count, System::UInt32 timeout) {
		FLASHWINFO info;
		info.cbSize = sizeof(info);
		info.hwnd = (HWND)hwnd.ToInt32();
		info.dwFlags = flags;
		info.dwTimeout = timeout;
		info.uCount = count;
		return (bool)(::FlashWindowEx(&info));
	}
}
