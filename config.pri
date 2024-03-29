# Config.pri file version 2.0. Auto-generated by IDE. Any changes made by user will be lost!
BASEDIR = $$quote($$_PRO_FILE_PWD_)

device {
    CONFIG(debug, debug|release) {
        profile {
            INCLUDEPATH += $$quote(${QNX_TARGET}/usr/include/QtLocationSubset) \
                $$quote(${QNX_TARGET}/usr/include/bb/device) \
                $$quote(${QNX_TARGET}/usr/include/bb/platform) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork) \
                $$quote(${QNX_TARGET}/usr/include/bb/data) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtGui) \
                $$quote(${QNX_TARGET}/usr/include/bb) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                $$quote(${QNX_TARGET}/usr/include/bb/system)

            DEPENDPATH += $$quote(${QNX_TARGET}/usr/include/QtLocationSubset) \
                $$quote(${QNX_TARGET}/usr/include/bb/device) \
                $$quote(${QNX_TARGET}/usr/include/bb/platform) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork) \
                $$quote(${QNX_TARGET}/usr/include/bb/data) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtGui) \
                $$quote(${QNX_TARGET}/usr/include/bb) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                $$quote(${QNX_TARGET}/usr/include/bb/system)

            LIBS += -lbbcascades \
                -lexif \
                -lQtGui \
                -lbbutility \
                -llocation_manager \
                -lgeomonitor \
                -lbbdata \
                -lbbsystem \
                -lphone-number \
                -lbbplatform \
                -lbbcascadesplaces \
                -lQtCore \
                -lbbdevice \
                -lbbpim \
                -lbbmultimedia \
                -lbps \
                -lQtLocationSubset \
                -lbbcascadesmultimedia \
                -lbb \
                -lQtNetwork

            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        } else {
            INCLUDEPATH += $$quote(${QNX_TARGET}/usr/include/QtLocationSubset) \
                $$quote(${QNX_TARGET}/usr/include/bb/device) \
                $$quote(${QNX_TARGET}/usr/include/bb/platform) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork) \
                $$quote(${QNX_TARGET}/usr/include/bb/data) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtGui) \
                $$quote(${QNX_TARGET}/usr/include/bb) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                $$quote(${QNX_TARGET}/usr/include/bb/system)

            DEPENDPATH += $$quote(${QNX_TARGET}/usr/include/QtLocationSubset) \
                $$quote(${QNX_TARGET}/usr/include/bb/device) \
                $$quote(${QNX_TARGET}/usr/include/bb/platform) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork) \
                $$quote(${QNX_TARGET}/usr/include/bb/data) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtGui) \
                $$quote(${QNX_TARGET}/usr/include/bb) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                $$quote(${QNX_TARGET}/usr/include/bb/system)

            LIBS += -lbbcascades \
                -lexif \
                -lQtGui \
                -lbbutility \
                -llocation_manager \
                -lgeomonitor \
                -lbbdata \
                -lbbsystem \
                -lphone-number \
                -lbbplatform \
                -lbbcascadesplaces \
                -lQtCore \
                -lbbdevice \
                -lbbpim \
                -lbbmultimedia \
                -lbps \
                -lQtLocationSubset \
                -lbbcascadesmultimedia \
                -lbb \
                -lQtNetwork

            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }

    }

    CONFIG(release, debug|release) {
        !profile {
            INCLUDEPATH += $$quote(${QNX_TARGET}/usr/include/QtLocationSubset) \
                $$quote(${QNX_TARGET}/usr/include/bb/device) \
                $$quote(${QNX_TARGET}/usr/include/bb/platform) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork) \
                $$quote(${QNX_TARGET}/usr/include/bb/data) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtGui) \
                $$quote(${QNX_TARGET}/usr/include/bb) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                $$quote(${QNX_TARGET}/usr/include/bb/system)

            DEPENDPATH += $$quote(${QNX_TARGET}/usr/include/QtLocationSubset) \
                $$quote(${QNX_TARGET}/usr/include/bb/device) \
                $$quote(${QNX_TARGET}/usr/include/bb/platform) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork) \
                $$quote(${QNX_TARGET}/usr/include/bb/data) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtGui) \
                $$quote(${QNX_TARGET}/usr/include/bb) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                $$quote(${QNX_TARGET}/usr/include/bb/system)

            LIBS += -lbbcascades \
                -lexif \
                -lQtGui \
                -lbbutility \
                -llocation_manager \
                -lgeomonitor \
                -lbbdata \
                -lbbsystem \
                -lphone-number \
                -lbbplatform \
                -lbbcascadesplaces \
                -lQtCore \
                -lbbdevice \
                -lbbpim \
                -lbbmultimedia \
                -lbps \
                -lQtLocationSubset \
                -lbbcascadesmultimedia \
                -lbb \
                -lQtNetwork

            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }
    }
}

