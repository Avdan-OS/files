#ifndef PINNEDLISTMODEL_H
#define PINNEDLISTMODEL_H

#include <QAbstractListModel>

class PinnedList;

class PinnedListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(PinnedList *list READ list WRITE setList)
    enum {
       LabelRole, DescriptionRole, IconRole, PathRole
    };
public:
    explicit PinnedListModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    PinnedList *list() const;
    void setList(PinnedList *list);
private:
    PinnedList *mList;
};

#endif // FAVOURITELISTMODEL_H
