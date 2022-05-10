#ifndef PINNEDLIST_H
#define PINNEDLIST_H

#include <QObject>
#include <QVector>

struct PinnedItem{
    QString label;
    QString description;
    QString icon;
    QString path;
};

class PinnedList : public QObject
{
    Q_OBJECT
public:
    explicit PinnedList(QObject *parent = nullptr);

    QVector<PinnedItem> item() const;

    bool setItemAt(int index, const PinnedItem &item);
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();
public slots:
    void appendItem();
    void removeCompletedItem();
private:
    QVector<PinnedItem> mItems;

};

#endif // FAVOURITELIST_H
