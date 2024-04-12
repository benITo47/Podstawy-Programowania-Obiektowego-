#ifndef MAPPOINT_H
#define MAPPOINT_H
#pragma once 

class MapPoint
{
  public: 
    double Latitude; 
    double Longtitude; 


    void set_latitude(double latitude);
    void set_longitude(double longitude);
    void print();
    void set_coordinates(double latitude, double longitude);
   
    MapPoint closest(MapPoint first, MapPoint second) ;
    MapPoint half_way_to(MapPoint point);
};


#endif