#include "recentsmodel.h"
#include "recents.h"
RecentsModel::RecentsModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int RecentsModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    return mList->item().size();
}

QVariant RecentsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const RecentItem item = mList->item().at(index.row());
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

bool RecentsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;
    RecentItem item = mList->item().at(index.row());
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

Qt::ItemFlags RecentsModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QHash<int, QByteArray> RecentsModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[LabelRole] = "label";
    names[IconRole] = "icon";
    names[DescriptionRole] = "description";
    names[PathRole] = "path";
    return names;
}

RecentList *RecentsModel::list() const
{
    return mList;
}

void RecentsModel::setList(RecentList *list)
{
    beginResetModel();

    if(mList)
        mList->disconnect(this);

    mList = list;

    if(mList){
        connect(mList, &RecentList::preItemAppended, this, [=](){
            const int index = mList->item().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &RecentList::postItemAppended, this, [=](){
            endInsertRows();
        });
        connect(mList, &RecentList::preItemRemoved, this, [=](int index){
            beginRemoveRows(QModelIndex(), true, true);
        });
        connect(mList, &RecentList::postItemRemoved, this, [=](){
            endRemoveRows();
        });
    };

    endResetModel();
}
