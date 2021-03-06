#ifndef MAPLAYERSDATA_H
#define MAPLAYERSDATA_H
#include <SkBitmap.h>

#include <QImage>
#include <OsmAndCore.h>
#include <OsmAndApplication.h>
#include <RouteSegment.h>



class MapLayersData: public QObject
{
    Q_OBJECT
private:
    std::shared_ptr<OsmAnd::OsmAndApplication> app;
    QList< OsmAnd::PointF > route;
    QList< QString > routeText;
    QImage* lastRenderedImage;
    OsmAnd::AreaI lastRenderedBox;
signals:
    void mapNeedsToRefresh(QString message);
public:
    explicit MapLayersData(QObject *parent = 0);

    void setRoute(QList< std::shared_ptr<OsmAnd::RouteSegment> >& r);
    QImage* getRenderedImage(OsmAnd::AreaI* bbox) ;
    void setRenderedImage(SkBitmap& bmp, OsmAnd::AreaI bbox);


    Q_INVOKABLE int getMapZoom();
    Q_INVOKABLE double getMapLatitude();
    Q_INVOKABLE double getMapLongitude();
    Q_INVOKABLE void setMapLatLonZoom(double,double,int);

    Q_INVOKABLE int getRoutePointLength() { return route.size();}
    Q_INVOKABLE float getRoutePointLat(int i) {return route[i].y; }
    Q_INVOKABLE float getRoutePointLon(int i) {return route[i].x; }
    Q_INVOKABLE QString getRoutePointText(int i) {return routeText[i]; }


    Q_INVOKABLE bool isTargetPresent();
    Q_INVOKABLE double getTargetLatitude();
    Q_INVOKABLE double getTargetLongitude();
    Q_INVOKABLE void setTargetLatLon(double lat,double lon);

    Q_INVOKABLE bool isStartPresent();
    Q_INVOKABLE double getStartLatitude();
    Q_INVOKABLE double getStartLongitude();
    Q_INVOKABLE void setStartLatLon(double lat,double lon);
};

#endif // MAPLAYERSDATA_H
