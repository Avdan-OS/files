#ifndef RECENTS_H
#define RECENTS_H

#include <QObject>
#include <QVector>

struct RecentItem{
    QString label;
    QString description;
    QString icon;
    QString path;
};

class RecentList : public QObject
{
    Q_OBJECT
public:
    explicit RecentList(QObject *parent = nullptr);

    QVector<RecentItem> item() const;

    bool setItemAt(int index, const RecentItem &item);
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();
public slots:
    void appendItem();
    void removeCompletedItem();
private:
    QVector<RecentItem> mItems;

};

#endif // FAVOURITELIST_H
