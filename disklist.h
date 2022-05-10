#ifndef DISKLIST_H
#define DISKLIST_H

#include <QObject>
#include <QVector>

struct DiskItem{
    QString label;
    QString description;
    QString icon;
    QString path;
};

class DiskList : public QObject
{
    Q_OBJECT
public:
    explicit DiskList(QObject *parent = nullptr);

    QVector<DiskItem> item() const;

    bool setItemAt(int index, const DiskItem &item);
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();
public slots:
    void appendItem();
    void removeCompletedItem();
private:
    QVector<DiskItem> mItems;

};

#endif // FAVOURITELIST_H
