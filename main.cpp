#include "backendclass.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickView>
#include <QIcon>
#include <QQmlContext>
#include "favouritelist.h"
#include "favouritelistmodel.h"
#include "disklist.h"
#include "disklistmodel.h"
#include "recents.h"
#include "recentsmodel.h"
#include "tagged.h"
#include "taggedmodel.h"
#include "pinned.h"
#include "pinnedmodel.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    qmlRegisterType<BackendClass>("Backend",1,0,"Backend");
    qmlRegisterType<FavouriteListModel>("FavouriteListModel",1,0,"FavouriteListModel");
    qmlRegisterUncreatableType<FavouriteList>("Favourite",1,0,"FavouriteList",
                                              QStringLiteral("FavouriteList should not be created in QML"));
    qmlRegisterType<DiskListModel>("DiskListModel",1,0,"DiskListModel");
    qmlRegisterUncreatableType<DiskList>("Disk",1,0,"DiskList",
                                              QStringLiteral("DiskList should not be created in QML"));
    qmlRegisterType<RecentsModel>("RecentListModel",1,0,"RecentListModel");
    qmlRegisterUncreatableType<RecentList>("Recent",1,0,"RecentList",
                                              QStringLiteral("RecentList should not be created in QML"));
    qmlRegisterType<TaggedListModel>("TaggedListModel",1,0,"TaggedListModel");
    qmlRegisterUncreatableType<TaggedList>("Tagged",1,0,"TaggedList",
                                              QStringLiteral("TaggedList should not be created in QML"));
    qmlRegisterType<PinnedListModel>("PinnedListModel",1,0,"PinnedListModel");
    qmlRegisterUncreatableType<PinnedList>("Pinned",1,0,"PinnedList",
                                              QStringLiteral("PinnedList should not be created in QML"));
    FavouriteList favlist;
    DiskList diskList;
    PinnedList pinnedList;
    RecentList recentList;
    TaggedList tagList;

    QIcon::setThemeName("Tela-blue-dark");
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("favlist"),&favlist);
    engine.rootContext()->setContextProperty(QStringLiteral("disklist"),&diskList);
    engine.rootContext()->setContextProperty(QStringLiteral("pinnedlist"),&pinnedList);
    engine.rootContext()->setContextProperty(QStringLiteral("recentlist"),&recentList);
    engine.rootContext()->setContextProperty(QStringLiteral("taglist"),&tagList);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
