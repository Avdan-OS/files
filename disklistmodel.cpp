#include "disklistmodel.h"
#include "disklist.h"
DiskListModel::DiskListModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int DiskListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    return mList->item().size();
}

QVariant DiskListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const DiskItem item = mList->item().at(index.row());
    switch(role){
    case LabelRole:
        return QVariant(item.label);
    case DescriptionRole:
        return QVariant(item.description);
    case IconRole:
        return QVariant(item.icon);
    case PathRole:
        return QVariant(item.path);
    }

    return QVariant();
}

bool DiskListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;
    DiskItem item = mList->item().at(index.row());
    switch(role){
    case LabelRole:
        item.label = value.toString();
        break;
    case DescriptionRole:
        item.description = value.toString();
        break;
    case IconRole:
        item.icon = value.toString();
        break;
    case PathRole:
        item.path = value.toString();
        break;
    }
    if (mList->setItemAt(index.row(),item)) {
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags DiskListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QHash<int, QByteArray> DiskListModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[LabelRole] = "label";
    names[IconRole] = "icon";
    names[DescriptionRole] = "description";
    names[PathRole] = "path";
    return names;
}

DiskList *DiskListModel::list() const
{
    return mList;
}

void DiskListModel::setList(DiskList *list)
{
    beginResetModel();

    if(mList)
        mList->disconnect(this);

    mList = list;

    if(mList){
        connect(mList, &DiskList::preItemAppended, this, [=](){
            const int index = mList->item().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &DiskList::postItemAppended, this, [=](){
            endInsertRows();
        });
        connect(mList, &DiskList::preItemRemoved, this, [=](int index){
            beginRemoveRows(QModelIndex(), true, true);
        });
        connect(mList, &DiskList::postItemRemoved, this, [=](){
            endRemoveRows();
        });
    };

    endResetModel();
}
