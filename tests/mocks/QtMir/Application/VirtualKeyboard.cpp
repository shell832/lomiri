/*
 * Copyright (C) 2015,2016 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "VirtualKeyboard.h"

#include <paths.h>

#include <QString>

#include <QDebug>

VirtualKeyboard::VirtualKeyboard()
    : MirSurface("input-method",
                 Mir::InputMethodType,
                 Mir::MinimizedState,
                 nullptr, /* parentSurface */
                 QUrl("qrc:///QtMir/Application/vkb_portrait.png"),
                 QUrl("qrc:///QtMir/Application/VirtualKeyboard.qml"))
{
}

VirtualKeyboard::~VirtualKeyboard()
{
}

void VirtualKeyboard::updateInputBoundsAfterResize()
{
    int width = this->width();

    int height = 0;
    if (visible()) {
        if (this->width() > this->height()) {
            // landscape
            height = this->height() * 0.4;
        } else {
            // portrait
            height = this->width() * 0.6;
        }
    }

    int x = 0;
    int y = this->height() - height;

    setInputBounds(QRect(x, y, width, height));
}
