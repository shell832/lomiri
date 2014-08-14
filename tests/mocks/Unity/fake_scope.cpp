/*
 * Copyright (C) 2013, 2014 Canonical, Ltd.
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

#include <QDebug>
#include <QUrl>

#include "fake_scope.h"

#include "fake_navigation.h"
#include "fake_resultsmodel.h"
#include "fake_scopes.h"

Scope::Scope(Scopes* parent) : Scope(QString(), QString(), false, parent)
{
}

Scope::Scope(QString const& id, QString const& name, bool favorite, Scopes* parent, int categories)
    : unity::shell::scopes::ScopeInterface(parent)
    , m_id(id)
    , m_name(name)
    , m_searching(false)
    , m_favorite(favorite)
    , m_isActive(false)
    , m_currentNavigationId("root")
    , m_currentAltNavigationId("altroot")
    , m_previewRendererName("preview-generic")
    , m_categories(new Categories(categories, this))
    , m_openScope(nullptr)
{
}

QString Scope::id() const
{
    return m_id;
}

QString Scope::name() const
{
    return m_name;
}

QString Scope::searchQuery() const
{
    return m_searchQuery;
}

QString Scope::iconHint() const
{
    return m_iconHint;
}

QString Scope::description() const
{
    return m_description;
}

QString Scope::searchHint() const
{
    return QString("Search %1").arg(m_name);
}

QString Scope::shortcut() const
{
    return QString("");
}

bool Scope::searchInProgress() const
{
    return m_searching;
}

bool Scope::favorite() const
{
    return m_favorite;
}

unity::shell::scopes::CategoriesInterface* Scope::categories() const
{
    return m_categories;
}

unity::shell::scopes::SettingsModelInterface* Scope::settings() const
{
    return nullptr;
}

QString Scope::noResultsHint() const
{
    return m_noResultsHint;
}

QString Scope::formFactor() const
{
    return m_formFactor;
}

bool Scope::isActive() const
{
    return m_isActive;
}

void Scope::setSearchQuery(const QString &str)
{
    if (str != m_searchQuery) {
        m_searchQuery = str;
        Q_EMIT searchQueryChanged();
    }
}

void Scope::setFormFactor(const QString &str)
{
    if (str != m_formFactor) {
        m_formFactor = str;
        Q_EMIT formFactorChanged();
    }
}

void Scope::setActive(const bool active)
{
    if (active != m_isActive) {
        m_isActive = active;
        Q_EMIT isActiveChanged();
    }
}

void Scope::setFavorite(const bool favorite)
{
    if (favorite != m_favorite) {
        m_favorite = favorite;
        Q_EMIT favoriteChanged();
    }
}
void Scope::setSearchInProgress(const bool inProg)
{
    if (inProg != m_searching) {
        m_searching = inProg;
        Q_EMIT searchInProgressChanged();
    }
}

void Scope::setNoResultsHint(const QString& str)
{
    if (str != m_noResultsHint) {
        m_noResultsHint = str;
        Q_EMIT noResultsHintChanged();
    }
}

void Scope::activate(QVariant const& result)
{
    qDebug() << "Called activate on scope" << m_id << "with result" << result;
    if (result.toString() == "Result.2.2") {
        Scopes *scopes = dynamic_cast<Scopes*>(parent());
        m_openScope = scopes->getScopeFromAll("MockScope9");
        Q_EMIT openScope(m_openScope);
    }
}

PreviewStack* Scope::preview(QVariant const& result)
{
    Q_UNUSED(result);

    // This probably leaks, do we don't care
    // it's a  test after all
    return new PreviewStack;
}

void Scope::cancelActivation()
{
}

void Scope::closeScope(unity::shell::scopes::ScopeInterface* scope)
{
    if (scope != m_openScope) {
        qDebug() << scope << m_openScope;
        qFatal("Scope::closeScope got wrong scope in closeScope");
    }
    m_openScope = nullptr;
}

QString Scope::currentNavigationId() const
{
    return m_currentNavigationId;
}

bool Scope::hasNavigation() const
{
    return true;
}

QString Scope::currentAltNavigationId() const
{
    return m_currentAltNavigationId;
}

bool Scope::hasAltNavigation() const
{
    return true;
}

Scope::Status Scope::status() const
{
    return Status::Okay;
}

QVariantMap Scope::customizations() const
{
    QVariantMap m, h;
    if (m_id == "clickscope") {
        h["foreground-color"] = "yellow";
        m["background-color"] = "red";
        m["foreground-color"] = "blue";
        m["page-header"] = h;
    } else if (m_id == "MockScope5") {
        h["background"] = "gradient:///lightgrey/grey";
        h["logo"] = QUrl("../../../tests/qmltests/Dash/tst_PageHeader/logo-ubuntu-orange.svg");
        h["navigation-background"] = "color:///black";
        m["page-header"] = h;
    }
    return m;
}

void Scope::refresh()
{
    qDebug() << "Scope::refresh is currently not implmented in the fake scopes plugin";
}

unity::shell::scopes::NavigationInterface* Scope::getNavigation(const QString& id)
{
    if (id.isEmpty())
        return nullptr;

    QString parentId;
    QString parentLabel;
    if (id.startsWith("middle")) {
        parentId = "root";
        parentLabel = "root";
    } else if (id.startsWith("child")) {
        parentId = id.mid(5, 7);
        parentLabel = parentId;
    }
    return new Navigation(id, id, "all"+id, parentId, parentLabel, this);
}

unity::shell::scopes::NavigationInterface* Scope::getAltNavigation(QString const& id)
{
    if (id.isEmpty())
        return nullptr;

    QString parentId;
    QString parentLabel;
    if (id.startsWith("altmiddle")) {
        parentId = "altroot";
        parentLabel = "altroot";
    }
    return new Navigation(id, id, "all"+id, parentId, parentLabel, this);
}

void Scope::setNavigationState(const QString &navigationId, bool isAltNavigation)
{
    if (isAltNavigation) {
        m_currentAltNavigationId = navigationId;
        Q_EMIT currentAltNavigationIdChanged();
    } else {
        m_currentNavigationId = navigationId;
        Q_EMIT currentNavigationIdChanged();
    }
}
