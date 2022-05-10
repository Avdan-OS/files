#ifndef RECENTSMODEL_H
#define RECENTSMODEL_H

#include <QAbstractListModel>

class RecentList;

class RecentsModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(RecentList *list READ list WRITE setList)
    enum {
       LabelRole, DescriptionRole, IconRole, PathRole
    };
public:
    explicit RecentsModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    RecentList *list() const;
    void setList(RecentList *list);
private:
    RecentList *mList;
};

#endif // FAVOURITELISTMODEL_H
