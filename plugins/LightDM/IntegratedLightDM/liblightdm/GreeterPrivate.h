/*
 * Copyright (C) 2013 Canonical, Ltd.
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
 *
 * Author: Michael Terry <michael.terry@canonical.com>
 */

#ifndef LOMIRI_MOCK_GREETER_PRIVATE_H
#define LOMIRI_MOCK_GREETER_PRIVATE_H

#include <QtCore/QObject>

namespace QLightDM
{
class Greeter;
class GreeterImpl;

class GreeterPrivate
{
public:
    explicit GreeterPrivate(Greeter* parent=0);
    virtual ~GreeterPrivate();

    // These variables may not be used by all subclasses, that's no problem
    bool authenticated;
    QString authenticationUser;

    void handleAuthenticate();
    void handleRespond(const QString &response);
    void cancelAuthentication();

protected:
    GreeterImpl *m_impl; // if the backend needs more private data
    Greeter * const q_ptr;

private:
    Q_DECLARE_PUBLIC(Greeter)
};
}

#endif // LOMIRI_MOCK_GREETER_PRIVATE_H
