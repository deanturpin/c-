#include <iostream>
#include <regex>

#include "pxl.h"

int main()
{
    using namespace std;

    // Get the whole file
    stringstream raw;
    raw << cin.rdbuf();
    string gpx = raw.str();

    // Create a bitmap
    // pxl::pxl8 p;
    smatch match;

    vector<pair<double, double> > points;
    vector<double> lats, lons;

    while (regex_search(gpx, match, regex("lat=\"([0-9.-]+)\" lon=\"([0-9.-]+)\""))) {
        stringstream latlon;
        latlon << match[1] << " " << match[2];

        double lat, lon;
        latlon >> lat;
        latlon >> lon;

        points.push_back(make_pair(lat, lon));
        lats.push_back(lat);
        lons.push_back(lon);

        // p.set(lon / 5, lat / 10);

        // Move on to the remainder
        gpx = match.suffix().str();
    }

    cout << "Points " << points.size() << endl;

    // Calculate range
    const auto lat_min = *min_element(lats.cbegin(), lats.cend());
    const auto lat_max = *max_element(lats.cbegin(), lats.cend());
    cout << "Min lat " << lat_min << endl;
    cout << "Max lat " << lat_max << endl;

    const auto lon_min = *min_element(lons.cbegin(), lons.cend());
    const auto lon_max = *max_element(lons.cbegin(), lons.cend());
    cout << "Min lon " << lon_min << endl;
    cout << "Max lon " << lon_max << endl;

    // cout << "Max " << max << endl;
    // cout << "Max " << *minmax.second << endl;

    // p.render();

    return 0;
}
