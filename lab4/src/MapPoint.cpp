#include "MapPoint.h"
#include <iostream>
using namespace std;

void MapPoint::set_latitude(double latitude)
{
    Latitude = latitude;
}
void MapPoint::set_longitude(double longitude)
{
    Longtitude = longitude;
}
void MapPoint::print()
{
    cout << "Point (" << Latitude << ", " << Longtitude << " )" << endl;
}
void MapPoint::set_coordinates(double latitude, double longitude)
{
    set_latitude(latitude);
    set_longitude(longitude);
}

MapPoint MapPoint::closest(MapPoint first, MapPoint second)
{
    double x_1 = Latitude - first.Latitude;
    double y_1 = Longtitude - first.Longtitude;

    double x_2 = Latitude - second.Latitude;
    double y_2 = Longtitude - second.Longtitude;

    double distance_1 = sqrt(x_1 * x_1 + y_1 * y_1);
    double distance_2 = sqrt(x_2 * x_2 + y_2 * y_2);

    if (distance_1 < distance_2)
    {
        return first;
    }
    else
    {
        return second;
    }
}

MapPoint MapPoint::half_way_to(MapPoint point)
{
    double x = (Latitude + point.Latitude) / 2;
    double y = (Longtitude + point.Longtitude) / 2;

    MapPoint halfway;
    halfway.set_coordinates(x, y);
    return halfway;
}