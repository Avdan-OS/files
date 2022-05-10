#ifndef DISKLISTMODEL_H
#define DISKLISTMODEL_H

#include <QAbstractListModel>

class DiskList;

class DiskListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(DiskList *list READ list WRITE setList)
    enum {
       LabelRole, DescriptionRole, IconRole, PathRole
    };
public:
    explicit DiskListModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    DiskList *list() const;
    void setList(DiskList *list);
private:
    DiskList *mList;
};

#endif // FAVOURITELISTMODEL_H
