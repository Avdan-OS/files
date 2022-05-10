#ifndef FAVOURITELIST_H
#define FAVOURITELIST_H

#include <QObject>
#include <QVector>

struct FavouriteItem{
    QString label;
    QString description;
    QString icon;
    QString path;
};

class FavouriteList : public QObject
{
    Q_OBJECT
public:
    explicit FavouriteList(QObject *parent = nullptr);

    QVector<FavouriteItem> item() const;

    bool setItemAt(int index, const FavouriteItem &item);
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();
public slots:
    void appendItem();
    void removeCompletedItem();
private:
    QVector<FavouriteItem> mItems;

};

#endif // FAVOURITELIST_H
