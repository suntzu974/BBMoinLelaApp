/*
 * Copyright (c) 2011-2015 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "applicationui.hpp"
#include <bb/cascades/Application>
#include <bb/cascades/places/PlacePicker>
#include <bb/cascades/places/SelectedPlace>
#include <QLocale>
#include <QTranslator>
#include <bb/system/phone/Phone>
#include <Qt/qdeclarativedebug.h>
#include "MoinLelaRequest.hpp"

using namespace bb::cascades;

Q_DECL_EXPORT int main(int argc, char **argv)
{
    Application app(argc, argv);
    // Register our custom control
    qmlRegisterType<bb::cascades::places::PlacePicker>("bb.cascades.places", 1, 0, "PlacePicker");
    qmlRegisterUncreatableType<bb::cascades::places::SelectedPlace>("bb.cascades.places", 1, 0, "SelectedPlace", "");
    qmlRegisterType<bb::system::phone::Phone>("bb.system.phone", 1, 0, "Phone");
    qmlRegisterType<WebMaps>("com.moinlela.webmaps",1, 0, "WebMaps");
    qmlRegisterType<MoinLelaRequest>("com.moinlela.MoinLelaRequest", 1, 0, "MoinLelaRequest");
    // Create the Application UI object, this is where the main.qml file
    // is loaded and the application scene is set.
    ApplicationUI appui;

    // Enter the application main event loop.
    return Application::exec();
}
