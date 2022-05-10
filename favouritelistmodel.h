#ifndef FAVOURITELISTMODEL_H
#define FAVOURITELISTMODEL_H

#include <QAbstractListModel>

class FavouriteList;

class FavouriteListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(FavouriteList *list READ list WRITE setList)
    enum {
       LabelRole, DescriptionRole, IconRole, PathRole
    };
public:
    explicit FavouriteListModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    FavouriteList *list() const;
    void setList(FavouriteList *list);
private:
    FavouriteList *mList;
};

#endif // FAVOURITELISTMODEL_H
