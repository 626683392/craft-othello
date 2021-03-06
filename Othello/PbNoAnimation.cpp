﻿/*
*************************************************************************
    Craft is an othello program with relatively high AI.
    Copyright (C) 2008-2011  Patrick

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
								PbNoAnimation.cpp
		作者：Patrick
		概述：setProgressBarValueNoAnimation的定义，用于无动画地设置进度条的值
			 (Vista/7 only)

********************************************************************************
*/

#include "StdAfx.h"
#include "PbNoAnimation.h"

namespace Othello {

void setProgressBarValueNoAnimation(System::Windows::Forms::ProgressBar^ pb, int value) {
	if (value >= pb->Maximum) {
		pb->Maximum = value + 1;
		pb->Value = value + 1;
		pb->Maximum = value;
		pb->Value = value;
	} else {
		pb->Value = value + 1;
		pb->Value = value;
	}
}

} // namespace Othello
