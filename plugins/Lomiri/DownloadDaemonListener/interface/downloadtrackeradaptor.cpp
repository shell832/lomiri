/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -v -c DownloadTrackerAdaptor -p downloadtrackeradaptor.h:downloadtrackeradaptor.cpp -i metatypes.h ../../../../../../lomiri-download-manager/trunk/docs/dbus/com.canonical.applications.download.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "downloadtrackeradaptor.h"

/*
 * Implementation of interface class DownloadTrackerAdaptor
 */

DownloadTrackerAdaptor::DownloadTrackerAdaptor(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

DownloadTrackerAdaptor::~DownloadTrackerAdaptor()
{
}
