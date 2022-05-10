#ifndef TAGGEDLISTMODEL_H
#define TAGGEDLISTMODEL_H

#include <QAbstractListModel>

class TaggedList;

class TaggedListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(TaggedList *list READ list WRITE setList)
    enum {
       LabelRole, DescriptionRole, IconRole, PathRole
    };
public:
    explicit TaggedListModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    TaggedList *list() const;
    void setList(TaggedList *list);
private:
    TaggedList *mList;
};

#endif // FAVOURITELISTMODEL_H