simulator {
    CONFIG(debug, debug|release) {
        !profile {
            INCLUDEPATH += $$quote(${QNX_TARGET}/usr/include/QtLocationSubset) \
                $$quote(${QNX_TARGET}/usr/include/bb/device) \
                $$quote(${QNX_TARGET}/usr/include/bb/platform) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork) \
                $$quote(${QNX_TARGET}/usr/include/bb/data) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtGui) \
                $$quote(${QNX_TARGET}/usr/include/bb) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                $$quote(${QNX_TARGET}/usr/include/bb/system)

            DEPENDPATH += $$quote(${QNX_TARGET}/usr/include/QtLocationSubset) \
                $$quote(${QNX_TARGET}/usr/include/bb/device) \
                $$quote(${QNX_TARGET}/usr/include/bb/platform) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork) \
                $$quote(${QNX_TARGET}/usr/include/bb/data) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtGui) \
                $$quote(${QNX_TARGET}/usr/include/bb) \
                $$quote(${QNX_TARGET}/usr/include/qt4/QtCore) \
                $$quote(${QNX_TARGET}/usr/include/bb/system)

            LIBS += -lbbcascades \
                -lexif \
                -lQtGui \
                -lbbutility \
                -llocation_manager \
                -lgeomonitor \
                -lbbdata \
                -lbbsystem \
                -lphone-number \
                -lbbplatform \
                -lbbcascadesplaces \
                -lQtCore \
                -lbbdevice \
                -lbbpim \
                -lbbmultimedia \
                -lbps \
                -lQtLocationSubset \
                -lbbcascadesmultimedia \
                -lbb \
                -lQtNetwork

            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }
    }
}

