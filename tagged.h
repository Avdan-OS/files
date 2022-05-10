#ifndef TAGGEDLIST_H
#define TAGGEDLIST_H

#include <QObject>
#include <QVector>

struct TaggedItem{
    QString label;
    QString description;
    QString icon;
    QString path;
};

class TaggedList : public QObject
{
    Q_OBJECT
public:
    explicit TaggedList(QObject *parent = nullptr);

    QVector<TaggedItem> item() const;

    bool setItemAt(int index, const TaggedItem &item);
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();
public slots:
    void appendItem();
    void removeCompletedItem();
private:
    QVector<TaggedItem> mItems;

};

#endif // FAVOURITELIST_H
