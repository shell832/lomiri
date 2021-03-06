/*
 * Copyright (C) 2014 Canonical, Ltd.
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

#ifndef CONNECTIVITY_H
#define CONNECTIVITY_H

#include <QObject>

class ModemConnectivity : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ModemConnectivity)

public:
    explicit ModemConnectivity(QObject *parent = 0);
    ~ModemConnectivity() = default;

    Q_INVOKABLE void unlockAllModems();
};

#endif // CONNECTIVITY_H