config_pri_assets {
    OTHER_FILES += \
        $$quote($$BASEDIR/assets/FieldLabel.qml) \
        $$quote($$BASEDIR/assets/FieldNumber.qml) \
        $$quote($$BASEDIR/assets/Map.qml) \
        $$quote($$BASEDIR/assets/bing_map.js) \
        $$quote($$BASEDIR/assets/controls/NetworkActivity.qml) \
        $$quote($$BASEDIR/assets/controls/starRating.qml) \
        $$quote($$BASEDIR/assets/google_map.js) \
        $$quote($$BASEDIR/assets/helpPage.qml) \
        $$quote($$BASEDIR/assets/icons/ic_add.png) \
        $$quote($$BASEDIR/assets/icons/ic_add_bookmarks.png) \
        $$quote($$BASEDIR/assets/icons/ic_add_folder.png) \
        $$quote($$BASEDIR/assets/icons/ic_add_to_contacts.png) \
        $$quote($$BASEDIR/assets/icons/ic_all.png) \
        $$quote($$BASEDIR/assets/icons/ic_attach.png) \
        $$quote($$BASEDIR/assets/icons/ic_bbm.png) \
        $$quote($$BASEDIR/assets/icons/ic_browser.png) \
        $$quote($$BASEDIR/assets/icons/ic_buy.png) \
        $$quote($$BASEDIR/assets/icons/ic_camera.png) \
        $$quote($$BASEDIR/assets/icons/ic_cancel.png) \
        $$quote($$BASEDIR/assets/icons/ic_cancel_selection.png) \
        $$quote($$BASEDIR/assets/icons/ic_check_spell.png) \
        $$quote($$BASEDIR/assets/icons/ic_clear.png) \
        $$quote($$BASEDIR/assets/icons/ic_clear_list.png) \
        $$quote($$BASEDIR/assets/icons/ic_code_inspector.png) \
        $$quote($$BASEDIR/assets/icons/ic_collapse.png) \
        $$quote($$BASEDIR/assets/icons/ic_compose.png) \
        $$quote($$BASEDIR/assets/icons/ic_contact.png) \
        $$quote($$BASEDIR/assets/icons/ic_copy.png) \
        $$quote($$BASEDIR/assets/icons/ic_copy_link.png) \
        $$quote($$BASEDIR/assets/icons/ic_copy_link_image.png) \
        $$quote($$BASEDIR/assets/icons/ic_copy_password.png) \
        $$quote($$BASEDIR/assets/icons/ic_cut.png) \
        $$quote($$BASEDIR/assets/icons/ic_decrease.png) \
        $$quote($$BASEDIR/assets/icons/ic_delete.png) \
        $$quote($$BASEDIR/assets/icons/ic_delete_prior.png) \
        $$quote($$BASEDIR/assets/icons/ic_deselect.png) \
        $$quote($$BASEDIR/assets/icons/ic_deselect_all.png) \
        $$quote($$BASEDIR/assets/icons/ic_diagnostics.png) \
        $$quote($$BASEDIR/assets/icons/ic_disable.png) \
        $$quote($$BASEDIR/assets/icons/ic_doctype_doc.png) \
        $$quote($$BASEDIR/assets/icons/ic_doctype_generic.png) \
        $$quote($$BASEDIR/assets/icons/ic_doctype_music.png) \
        $$quote($$BASEDIR/assets/icons/ic_doctype_pdf.png) \
        $$quote($$BASEDIR/assets/icons/ic_doctype_picture.png) \
        $$quote($$BASEDIR/assets/icons/ic_doctype_ppt.png) \
        $$quote($$BASEDIR/assets/icons/ic_doctype_video.png) \
        $$quote($$BASEDIR/assets/icons/ic_doctype_web.png) \
        $$quote($$BASEDIR/assets/icons/ic_doctype_xls.png) \
        $$quote($$BASEDIR/assets/icons/ic_doctype_zip.png) \
        $$quote($$BASEDIR/assets/icons/ic_done.png) \
        $$quote($$BASEDIR/assets/icons/ic_download.png) \
        $$quote($$BASEDIR/assets/icons/ic_edit.png) \
        $$quote($$BASEDIR/assets/icons/ic_edit_bookmarks.png) \
        $$quote($$BASEDIR/assets/icons/ic_edit_list.png) \
        $$quote($$BASEDIR/assets/icons/ic_edit_profile.png) \
        $$quote($$BASEDIR/assets/icons/ic_email_dk.png) \
        $$quote($$BASEDIR/assets/icons/ic_enable.png) \
        $$quote($$BASEDIR/assets/icons/ic_entry.png) \
        $$quote($$BASEDIR/assets/icons/ic_expand.png) \
        $$quote($$BASEDIR/assets/icons/ic_facebook.png) \
        $$quote($$BASEDIR/assets/icons/ic_favorite.png) \
        $$quote($$BASEDIR/assets/icons/ic_feedback.png) \
        $$quote($$BASEDIR/assets/icons/ic_forward.png) \
        $$quote($$BASEDIR/assets/icons/ic_help.png) \
        $$quote($$BASEDIR/assets/icons/ic_history.png) \
        $$quote($$BASEDIR/assets/icons/ic_home.png) \
        $$quote($$BASEDIR/assets/icons/ic_increase.png) \
        $$quote($$BASEDIR/assets/icons/ic_info.png) \
        $$quote($$BASEDIR/assets/icons/ic_location.png) \
        $$quote($$BASEDIR/assets/icons/ic_lock.png) \
        $$quote($$BASEDIR/assets/icons/ic_map.png) \
        $$quote($$BASEDIR/assets/icons/ic_microphone.png) \
        $$quote($$BASEDIR/assets/icons/ic_microphone_mute.png) \
        $$quote($$BASEDIR/assets/icons/ic_move.png) \
        $$quote($$BASEDIR/assets/icons/ic_nav_to.png) \
        $$quote($$BASEDIR/assets/icons/ic_next.png) \
        $$quote($$BASEDIR/assets/icons/ic_notes.png) \
        $$quote($$BASEDIR/assets/icons/ic_notification.png) \
        $$quote($$BASEDIR/assets/icons/ic_open.png) \
        $$quote($$BASEDIR/assets/icons/ic_open_link.png) \
        $$quote($$BASEDIR/assets/icons/ic_overflow_action.png) \
        $$quote($$BASEDIR/assets/icons/ic_overflow_tab.png) \
        $$quote($$BASEDIR/assets/icons/ic_paste.png) \
        $$quote($$BASEDIR/assets/icons/ic_pause.png) \
        $$quote($$BASEDIR/assets/icons/ic_phone.png) \
        $$quote($$BASEDIR/assets/icons/ic_play.png) \
        $$quote($$BASEDIR/assets/icons/ic_previous.png) \
        $$quote($$BASEDIR/assets/icons/ic_properties.png) \
        $$quote($$BASEDIR/assets/icons/ic_reload.png) \
        $$quote($$BASEDIR/assets/icons/ic_rename.png) \
        $$quote($$BASEDIR/assets/icons/ic_reply.png) \
        $$quote($$BASEDIR/assets/icons/ic_reply_all.png) \
        $$quote($$BASEDIR/assets/icons/ic_resume.png) \
        $$quote($$BASEDIR/assets/icons/ic_save.png) \
        $$quote($$BASEDIR/assets/icons/ic_save_as.png) \
        $$quote($$BASEDIR/assets/icons/ic_scan_barcode.png) \
        $$quote($$BASEDIR/assets/icons/ic_search.png) \
        $$quote($$BASEDIR/assets/icons/ic_select.png) \
        $$quote($$BASEDIR/assets/icons/ic_select_all.png) \
        $$quote($$BASEDIR/assets/icons/ic_select_more.png) \
        $$quote($$BASEDIR/assets/icons/ic_select_text.png) \
        $$quote($$BASEDIR/assets/icons/ic_set_as_default.png) \
        $$quote($$BASEDIR/assets/icons/ic_settings.png) \
        $$quote($$BASEDIR/assets/icons/ic_share.png) \
        $$quote($$BASEDIR/assets/icons/ic_show_dialpad.png) \
        $$quote($$BASEDIR/assets/icons/ic_show_vkb.png) \
        $$quote($$BASEDIR/assets/icons/ic_sort.png) \
        $$quote($$BASEDIR/assets/icons/ic_speaker_dk.png) \
        $$quote($$BASEDIR/assets/icons/ic_speaker_mute.png) \
        $$quote($$BASEDIR/assets/icons/ic_stop.png) \
        $$quote($$BASEDIR/assets/icons/ic_textmessage_dk.png) \
        $$quote($$BASEDIR/assets/icons/ic_to_bottom.png) \
        $$quote($$BASEDIR/assets/icons/ic_to_top.png) \
        $$quote($$BASEDIR/assets/icons/ic_view_details_dk.png) \
        $$quote($$BASEDIR/assets/icons/ic_view_grid.png) \
        $$quote($$BASEDIR/assets/icons/ic_view_image.png) \
        $$quote($$BASEDIR/assets/icons/ic_view_list.png) \
        $$quote($$BASEDIR/assets/icons/ic_view_post.png) \
        $$quote($$BASEDIR/assets/icons/ic_zoom_in.png) \
        $$quote($$BASEDIR/assets/icons/ic_zoom_out.png) \
        $$quote($$BASEDIR/assets/images/M_720_1280.png) \
        $$quote($$BASEDIR/assets/images/M_720_720.png) \
        $$quote($$BASEDIR/assets/images/Moinlela_logo.png) \
        $$quote($$BASEDIR/assets/images/SplashMoinLela_1440_1440.png) \
        $$quote($$BASEDIR/assets/images/SplashMoinLela_720_1280.png) \
        $$quote($$BASEDIR/assets/images/background.png) \
        $$quote($$BASEDIR/assets/images/bingmaps.png) \
        $$quote($$BASEDIR/assets/images/clearpin.png) \
        $$quote($$BASEDIR/assets/images/googlemaps.png) \
        $$quote($$BASEDIR/assets/images/handle_inactive.png) \
        $$quote($$BASEDIR/assets/images/handle_pressed.png) \
        $$quote($$BASEDIR/assets/images/map.png) \
        $$quote($$BASEDIR/assets/images/moinlela.png) \
        $$quote($$BASEDIR/assets/images/on_map_pin.png) \
        $$quote($$BASEDIR/assets/images/openlayers.png) \
        $$quote($$BASEDIR/assets/images/pin.png) \
        $$quote($$BASEDIR/assets/images/slider_track.png) \
        $$quote($$BASEDIR/assets/images/star.png) \
        $$quote($$BASEDIR/assets/images/tiny_default.png) \
        $$quote($$BASEDIR/assets/itemDetails.qml) \
        $$quote($$BASEDIR/assets/itemPage.qml) \
        $$quote($$BASEDIR/assets/map.html) \
        $$quote($$BASEDIR/assets/menu.json) \
        $$quote($$BASEDIR/assets/moinlela.qml) \
        $$quote($$BASEDIR/assets/newItem.qml) \
        $$quote($$BASEDIR/assets/openlayers_map.js) \
        $$quote($$BASEDIR/assets/settings.qml) \
        $$quote($$BASEDIR/assets/style.css) \
        $$quote($$BASEDIR/assets/userRegistration.qml) \
        $$quote($$BASEDIR/assets/userSession.qml)
}

