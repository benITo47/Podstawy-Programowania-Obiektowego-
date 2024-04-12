#include "PointCloud.h"

int Point2D::DISPLAY_PRESITION = 1;

Point2D::Point2D()
{
    Point[0] = 0;
    Point[1] = 0;
}
Point2D::Point2D(std::array<double, 2> initial)
{
    for (int i = 0; i < 2; i++)
    {
        Point[i] = initial[i];
    }
}
Point2D::Point2D(double x)
{
    Point[0] = x;
    Point[1] = x;
}

void Point2D::displayCoordinates() const
{
    std::cout << std::fixed << std::setprecision(DISPLAY_PRESITION) << "Wspolrzedne: (" << Point[0] << ", " << Point[1] << ")\n";
}

double Point2D::PointSum()
{
    return Point[0] + Point[1];
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

VPointCloud2D::VPointCloud2D(){}


VPointCloud2D::VPointCloud2D(const VPointCloud2D &other)
{
    for(auto& elem: other.Cloud)
    {
        Point2D* nowyPunkt = new Point2D(elem->Point);
        Cloud.push_back(nowyPunkt);
    }
    
}
VPointCloud2D::VPointCloud2D(VPointCloud2D &&other) noexcept
{
    Cloud = std::move(other.Cloud);
    other.Cloud.clear();
    
}

void VPointCloud2D::addPoint(Point2D *point)
{
    Cloud.push_back(point);
}
void VPointCloud2D::addPoint(std::array<double, 2> initialP)
{
    Point2D* newOne = new Point2D(initialP);
    Cloud.push_back(newOne); 
}

void VPointCloud2D::displayPoints()
{
    for (Point2D *elem : Cloud)
    {
        elem->displayCoordinates();
    }
}

Point2D *VPointCloud2D::getCopyPoint(int index)
{
    if(index < 0 || index >= Cloud.size())
    {
        return nullptr;
    }
    return Cloud[index];
}

void VPointCloud2D::add(VPointCloud2D otherCloud)
{
    for (Point2D *elem : otherCloud.Cloud)
    {
        addPoint(elem);
    }
}

void VPointCloud2D::displaySumOfPoints()
{
    double sum = 0;
    for (Point2D *elem : Cloud)
    {
        sum += elem->PointSum();
    }

    std::cout << std::fixed << std::setprecision(0) << "Suma punktow: " << sum << std::endl;
}

 VPointCloud2D::~VPointCloud2D()
    {
        for(auto& elem: Cloud)
        {
            if(elem != nullptr)
            {
                delete elem; 
                elem = nullptr;
            }
        }
        Cloud.clear();
    }