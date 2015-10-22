/*
 * StatusEventHandler.cpp
 *
 *  Created on: Dec 17, 2014
 *      Author: mchepesky
 */

#include "StatusEventHandler.h"

#include <bps/bps.h>
#include <bps/netstatus.h>
#include <bps/locale.h>
#include <bps/geolocation.h>
#include <bps/navigator.h>
#include <QDebug>

StatusEventHandler::StatusEventHandler()
{
    subscribe(netstatus_get_domain());
    subscribe(locale_get_domain());
    subscribe(geolocation_get_domain());

    bps_initialize();

    netstatus_request_events(0);
    locale_request_events(0);
    geolocation_request_events(0);
    geolocation_set_period(1);
}

StatusEventHandler::~StatusEventHandler()
{
    bps_shutdown();
}

void StatusEventHandler::event(bps_event_t *event) {
    bool status = false;
    const char* language = "";
    const char* country = "";
    const char* locale = "";
    const char* interface = "";
    const char* type = "none";
    double latitude = 0;
    double longitude= 0;

    if (bps_event_get_domain(event) == geolocation_get_domain()) {
           if(event == NULL || bps_event_get_code(event) != GEOLOCATION_INFO) {
               qDebug() << "NO INFORMATION PROVIDED";
               return;
           }
               latitude = geolocation_event_get_latitude(event);
               longitude = geolocation_event_get_longitude(event);
               double accuracy = geolocation_event_get_accuracy(event);

               double altitude = geolocation_event_get_altitude(event);
               bool altitude_valid =
                          geolocation_event_is_altitude_valid(event);

               double altitude_accuracy =
                           geolocation_event_get_altitude_accuracy(event);
               bool altitude_accuracy_valid =
                           geolocation_event_is_altitude_accuracy_valid(event);

               double heading = geolocation_event_get_heading(event);
               bool heading_valid =
                           geolocation_event_is_heading_valid(event);

               double speed = geolocation_event_get_speed(event);
               bool speed_valid = geolocation_event_is_speed_valid(event);

               double num_satellites =
                           geolocation_event_get_num_satellites_used(event);
               bool num_satellites_valid =
                           geolocation_event_is_num_satellites_valid(event);

               emit geolocationUpdated(latitude,longitude);
       }
    if (bps_event_get_domain(event) == netstatus_get_domain()) {
        if (NETSTATUS_INFO == bps_event_get_code(event)) {
            netstatus_info_t *info = netstatus_event_get_info(event);
            if (info)
            {
                status = netstatus_info_get_availability(info);
                interface = netstatus_info_get_default_interface(info);

                netstatus_interface_details_t *details;

                int success = netstatus_get_interface_details(interface, &details);
                if (success == BPS_SUCCESS) {
                    switch (netstatus_interface_get_type(details)) {

                    case NETSTATUS_INTERFACE_TYPE_UNKNOWN:
                        type = "Unknown";
                        break;

                    case NETSTATUS_INTERFACE_TYPE_WIRED:
                        type = "Wired";
                        break;

                    case NETSTATUS_INTERFACE_TYPE_WIFI:
                        type = "Wi-Fi";
                        break;

                    case NETSTATUS_INTERFACE_TYPE_BLUETOOTH_DUN:
                        type = "Bluetooth";
                        break;

                    case NETSTATUS_INTERFACE_TYPE_USB:
                        type = "USB";
                        break;

                    case NETSTATUS_INTERFACE_TYPE_VPN:
                        type = "VPN";
                        break;

                    case NETSTATUS_INTERFACE_TYPE_BB:
                        type = "BB";
                        break;

                    case NETSTATUS_INTERFACE_TYPE_CELLULAR:
                        type = "Cellular";
                        break;

                    case NETSTATUS_INTERFACE_TYPE_P2P:
                        type = "P2P";
                        break;
                    }
                }

                netstatus_free_interface_details(&details);
                emit networkStatusUpdated(status, type);
            }
        }
    } else if (bps_event_get_domain(event) == locale_get_domain()) {
        if (LOCALE_INFO == bps_event_get_code(event)) {
            language = locale_event_get_language(event);
            country = locale_event_get_country(event);
            locale = locale_event_get_locale(event);
            emit localeUpdated(language, country, locale);
        }
    }
}