config_pri_source_group1 {
    SOURCES += \
        $$quote($$BASEDIR/src/MoinLelaRequest.cpp) \
        $$quote($$BASEDIR/src/SocialInvocation.cpp) \
        $$quote($$BASEDIR/src/StatusEventHandler.cpp) \
        $$quote($$BASEDIR/src/WebMaps.cpp) \
        $$quote($$BASEDIR/src/applicationui.cpp) \
        $$quote($$BASEDIR/src/appsettings.cpp) \
        $$quote($$BASEDIR/src/main.cpp)

    HEADERS += \
        $$quote($$BASEDIR/src/MoinLelaRequest.hpp) \
        $$quote($$BASEDIR/src/SocialInvocation.hpp) \
        $$quote($$BASEDIR/src/StatusEventHandler.h) \
        $$quote($$BASEDIR/src/WebMaps.hpp) \
        $$quote($$BASEDIR/src/applicationui.hpp) \
        $$quote($$BASEDIR/src/appsettings.h)
}

CONFIG += precompile_header

PRECOMPILED_HEADER = $$quote($$BASEDIR/precompiled.h)

lupdate_inclusion {
    SOURCES += \
        $$quote($$BASEDIR/../src/*.c) \
        $$quote($$BASEDIR/../src/*.c++) \
        $$quote($$BASEDIR/../src/*.cc) \
        $$quote($$BASEDIR/../src/*.cpp) \
        $$quote($$BASEDIR/../src/*.cxx) \
        $$quote($$BASEDIR/../assets/*.qml) \
        $$quote($$BASEDIR/../assets/*.js) \
        $$quote($$BASEDIR/../assets/*.qs) \
        $$quote($$BASEDIR/../assets/controls/*.qml) \
        $$quote($$BASEDIR/../assets/controls/*.js) \
        $$quote($$BASEDIR/../assets/controls/*.qs) \
        $$quote($$BASEDIR/../assets/icons/*.qml) \
        $$quote($$BASEDIR/../assets/icons/*.js) \
        $$quote($$BASEDIR/../assets/icons/*.qs) \
        $$quote($$BASEDIR/../assets/images/*.qml) \
        $$quote($$BASEDIR/../assets/images/*.js) \
        $$quote($$BASEDIR/../assets/images/*.qs)

    HEADERS += \
        $$quote($$BASEDIR/../src/*.h) \
        $$quote($$BASEDIR/../src/*.h++) \
        $$quote($$BASEDIR/../src/*.hh) \
        $$quote($$BASEDIR/../src/*.hpp) \
        $$quote($$BASEDIR/../src/*.hxx)
}

TRANSLATIONS = $$quote($${TARGET}.ts)
